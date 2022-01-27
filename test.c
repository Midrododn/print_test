#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void){

	ft_printf("\n---------------------\n");
	char	*ptr = NULL;

	int tmp = ft_printf("ft str=%s|\n", ptr);
	int tmp2 = printf("pr str=%s|\n", ptr);
	printf("\n!%d %d!\n ", tmp, tmp2);

	tmp = ft_printf("ft ptr=%p|\n", ptr);
	tmp2 = printf("pr ptr=%p|\n", ptr);
	printf("\n%d %d\n ", tmp, tmp2);

	return 0;
}