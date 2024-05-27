#ifndef QUEUE_HEADER

#define QUEUE_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct t
{
    float points ;
    char * name ;
    struct t * next ;

} Team ;

typedef struct 
{
    
    Team * front , * rear ;

} Queue ;


Queue * createQueue () ;

void enQueue ( Queue * q , char teamName[] , float pts ) ;

int isEmpty_Q ( Queue * q ) ;

void deQueue ( Queue * q , char String[] , float * pts ) ;

void printQueue ( Queue * q , FILE * f_out ) ;

void deleteQueue ( Queue * q ) ;


#endif // QUEUE_HEADER