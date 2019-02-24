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
        int counter = 0;
	int charCounter = 0;
        char buff[MAX_READ];
        ssize_t num;
        

//printf("%d ", argc);

if ((argc ==2 ) && (strcmp(argv[1], "-h") == 0))
{
printf("usage: ouhead [-n N] <file>\n");
        exit(-1);
}

if (argc == 3)
{

 num = read(STDIN_FILENO, buff, MAX_READ);
        if (num == -1)
{
        return EXIT_FAILURE; //returns if file can't read
}

buff[num] = '\0';
while (buff[counter] != '\0')
{
        if (charCounter == atoi(argv[2]))
        break;

        if (buff[counter] =='\n')
                        {
 
                        charCounter++; //counting lines
                        }
        if(charCounter < atoi(argv[2]));
        {
                printf("%c", buff[counter]);
        }

counter++;
}

return EXIT_SUCCESS; //returns success if file is readable

}




if (argc == 2)
{
fd = fopen(argv[1], "r");
if (fd == NULL)
{
fprintf(stderr,"error read only\n");
}


while( getline(&oneLine, &line, fd) != -1)
{
        counter++;
        if (counter > 10)
        {
                break;
        }
        printf("%s", oneLine); fflush(stdout);
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


while( getline(&oneLine, &line, fd) != -1)
{
        counter++;
        if (counter > atoi(argv[2]))
        {
                break;
        }
        printf("%s", oneLine);
}

fclose(fd);
return EXIT_SUCCESS;

}



return EXIT_SUCCESS;
}
                  
