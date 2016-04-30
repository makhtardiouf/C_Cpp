/*
$Id: listdir_test.c 5 2007-03-31 15:04:06Z Makhtar $
List the content of a directory
*/

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

/*   char* entries[100]; */

int listdir(const char *directory, const char *output_file) {
  DIR *dp;
  FILE *fp;
  struct dirent *ep;

  dp = opendir(directory);
  if (dp != NULL) {
    if (output_file == NULL)
      while ((ep = readdir(dp)))
        fprintf(stdout, "%s\n", ep->d_name);
    else {
      fp = fopen(output_file, "w");
      if (fp != NULL) {
        while ((ep = readdir(dp)))
          fprintf(fp, "%s\n", ep->d_name);

        fclose(fp);
      }
    }
    closedir(dp);
  } else {
    fprintf(stderr, "Couldn't open the directory %s, %s\n", directory,
            strerror(errno));
    return -1;
  }
  return 0;
}

/*
int listdir_fly(const char* directory)
{
    int i = 0;
  DIR *dp;
  struct dirent *ep;

  dp = opendir(directory);
  if(dp != NULL)
  {
    while( (ep = readdir(dp)) )
      {
       entries[i] =  ep->d_name;
       ++i;
      }
    entries[i] = NULL;
      closedir(dp);
  }
  else
  {
    fprintf(stderr, "Couldn't open the directory %s, %s\n", directory,
strerror(errno));
    return -1;
  }
  return 0;
}
*/

int main(int argc, char **argv) {
  listdir(argv[1], argv[2]);
  return 0;
}
