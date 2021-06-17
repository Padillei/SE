
#include "Global.h"

void *hari_timer(int *t_p ){
	int erro;

    
	struct timer_parametroak *lag;
    lag=(struct timer_parametroak *)t_p;
	int timer=lag->denb;
    timer=timer*1000;
	
    
	while(1){
pthread_mutex_lock(&clock_l);

	if(tik>=timer){
    tik=0;;
	pthread_mutex_lock(&timer_l);
	seinalea=1;
    
    
  
    pthread_mutex_unlock(&timer_l);

	}
pthread_mutex_unlock(&clock_l);

	}
	pthread_exit(NULL);
	
}


