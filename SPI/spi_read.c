#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread1, thread2;
pthread_mutex_t spi_read_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

int exit_spi_read = 0;

void spi_read_thread (void *threadID){

     while (!exit_spi_read){
          
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
