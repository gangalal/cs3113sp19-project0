#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_READ 20

void fileReader(FILE* fd, char* oneLine, int line, int counter, char buff[MAX_READ], int* charCounter, char character, char** argv, int* byte);


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
	char character;
	int byte = 0;
if ((argc ==2 ) && (strcmp(argv[1], "-h") == 0)) 
{
printf("usage: ouwc [-l | -c] <file>");
        exit(-1);
}



if ((argc == 3)&& (strcmp(argv[1], "-l") == 0)&& (strcmp(argv[2], "-c") == 0))
{
   num = read(STDIN_FILENO, buff, MAX_READ);
        if (num == -1)
{
        return EXIT_FAILURE;
}

buff[num] = '\0';
while (buff[counter] != '\0')//this loop counts number of lines in a file
{
        if (buff[counter] =='\n')
                        {
                        charCounter++;
                        }
counter++;
}
printf("        %d        %ld\n", charCounter, num);//prints number of lines and bytes 
return EXIT_SUCCESS;

}



if (argc == 2)
{
fd = fopen(argv[1], "r");
  if (fd == NULL)
 {
  fprintf(stderr,"error read only\n");
return 0;
 }
character = getc(fd);
 while(character != EOF)
  {
 if (character == '\n')
 {
 charCounter = charCounter + 1;
 }
 byte = byte + sizeof(character);
 character = getc(fd);
  }
 fclose(fd);

printf("        %d        %d\n", charCounter, byte); 

}



if ((argc == 3) && (strcmp(argv[1], "-l") == 0))
{
fd = fopen(argv[2], "r");
  if (fd == NULL)
 {
  fprintf(stderr,"error read only\n");
return 0;
 }
character = getc(fd);
 while(character != EOF)
  {
 if (character == '\n')
 {
 charCounter = charCounter + 1;
 }
 byte = byte + sizeof(character);
 character = getc(fd);
  }
 fclose(fd);

printf("        %d\n", charCounter);
return EXIT_SUCCESS;

}


if ((argc == 3) && (strcmp(argv[1], "-c") == 0))
{
fd = fopen(argv[2], "r");
  if (fd == NULL)
 {
  fprintf(stderr,"error read only\n");
return 0;
 }
character = getc(fd);
 while(character != EOF)
  {
 if (character == '\n')
 {
 charCounter = charCounter + 1;
 }
 byte = byte + sizeof(character);
 character = getc(fd);
  }
 fclose(fd);

printf("        %d\n", byte);
return EXIT_SUCCESS;

}





if (argc == 4)
{
fd = fopen(argv[3], "r");
  if (fd == NULL)
 {
  fprintf(stderr,"error read only\n");
return 0;
 }
character = getc(fd);
 while(character != EOF)
  {
 if (character == '\n')
 {
 charCounter = charCounter + 1;
 }
 byte = byte + sizeof(character);
 character = getc(fd);
  }
 fclose(fd);

printf("        %d        %d\n", charCounter, byte); 
}

return EXIT_SUCCESS;
}


