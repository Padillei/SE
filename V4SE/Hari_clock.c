#include"Global.h"




void *hari_clock(){
	
    
	while(1){
   //printf("Clock hasi da eta tik %d da \n", tik);
    pthread_mutex_lock(&clock_l);
   
    tik++;
    


	pthread_mutex_unlock(&clock_l);
		
	}
	pthread_exit(1);
	
}



