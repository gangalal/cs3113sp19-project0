#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_READ 20
int main( int argc, char** argv)
{
        FILE* fd; 
        char* oneLine = NULL;
        int line = 0;
        int counter;
        char buff[MAX_READ];
        ssize_t num;
        int charCounter = 0;
	int spaceCounter = 0;
if ((argc ==2 ) && (strcmp(argv[1], "-h") == 0)) 
{
printf("usage: ouhead [-n N] <file>\n");
        exit(-1);
}
if (argc == 3)
{
while((num = read(STDIN_FILENO, buff, MAX_READ))>atoi(argv[2]))
{
        ssize_t num1;
        num1 = write(STDOUT_FILENO, buff, num);
        if (num != num1)
        {   
                  fprintf(stderr,"can't read file\n");
        }   
}
if (argc == 3)
{
while((num = read(STDIN_FILENO, buff, MAX_READ))>atoi(argv[2]))
{
        ssize_t num1;
        num1 = write(STDOUT_FILENO, buff, num);
        if (num != num1)
        {   
                  fprintf(stderr,"can't read file\n");
        }   
}
if (num < 0 )
{
          fprintf(stderr,"can't read file\n");
}
return EXIT_SUCCESS;
}
if (argc == 2)
{
 fd = fopen(argv[1], "r");
  if (fd == NULL)
 {
  fprintf(stderr,"error read only\n");
 }
character = getc(fd);
 while(character != EOF)
  {
 if (character == '\n')
 {
 charCounter = charCounter + 1;
 }
 if (character == ' ')
 {
 spaceCounter = spaceCounter + 1;
 }
 character = getc(fd);
  }
 fclose(fd);







return EXIT_SUCCESS;
}

if (argc == 4)
{
fd = fopen(argv[3], "r");
  if (fd == NULL)
 {
  fprintf(stderr,"error read only\n");
 }
character2 = getc(fd);
 while(character2 != EOF)
  {
 if (character2 == '\n')
 {
 charCounter2 = charCounter2 + 1;
 }
 character2 = getc(fd);
  }
 fclose(fd);
fd = fopen(argv[3], "r");
if (fd == NULL)
{
fprintf(stderr,"error read only\n");
}
while( getline(&oneLine, &line, fd) != -1)
{
        counter++;
        if (counter >  charCounter2 - atoi(argv[2]) )
        {
          printf("%s", oneLine);
        }
}
fclose(fd);
return EXIT_SUCCESS;
}
return EXIT_SUCCESS;
}

