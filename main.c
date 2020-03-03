#include <stdio.h>

int main(void) {
	typedef struct {
		unsigned a1, a2, a3, a4, a5;
	} five_u_t;
	typedef struct {
		unsigned a1, a2;
	} two_u_t;
	typedef struct {
		five_u_t f;
		two_u_t t;
	} seven_u_t;
	seven_u_t s;
	printf("s首地址：%lld\nf首地址：%lld\nt首地址：%lld\n下一个首地址：%"
	       "lld\n",
	       &s, &(s.f), &(s.t), (seven_u_t*)(&s)+1);
}