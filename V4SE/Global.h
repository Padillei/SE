
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#ifndef GLOBALAK_H_
#define GLOBALAK_H_
#define hari_kop 4
#define prozesu_kop 100
#define exekuzio_ilara 10

int MAX;
extern int tik;
extern int seinalea;
extern pthread_mutex_t clock_l;
extern pthread_mutex_t timer_l;
extern int CORE;
extern int THREAD;
extern int QUANTUM;
extern sem_t sem1;
extern sem_t sem2;
extern sem_t sem3;
extern struct prozesuak proclist;
extern struct cpu pcu;




struct prozesuak{ 
//identifikatzailea
int pid;
//lehentasuna
int pref;
//ze egoeratan dagoen 0=itxazwroten 1=exekutatzen 2=Blokeatuta/lotan 4=amaituta
 int exe;
//Prozesua exekutatzeko behar den denbora
int denb;
//exekutatu den denbora
int denbpasa;
// Prozesua core baten barruan dagoen edo ez jakiteko
int barruan;

};

struct queue{
    struct prozesuak *buff;
    int index;
};

struct prio{
//lehentasun maila honetan dauden prozesu kopurua
int total;
//lehentasun honetako zenbagarren prozesua den zehazten du
int now;
struct prozesuak lista[30];
};

//prozesadoreko hardwarea
struct thread{
int threadid;
int usable;
int quantum;
struct prozesuak prozesua;
};

struct core {
//corearen identifikadorea
int coreId;
//core barruko thread kopurua
struct thread *threadnum;
//corera eta hari/thread era sartzeko bi ilara
struct prio loader1[15];
struct prio loader2[15];
//zein ilaratan gauden jakiteko
int loadid;
//zenbagarren lehentasunean lan egiten gauden
int priority;
} ;

struct cpu{
struct core *corenum;

};

struct hariaren_parame{

  int  haria_id;

};

struct timer_parametroak{

   int denb;
};


void *hari_timer(int *t_p);

void *hari_clock();

void *hari_scheduler();

void *hari_pcb(int *pcbs);
#endif
