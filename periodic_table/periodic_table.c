#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void	ft_swap(char **first, char **last)
{
	char	*temp;

	temp = *first;
	*first = *last;
	*last = temp; 
}

int 	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char **ft_sort(char **arr)
{
	char **tmp;
	
	arr++;
	tmp = arr;
	
	while(*arr)
	{
		if(*(arr + 1) && ft_strcmp(*(arr),*(arr + 1) ) > 0)
		{
			ft_swap(arr,arr + 1);
			arr = tmp;
			continue;
		}
		arr++;
	}
	return tmp;
}



int main(int argc, char **argv)
{

    //char word[31];
    //scanf("%[^\n]", word);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    char **tmp = ft_sort(argv);
    while(*tmp)
    {
	    printf("%s ",*(tmp));
	    tmp++;
    }
    //printf("spellings\n");

    return 0;
}
