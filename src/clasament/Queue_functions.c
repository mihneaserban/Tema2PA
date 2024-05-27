#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Queue_header.h"


// creare coada

Queue * createQueue ()
{
    Queue * q ;
    q = (Queue*)malloc(sizeof(Queue)) ;
    if( q ==  NULL ) return NULL ;
    q->front = q->rear = NULL ;
    return q ;
}

/// adaugare elemente la coada

void enQueue ( Queue * q , char teamName[] , float pts )
{

    Team * newNode = (Team*)malloc(sizeof(Team)) ;
    newNode->name = (char*)malloc(strlen(teamName)*sizeof(char)) ;

    if( q->front == NULL )
        q->rear = NULL ;

    strcpy( newNode->name , teamName ) ;
    newNode->points = pts ;
    newNode->next = NULL ;

    if( q->rear == NULL )
        q->rear = newNode ;
    else
    {
        (q->rear)->next = newNode ;
        (q->rear) = newNode ;
    }
    if( q->front == NULL )
        q->front = q->rear ;


}

int isEmpty_Q ( Queue * q )
{
    return  (q->front == NULL)  ;
}

/// functie de eliminare din coada

void deQueue ( Queue * q , char String[] , float * pts )
{
    Team * aux ;

    aux = q->front ;
    strcpy( String , (aux->name ) ) ;
    *pts = aux->points ;
    q->front = (q->front)->next ;
    free(aux) ;

}

void printQueue ( Queue * q , FILE * f_out )
{
    Team * aux ;
    aux = q->front ;
    while(aux!=NULL)
    {
        fprintf(f_out,"%s\n",aux->name);
        aux = aux->next;
    }
}

void deleteQueue ( Queue * q ) 
{
    Team * aux ;
    while ( ! isEmpty_Q( q ) )
    {
        aux = q->front ;
        q->front = (q->front)->next ;
        free( aux ) ;
    }
    free( q ) ;
}