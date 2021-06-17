
#include "Global.h"


void *hari_scheduler(){
printf("Schedulerra martxan dago\n");
while(1){
    sem_wait(&sem1);
    
   pthread_mutex_lock(&timer_l);
    exec();

	pthread_mutex_unlock(&timer_l);
		
	}
	pthread_exit(NULL);


}

void exec(){
printf("exekutatzen\n");
int i,j,k,m;
int end=0;

for (i=0;i<CORE;i++)
{

end=0;
for(j=0;j< THREAD;j++){

end=0;

if(pcu.corenum[i].threadnum[j].usable==1){

break;
}else{
if(pcu.corenum[i].loadid==1){

int nowaux=pcu.corenum[i].loader1[pcu.corenum[i].priority].now;
int prioaux=pcu.corenum[i].priority;
    
    for(k = 0; k <15; k++){

if(pcu.corenum[i].loader1[k].total==0){

}else{


for(m=0;m<pcu.corenum[i].loader1[k].total; m++){

if(pcu.corenum[i].loader1[k].lista[m].exe==1){
pcu.corenum[i].loader1[k].lista[m].exe=2;
pcu.corenum[i].loader1[pcu.corenum[i].priority].now=m;
    pcu.corenum[i].priority=k;
pcu.corenum[i].threadnum[j].usable=0;
pcu.corenum[i].threadnum[j].prozesua=pcu.corenum[i].loader1[k].lista[m];

end=1;
printf("%d prozesua exekutatzen, %d core %d thread-an \n",pcu.corenum[i].loader1[k].lista[m].pid,i,j);
break;
}


}
if(end==1){
break;

}
}


}

if(k==15){
pcu.corenum[i].loadid=2;
pcu.corenum[i].priority=0;

}

if(end==1){break;}


}else{int nowaux=pcu.corenum[i].loader2[pcu.corenum[i].priority].now;
int prioaux=pcu.corenum[i].priority;
    
    for(k = 0; k <15; k++){

if(pcu.corenum[i].loader2[k].total==0){

}else{


for(m=0;m<pcu.corenum[i].loader2[k].total; m++){

if(pcu.corenum[i].loader2[k].lista[m].exe==1){
pcu.corenum[i].loader2[k].lista[m].exe=2;
pcu.corenum[i].loader2[pcu.corenum[i].priority].now=m;
    pcu.corenum[i].priority=k;
pcu.corenum[i].threadnum[j].usable=0;
pcu.corenum[i].threadnum[j].prozesua=pcu.corenum[i].loader2[k].lista[m];

end=1;
printf("%d prozesua exekutatzen, %d core %d thread-an \n",pcu.corenum[i].loader2[k].lista[m].pid,i,j);
break;
}


}
if(end==1){
break;

}
}


}

if(k==15){
pcu.corenum[i].loadid=2;
pcu.corenum[i].priority=0;

}

if(end==1){break;}


}

}
}



}





}
