#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
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

char *and_operation(char *a,char *b)
{
	int count ;
	char *start;
	char *output;

	count = str_len(a); 
	output =  (char *)malloc((count + 1) * sizeof(char));
	
	start = output;
	while(*a && *b )
	{
		if(*a == '-' && *b == '-')
			*output = '-'; 
		else
			*output = '_';
		output++;
		a++;
		b++;
	}
	*output = '\0';
	return start;
}

char *or_operation(char *a,char *b)
{
	int count ;
	char *start;
	char *output;

	count = str_len(a); 
	output =  (char *)malloc((count + 1) * sizeof(char));
	
	start = output;
	while(*a && *b )
	{
		if(*a == '-' || *b == '-')
			*output = '-'; 
		else
			*output = '_';
		output++;
		a++;
		b++;
	}
	*output = '\0';
	return start;
}

char *xor_operation(char *a,char *b)
{
	int count ;
	char *start;
	char *output;

	count = str_len(a); 
	output =  (char *)malloc((count + 1) * sizeof(char));
	
	start = output;
	while(*a && *b )
	{
		if(*a == *b)
			*output = '_'; 
		else
			*output = '-';
		output++;
		a++;
		b++;
	}
	*output = '\0';
	return start;
}

char *nand_operation(char *a,char *b)
{
	int count ;
	char *start;
	char *output;

	count = str_len(a); 
	output =  (char *)malloc((count + 1) * sizeof(char));
	
	start = output;
	while(*a && *b )
	{
		if(*a == '-' && *b == '-')
			*output = '_'; 
		else:wq

			*output = '-';
		output++;
		a++;
		b++;
	}
	*output = '\0';
	return start;
}

char *nor_operation(char *a,char *b)
{
	int count ;
	char *start;
	char *output;

	count = str_len(a); 
	output =  (char *)malloc((count + 1) * sizeof(char));
	
	start = output;
	while(*a && *b )
	{
		if(*a == '-' || *b == '-')
			*output = '_'; 
		else
			*output = '-';
		output++;
		a++;
		b++;
	}
	*output = '\0';
	return start;
}

char *nxor_operation(char *a,char *b)
{
	int count ;
	char *start;
	char *output;

	count = str_len(a); 
	output =  (char *)malloc((count + 1) * sizeof(char));
	
	start = output;
	while(*a && *b )
	{
		if(*a == *b)
			*output = '-'; 
		else
			*output = '_';
		output++;
		a++;
		b++;
	}
	*output = '\0';
	return start;
}

int to_int(char *str)
{
	if(str)
		return *str - '0';
	else
		return 0;
}

// int	main(int argc,char **argv)
// {
// 	int n = to_int(*(argv + 1));
// 	int m = to_int(*(argv + 2));
// 	printf("%d\n",n);
// 	printf("%d\n",m);
// 
// 	char *a = *(argv + 3);
// 	char *b = *(argv + 4);
// 
// 	char *output = nor_operation(a,b);
// 
// 	printf("%s",output);
// 
// 
// 	return (0);
// }


int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        char input_name[9];
        char input_signal[65];
        scanf("%s%s", input_name, input_signal);
    }
    for (int i = 0; i < m; i++) {
        char output_name[9];
        char type[9];
        char input_name_1[9];
        char input_name_2[9];
        scanf("%s%s%s%s", output_name, type, input_name_1, input_name_2);

    }
    for (int i = 0; i < m; i++) {

        // Write an answer using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        printf("output name and signal\n");
    }

    return 0;
}
