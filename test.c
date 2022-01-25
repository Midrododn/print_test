#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void){

	ft_printf("\n---------------------\n");

	int tmp = ft_printf("%c", 'A');
	int tmp2 = printf("%c", 'A');
	printf("\n%d %d\n ", tmp, tmp2);
	return 0;
}