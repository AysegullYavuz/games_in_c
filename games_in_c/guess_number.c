#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int num = rand() % 100;
    int n, count = 1;
    
    do
    {
        printf("Enter you number\n");
        scanf("%d", &n);

        if (n > num)
        {
            printf("Enter smaller number!!!!\n");
        }
        else if (n < num)
        {
            printf("Enter greater number!!!!\n");
        }
        else
            printf("You got right %d in %d attempts!!!!\n", num, count);
        count++;
        
    } while (n != num);
}
