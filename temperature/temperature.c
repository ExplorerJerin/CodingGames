// 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int make_positive(int n)
{
    if (n < 0)
        return n * -1;
    else 
        return n;
}

int find_lowest(int t, int i)
{
    static int small;
    static int real;
    int n = make_positive(t);

    if(i == 0)
    {
        small = n;
        real = t;
    }
    else
    {
        if (small > n)
        {
            small = n;
            real = t;
        }
        if(small == n && t > 0)
        {
           real = t;
        }
    }
    return (real);
}

int main()
{
    // the number of temperatures to analyse
    int n;
    int smallest;

    scanf("%d", &n);

    //printf("%d\n",n);


    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
       int t;
       scanf("%d", &t);
       smallest = find_lowest(t, i);
       printf("%d ",t);
       printf("%d,",smallest);
    }
    //printf("%d",smallest);
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n")    

    return 0;
}

