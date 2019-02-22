#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv)
{
if( argc == 1)
{
        printf("\n");
        return EXIT_SUCCESS;
}
for(int i = 1; i<argc; i++)
{
if(i<argc - 1)
{
printf("%s ", argv[i]);
}
if( i  == argc - 1)
{
        printf("%s", argv[i]);
        printf("\n");
        return EXIT_SUCCESS;
}

}
return EXIT_SUCCESS;
} 
