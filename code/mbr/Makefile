RM=rm -rf
AS=nasm
ASFLAGS=-f bin
SRCDIR=code
OUTDIR=out
SRC=${wildcard ${SRCDIR}/*.S}
OBJ=${SRC:.S=.o}
MBR=mbr

all: $(MBR).bin
	@echo "[+] Build bootlocker"

%.o: %.S
	${AS} $< -f elf -o $@

%.bin: %.S
	${AS} $< -f bin -o $@

${MBR}.bin: ${SRCDIR}/${MBR}.bin
	xxd -i ${SRCDIR}/${MBR}.bin > ${MBR}.c

run: ${SRCDIR}/${MBR}.bin
	qemu-system-i386 -fda $<

clean:
	${RM} ${SRCDIR}/*.o
	${RM} ${SRCDIR}/*.bin

re: clean all
