#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_READ 120
int main( int argc, char** argv)
{
        FILE* fd; 
        char* oneLine = NULL;
        int line = 0;
        int counter = 0;
        char buff[MAX_READ];
        ssize_t num;
        int charCounter = 0;
        char character;
         int charCounter2 = 0;
        char character2;
        char filep[50];

if ((argc ==2 ) && (strcmp(argv[1], "-h") == 0)) 
{
printf("usage: outail [-n N] <file>\n");
        exit(-1);
}
if (argc == 3)
{
  num = read(STDIN_FILENO, buff, MAX_READ);
        if (num == -1) 
{
fprintf(stderr,"error read only\n");
        return EXIT_FAILURE;
}
buff[num] = '\0';
int templine = 0;  
int tempCount = 0;
while (buff[tempCount] != '\0') //this loops finds the number of line in a file
{
        if (buff[tempCount] =='\n')
            {   
        templine++; 
        }   
tempCount++;
}
while (buff[counter] != '\0') //this loop prints the line to be printed 
{
    
        if (buff[counter] =='\n')
                        {   
                        charCounter++;
                        }
     counter++;	
	if(charCounter >= templine - atoi(argv[2]))
{
                printf("%c", buff[counter]);
        }
}
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
 character = getc(fd);
  }
 fclose(fd);
fd = fopen(argv[1], "r");
if (fd == NULL)
{
fprintf(stderr,"error read only\n");
return 0;
}
while( getline(&oneLine, &line, fd) != -1)
{
        counter++;
        if (counter >  charCounter - 10  )//prints default number of lines
        {
          printf("%s", oneLine);
        }
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
return 0;
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

