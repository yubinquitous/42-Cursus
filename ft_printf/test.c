// 가변인자 공부
#include <stdio.h>
#include <stdarg.h>

int sum(int num_args, ...);
int main(void)
{
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	printf("%d\n", sum(5, a,b,c,d,e));
	int n = printf("%d", 5);
	printf("printf : %d\n", n);
	return 0;
}

int sum(int num_args, ...)
{
	va_list ap;
	va_start(ap, num_args);
	int arg = 0, result = 0;
	for (int i = 0; i < num_args; i++)
	{
		arg = va_arg(ap, int);
		result += arg;
	}
	va_end(ap);
	return result;
}
