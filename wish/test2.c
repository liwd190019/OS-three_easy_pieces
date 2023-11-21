/*
Write a program that reads and prints the contents of a directory, similar to the ls command. This program should:

Accept a directory name as input
Loop repeatedly, reading one directory entry at a time
Print out the inode number and name of each file in the directory.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>

int get_inode(char *filename){
  int fd, inode;
  fd = open(filename, O_RDONLY);

  struct stat file_stat;
  int ret;
  ret = fstat(fd, &file_stat);
  if(ret < 0){
    exit(1);
  }
  inode = file_stat.st_ino;
  return inode;
}

int main(int argc, char* argv[])
{
    // int fd, inode;
    char diradd[256];
    scanf("%s", diradd);
    DIR *d = opendir(diradd);
    if(d == NULL) exit(-1);
    struct dirent *dir;
    while ((dir = readdir(d)) != NULL){
      printf("%d %s\n", get_inode(dir->d_name), dir->d_name);
    }
    closedir(d);

    return 0;
}

// another way to implement this problem
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(argv[1]);
    while((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", argv[1], myfile->d_name);
        stat(buf, &mystat);
        printf("%zu",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
}

*/