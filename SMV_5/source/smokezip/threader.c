// $Date$ 
// $Revision$
// $Author$
#define INTHREADER
#include "options.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "zlib.h"
#include "ASSERT.h"
#include "svzip.h"

// svn revision character string
char threader_revision[]="$Revision$";

/* ------------------ init_all_threads ------------------------ */

void init_pthread_mutexes(void){
#ifdef pp_THREAD
  pthread_mutex_init(&mutexCOMPRESS,NULL);
  pthread_mutex_init(&mutexPATCH,NULL);
  pthread_mutex_init(&mutexPATCH_BOUND,NULL);
  pthread_mutex_init(&mutexSLICE,NULL);
  pthread_mutex_init(&mutexSLICE_BOUND,NULL);
  pthread_mutex_init(&mutexISOS,NULL);
  pthread_mutex_init(&mutexSMOKE,NULL);
  pthread_mutex_init(&mutexPLOT3D,NULL);
  pthread_mutex_init(&mutexPART2ISO,NULL);
  pthread_mutex_init(&mutexPRINT,NULL);
#endif
}

/* ------------------ print_thread_stats ------------------------ */

void print_thread_stats(void){
#ifdef pp_THREAD
  int i;
  int sum;
  int lastthread;

  sum=0;
  for(i=0;i<mt_nthreads;i++){
    if(threadinfo[i].stat>0){
      sum++;
      lastthread=i;
    }
  }
  if(sum>0){
    char pp[2];

    strcpy(pp,"%");
    for(i=0;i<mt_nthreads;i++){
      threaddata *ti;

      ti = threadinfo+i;
      if(ti->stat>0){
        printf(" %s(%i%s)",ti->label,ti->stat,pp);
        if(lastthread!=i)printf(",");
      }
    }
    printf("\n");
  }
#endif
}


