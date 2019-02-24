#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_READ 250
int main( int argc, char* argv[])
{

if (argc == 2 && strcmp(argv[1], "-h") == 0)
{
        printf("usage: oucat <files>\n");
        exit(-1);
}


char buff[MAX_READ];
ssize_t num;
if (argc == 1)
{
while((num = read(STDIN_FILENO, buff, MAX_READ))>0)//reads and writes file from stdin
{
        ssize_t num1;
        num1 = write(STDOUT_FILENO, buff, num);

        if (num != num1)
        {
                  fprintf(stderr,"can't read file\n");
	return EXIT_FAILURE;
        }
}

if (num < 0 )
{
          fprintf(stderr,"can't read file\n");
	return EXIT_FAILURE;
}
}




if (argc == 2)
{
int fd = open(argv[1], O_RDONLY);
if (fd == -1)//returns failure if the file is not readable
{
fprintf(stderr,"error read only\n");
return 0;
}
char buffer[MAX_READ+1];
ssize_t numread;
numread  = (read(fd, buffer, MAX_READ));
 if (numread == -1)
 {
  fprintf(stderr,"can't read file\n");
return 0;
  }
buffer[numread] = '\0';
write(STDOUT_FILENO, buffer, numread+1);
close(fd);
}




if (argc == 3)
{
int fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr,"error read only\n");
return 0;
}
char buffer[MAX_READ+1];
ssize_t numread;
numread  = (read(fd, buffer, MAX_READ));
 if (numread == -1)
 {
  fprintf(stderr,"can't read file\n");
return 0;
  }
buffer[numread] = '\0';
write(STDOUT_FILENO, buffer, numread+1);
close(fd);


int fd1 = open(argv[2], O_RDONLY);
if (fd1 == -1)
{
fprintf(stderr,"error read only\n");
return 0;
}
char buffer1[MAX_READ+1];
ssize_t numread1;
numread1  = (read(fd1, buffer1, MAX_READ));
 if (numread1 == -1)
 {
  fprintf(stderr,"can't read file\n");
return 0;
  }
buffer[numread1] = '\0';
write(STDOUT_FILENO, buffer1, numread1+1);
close(fd1);

}
return EXIT_SUCCESS;
}

