
#include "Global.h"
int tik=0;
int seinalea=0;
int CORE, THREAD, QUANTUM;

 pthread_mutex_t clock_l;
 pthread_mutex_t timer_l;

sem_t sem1;
sem_t sem2;
sem_t sem3;

struct cpu pcu;



void sortu_hariak(int timer_count, int pcb_rand){
int err;
pthread_t *hariak;
struct timer_parametroak *pcbs;
struct timer_parametroak *t_p;
t_p=malloc(timer_count * sizeof(struct timer_parametroak));
t_p[0].denb=timer_count;
pcbs=malloc(pcb_rand * sizeof(struct timer_parametroak));
pcbs[0].denb=pcb_rand;

hariak = malloc(hari_kop * sizeof(pthread_t)); 

err = pthread_create(&hariak[0],NULL, hari_timer,(void*)&t_p[0]);;
   if(err==0){
 printf("haria timer sortu da\n");}
    
err = pthread_create(&hariak[1], NULL, hari_clock,NULL);;
if (err==0){
    printf("haria clock sortu da\n");}

    err = pthread_create(&hariak[2], NULL, hari_pcb,(void*)&pcbs[0]);;
if (err==0){
    printf("haria pcb sortu da\n");}

 err = pthread_create(&hariak[3], NULL, hari_scheduler,NULL);;
if (err==0){
    printf("haria scheduler sortu da\n");}

int s;
for (s=0;s < hari_kop;s++)
pthread_join(hariak[s], NULL);


free(hariak);
free(t_p);




}

int main(int argc, char *argv[]){

if(argc != 3){

fprintf(stderr, "Erabilpena: Sartu timerraren denbora eta zenbatero sortu behar den pcb timer denbora ms tan\n");
        exit(1);
    
}
int er;
char *p;
sem_init (&sem1,1,1);
sem_init (&sem2,1,1);
sem_init(&sem3,1,0);

printf("programa hasi da \n");

int i, timer_count, pcb_rand;



pthread_mutex_init(&clock_l, 0);
pthread_mutex_init(&timer_l, 0);


 printf("Sartu CORE kopurua:");
scanf("%d",&CORE);
printf("Sartu Hari kopurua:");
scanf("%d",&THREAD);
printf("Sartu quantum-aren luzeera ms-tan:");
scanf("%d",&QUANTUM);

pcu.corenum=malloc(CORE*sizeof(struct core));
 for(int i=0;i<CORE;i++){

    pcu.corenum[i].coreId=i;
    pcu.corenum[i].loadid=1;
    pcu.corenum[i].priority=0;
    pcu.corenum[i].threadnum=malloc(THREAD*sizeof(struct thread));

    for (int j = 0; j < THREAD; j++){
    
      pcu.corenum[i].threadnum[j].threadid=j;
      pcu.corenum[i].threadnum[j].usable=0;
      pcu.corenum[i].threadnum[j].quantum=QUANTUM;
        
        for(int h =0 ; h<15; h++){
            
            pcu.corenum[i].loader1[h].total=0;
            pcu.corenum[i].loader1[h].now=0;
            pcu.corenum[i].loader2[h].total=0;
            pcu.corenum[i].loader2[h].now=0;            

                for(int l=0; l<30; l++){
                    pcu.corenum[i].loader1[h].lista[l].pid=0;
                    pcu.corenum[i].loader1[h].lista[l].exe=4;

          }

}




}




}


timer_count=strtol(argv[1],&p,10);
pcb_rand=strtol(argv[2],&p,10);

sortu_hariak(timer_count, pcb_rand);

	pthread_mutex_destroy(&clock_l);
	pthread_mutex_destroy(&timer_l);
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	sem_destroy(&sem3);

return(0);





}
