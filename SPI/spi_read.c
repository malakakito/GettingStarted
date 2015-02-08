#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread1, thread2;
pthread_mutex_t spi_read_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  spi_read_cond   = PTHREAD_COND_INITIALIZER;

int exit_spi_read = 0;
int spi_read_loop = 0;

int spi_read_start_loop (int start){
     int retval = 0;
     if (start){
          spi_read_loop = 1;
          retval = pthread_cond_broadcast (&spi_read_cond);
     }
     else {
          spi_read_loop = 0;
          retval = 0;
     }
     return retval;
}

int exit_spi_read (void){
     exit_spi_read = 1;
}

void spi_read_thread (void *threadID){

     while(!exit_spi_read){
          pthread_mutex_lock( &spi_read_mutex );
          while (!spi_read_loop){
               pthread_cond_wait (&spi_read_cond, &spi_read_mutex);
          }
          
          pthread_mutex_unlock( &count_mutex );
     }
}

int init_spi_read (unsigned int buffer_size){
     int  iret1, iret2;
     int  threadID=0;
     
     iret1 = pthread_create( &thread1, NULL, spi_read_thread, (void*) &threadID);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*)  &(threadID=1));
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }
}
