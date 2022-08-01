#include <stdio.h>


void cb_0()
{
	printf("Cb0\n");
}

void cb_1()
{
	printf("Cb1\n");
}

void call_cb(void (*fn)())
{
//	(*fn)();
	fn();
}

int main()
{
	call_cb(&cb_0);
	call_cb(cb_1);
	return 0;
}
