#include <stdio.h>  
#include <setjmp.h>  

void second(void);
   
static jmp_buf buf;  

void first(void)
{
	second();
	printf("this line will not be executed\n");
}  

void second(void)
{  
	printf("hello\n");
	longjmp(buf, 123); //jump back to setjmp
}  
   
int main(void)
{
	int ret;
	ret = setjmp(buf); //save environment
	printf("setjmp return : %d\n", ret);

	if (ret == 0) {  
		first();
	} else { 
		printf("leave\n");
	}  
   
	return 0;  
}  
