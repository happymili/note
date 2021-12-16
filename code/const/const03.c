#include <stdio.h>

int add(const int a, const int b){
	++a;
	++b;
	return a+b;
}

int main(){
	int a = 3;
	int b = 4;
	int sum;

	sum = add(a, b);
	printf("sum = %d.\n", sum);
	return 0;	
}
