#include <netdb.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 500

int main(int argc, char *argv[]) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int sfd = -1;
  ssize_t nread = -1;
  char buf[BUF_SIZE];
  bool connected = false;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Obtain address(es) matching host/port. */

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
  hints.ai_flags = 0;
  hints.ai_protocol = 0; /* Any protocol */

  int s = getaddrinfo(argv[1], argv[2], &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  /* getaddrinfo() returns a list of address structures.
     Try each address until we successfully connect(2).
     If socket(2) (or connect(2)) fails, we (close the socket
     and) try the next address. */

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1)
      continue;

    if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1) {
      connected = true;
      break;
    }

    close(sfd);
  }

  freeaddrinfo(result);
  if (rp == NULL || !connected) {
    fprintf(stderr, "Could not connect\n");
    exit(EXIT_FAILURE);
  }

  /* Send remaining command-line arguments as separate
     datagrams, and read responses from server. */

  for (int j = 3; j < argc; j++) {
    size_t len = strlen(argv[j]) + 1;
    printf("Send command %s\n", argv[j]);

    if (len > BUF_SIZE) {
      fprintf(stderr, "Ignoring long message in argument %d\n", j);
      continue;
    }

    if ((size_t)write(sfd, argv[j], len) != len) {
      fprintf(stderr, "partial/failed write\n");
      exit(EXIT_FAILURE);
    }

    if ((nread = read(sfd, buf, BUF_SIZE)) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    printf("Received %zd bytes: %s\n", nread, buf);
  }

  exit(EXIT_SUCCESS);
}
