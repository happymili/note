#include <stdio.h>
int main(){
	const int a = 14;
	int * y = &a;
	*(int *)y = 16;
	printf("a == %d.\n", a);

	return 0;
}
