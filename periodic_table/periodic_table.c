#include <stdlib.h>
#include <stdio.h>


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
	while(*word && *minus && make_lower(*word) == make_lower(*minus))
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
		printf("%s",*str);
		str++;
	}
	printf("\n");
}
int empty(char **str)
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

int pattern_finder(char *word, char **elements, char **output, char **beg)
{
	char *split_B;
	char **split_A;
	char **start;
	static int count;


	split_A = str_search(word , elements);
	start = split_A;
	while(*split_A)
	{
		split_B = string_minus(word,*split_A);
		*output = *split_A;
		if(*split_B == '\0')
		{
			*(output + 1) = NULL;
			print_Matrix(beg);
			free(start);
			count++;
			return count;
		}
		pattern_finder(split_B,elements,output+1,beg);
		split_A++;
	}
        	free(start);
	return count;
}
// main 1
// you can use this in coding game directly
int main()
{
    char word[31];
    scanf("%[^\n]", word);

    char *p = word;
    char *elements[] = { 
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", 
        "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", 
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", 
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", 
        "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", 
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", 
        "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", 
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", 
        "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", 
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", 
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", NULL
    };
    int count = str_len(p);
    char **output = malloc((count + 1) * sizeof(char *));
    char **beg ;
    char **sorted_elements = ft_sort(elements);
    beg = output;  
    int pattern_found = pattern_finder(p, sorted_elements, output, beg);
    if (pattern_found == 0)
	    printf("none");
    //print_Matrix(output);
    //free(output);
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    //printf("spellings\n");

    return 0;
}

// main 2
// this main you can use for testing and to do specific input of elements and for testing

// int main(int argc, char **argv)
// {
//     printf("Number of arguments : %d\n", argc);
//     char *word = *(argv + 1);
//     char **elements = ft_sort(argv + 2);
// 
//     int count = str_len(word);
//     char **output = malloc((count + 1) * sizeof(char *));
//     char **beg ;
// 
//     beg = output;  
//     pattern_finder(word, elements, output, beg);
//     if (empty(output) == 0)
// 	    printf("none");
//     free(beg);
// 
//  
//     return 0;
// }
