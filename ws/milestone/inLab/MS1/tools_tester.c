#include <stdio.h>
#include "item.h"
#include "tools.h"

int main(void) {
	int a;
	double b;
	printf("Int: ");
	scanInt(&a);
	printf("The int is: %d\n", a);
	printf("Double: ");
	scanDouble(&b);
	printf("The double is: %lf\n", b);
	return 0;
}