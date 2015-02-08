#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void spi_read_thread (void *threadID){

}

int init_spi_read (unsigned int buffer_size){
     pthread_t thread1, thread2;
     int  iret1, iret2;
     int  threadID=0;
     
     iret1 = pthread_create( &thread1, NULL, spi_read_thread, (void*) &(threadID=1));
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*)  &(threadID=2));
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }
}
