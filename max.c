#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

    uint64_t start = 0;
    uint64_t end = 0;
    uint64_t elapsed = 0;
    uint64_t avg = 0;
    struct timespec t_start, t_end;
    int loop = 100000;


#if defined(BITWISE)//Avoid Integer Overflow

int get_max(int a,int b){
	return (   ( ((1^(a>>31&0x1) )^(1^(b>>31&0x1) ))^1)*(a*(1^((a-b)>>31&0x1) )+b*(1^(1^((a-b)>>31&0x1) ))) + (((1^(a>>31&0x1) )^(1^(b>>31&0x1) )))*(a*(1^(a>>31&0x1) )+b*(1^(b>>31&0x1) ))   );
}

#endif

#if defined(OPERATOR)//May cause Integer Overflow

int get_max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

#endif

int main(void)
{
	int i;
	for(i = 0;i<loop;i++){
		clock_gettime(CLOCK_MONOTONIC, &t_start);
		get_max(-100,-2147483646);
		clock_gettime(CLOCK_MONOTONIC, &t_end);
		start = ((uint64_t)(t_start.tv_sec) * 1000000000LL + t_start.tv_nsec);
        end = (uint64_t)(t_end.tv_sec) * 1000000000LL + t_end.tv_nsec;
        elapsed += (end-start);
	}
	avg = elapsed/loop;
	printf("big :%d\n", get_max(-100,-2147483646));
	printf("average time:%" PRIu64 " \n", avg);
	
	return 0;
}
