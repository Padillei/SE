#include"Global.h"
#include <time.h>

struct queue ilara;

void *hari_pcb(int *pcbs){
MAX=*pcbs;
time_t t;
srand((unsigned)time(&t));
ilara.index=0;
ilara.buff =malloc(MAX*sizeof(struct prozesuak));
int i=1; 
int d,l,c,k,j,m,p;
int cont=0;
k=0;
j=0;
for(int p=0;p<MAX;p++){

ilara.buff[p].barruan=1;
ilara.buff[p].pid=0;

}
while(1){
d=rand();

l=rand()% 15;
c=rand()%100000;
if(d!=0){
sleep(d%2);

struct prozesuak process;

process.pid=i;
process.denb=c;
process.exe=1;
process.barruan=0;
process.denbpasa=0;
printf("%d prozesua sortu da %d iraupenarekin\n",i,process.denb);
sem_post(&sem1);

while(k==0){
pthread_mutex_lock(&timer_l);
if(ilara.buff[j%MAX].barruan==1){
ilara.buff[j%MAX]=process;
save(j%CORE,process);
ilara.index++;
k=1;}else{
j++;}if(ilara.index==MAX){
ilara.index=0;}else{ilara.index++;}

}
pthread_mutex_unlock(&timer_l);
k=0;
j++;
i++;



}

}

}

void save(int core, struct prozesuak proc){
if(proc.pid!=0){
if(pcu.corenum[core].loadid==1){
if(proc.pref > pcu.corenum[core].priority){
proc.barruan=1;
pcu.corenum[core].loader1[proc.pref].lista[pcu.corenum[core].loader1[proc.pref].total]=proc;
pcu.corenum[core].loader1[proc.pref].total++;
printf("Pid %d.Core :%d. Prio: %d. \n", proc.pid, core, proc.pref);
}else{
proc.barruan=1;
pcu.corenum[core].loader2[proc.pref].lista[pcu.corenum[core].loader2[proc.pref].total]=proc;
pcu.corenum[core].loader2[proc.pref].total++;
printf("Pid %d.Core :%d. Prio: %d. \n", proc.pid, core, proc.pref);





}}else{
if(proc.pref > pcu.corenum[core].priority){
proc.barruan=1;
pcu.corenum[core].loader2[proc.pref].lista[pcu.corenum[core].loader2[proc.pref].total]=proc;
pcu.corenum[core].loader2[proc.pref].total++;
printf("Pid %d.Core :%d. Prio: %d. \n", proc.pid, core, proc.pref);
}else{
proc.barruan=1;
pcu.corenum[core].loader1[proc.pref].lista[pcu.corenum[core].loader1[proc.pref].total]=proc;
pcu.corenum[core].loader1[proc.pref].total++;
printf("Pid %d.Core :%d. Prio: %d. \n", proc.pid, core, proc.pref);



}





}}}





