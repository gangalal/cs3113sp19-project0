#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char** argv)
{
        if (strcmp(argv[1], "-h") == 0)
        {
        printf("usage: ouseq [M] N\n");
        exit(-1);
        }

        if ((argc == 2) )
        {
        int num = atoi(argv[1]);
        for(int i =0; i<=num; i++)
        {
                printf("%d\n", i);
        }
        }

         if ((argc == 3) )
        {
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        if(num1<num2)
        {
        for (int i = num1; i<=num2; i++)
        {
                printf("%d\n", i);
        }
        }
        else
        {
                for (int i = num1; i>=num2; i--)//prints in reverse order
        {
                printf("%d\n", i);
        }

        }
        }



return EXIT_SUCCESS;
}

