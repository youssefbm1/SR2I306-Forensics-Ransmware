#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
      int fd;
      struct dirent *d;
      DIR *rep;  
      rep=opendir(argc > 1 ? argv[1] : ".");
      printf("  inode#    file type    d_name\n");
      for ( ; ; ) {
          d = readdir(rep);
          if (d == NULL) break;
          printf("%8ld  ", d->d_ino);
          printf("  %-10s ", (d->d_type == DT_REG) ?  "regular" :
                             (d->d_type == DT_DIR) ?  "directory" :
                             (d->d_type == DT_FIFO) ? "FIFO" :
                             (d->d_type == DT_SOCK) ? "socket" :
                             (d->d_type == DT_LNK) ?  "symlink" :
                             (d->d_type == DT_BLK) ?  "block dev" :
                             (d->d_type == DT_CHR) ?  "char dev" : "???");
           printf("  %s\n", d->d_name);
      }
      closedir(rep);
      exit(EXIT_SUCCESS);
}
