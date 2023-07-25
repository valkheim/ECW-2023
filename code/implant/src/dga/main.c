#include "../implant/implant.h"

int main()
{
  generate_domain();
  printf("%.*s.%s",(int)sizeof(g_domain), g_domain, CNC_TLD);
}
