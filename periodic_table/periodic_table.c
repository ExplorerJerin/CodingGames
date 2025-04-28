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

int str_len(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

char	*to_lower(char *s)
{
	char *tem;
	char *start;
	int count;

	count = str_len(s);
	tem = (char *)malloc((count + 1) * sizeof(char));
	start = tem;
	while(*s)
	{
		if ('A' <= *s && *s <= 'Z')
		{
			*tem = *s + 32;
		}
		else
		{
			*tem = *s;
		}
		s++;
		tem++;
	}
	*tem = '\0';
	return start;
}

char	make_lower(char a)
{
	if ('A' <= a && a <= 'Z')
	{
		return a + 32;
	}
	else
	{
		return a;
	}

}

int str_cmp(char *word,char *element)
{
	int count;
	int match;
	char *tmp;

	count = 0;
	match = 0;

	count = str_len(element);
	while (*word && *element && make_lower(*word) == make_lower(*element))
	{
		word++;
		element++;
		match++;
	}
	if (match == count)
		return 0;
	else
		return 1;

}

char *str_cpy(char *str1)
{
	int count;
	char *tem;
	char *start;

	count = str_len(str1);
	tem = (char *)malloc((count + 1) * sizeof(char));

	start = tem;
	while(*str1)
	{
		*tem = *str1;
		tem++;
		str1++;
	}
	*tem = '\0';

	return start;
}

char **str_search(char *word, char **elements)
{
	char **tem;
	char **start;
	int count;

	tem = (char **)malloc(3 * sizeof(char *));
	start = tem;
	count = 0;
	while(*elements && count < 2)
	{
		if(str_cmp(word,*elements) == 0)
		{

			*tem = str_cpy(*elements);
			tem++;
			count = count + 1;
		}
		elements++;
	}
	*tem = NULL;
	return (start);
}
char *string_minus(char *word, char *minus)
{
	while(*word && *minus && *word == *minus)
	{
		word++;
		minus++;
	}
	return word;
}

void print_Matrix(char **str)
{
	while(*str)
	{
		printf("%s, ",*str);
		str++;
	}
	printf("\n");
}

void print(char *str,char *str1)
{
	printf("%s ",str);
	printf("%s \n",str1);
}


char *pattern_finder(char *word, char **elements)
{
	int count;
	char *split_B;
	char **split_A;
	char **start;
//carbon
// C arbon
// Ca rbon
	split_A = str_search(word , elements);
	start = split_A;
	while(*split_A)
	{
		split_B = string_minus(word,*split_A);
		print(*split_A,split_B);
		pattern_finder(split_B,elements);
		split_A++;
	}

// 	while(*)
// 	{
// 	    printf("%s ",*(split_B));
// 	    split_B++;
// 	}
// 	printf("\n");


	return split_B;
}

int main(int argc, char **argv)
{

    //char word[31];
    //scanf("%[^\n]", word);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    char *word = *(argv + 1);
    char **elements = ft_sort(argv + 2);
    printf("%s|| \n",to_lower(*elements));
    printf("word is : %s\n", word);
    char *N_word = pattern_finder(word, elements);
    //printf("OUtput is : %s\n", N_word);
    while(*elements)
    {
	    printf("%s ",*(elements));
	    elements++;
    }
    //printf("spellings\n");

    return 0;
}
