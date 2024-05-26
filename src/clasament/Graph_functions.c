#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Graph_header.h"

Graph * createG ( int nodes )
{
    int i , j ;
    Graph * g = (Graph*)malloc(sizeof(Graph)) ;
    if( g == NULL )
        {
            printf("memerror") ;
            return NULL ;
        }

    g->V = nodes ;
    g->a = (int **)malloc(g->V*sizeof(int*)) ;

    for( i=0 ; i<g->V ; i++ )
    {
        g->a[i] = (int*)calloc( g->V , sizeof(int) ) ;
    }

    if( g->a == NULL )
        printf("memerror") ;
    
    g->E = 0 ;

    return g ;

}

void printGraph ( Graph * g , FILE * out )
{
    int i , j ;
    for( i=0 ; i<g->V ; i++ )
    {
        for( j=0 ; j<g->V ; j++ )
            fprintf( out , "%d " ,g->a[i][j] ) ;
        fprintf( out , "\n" ) ;
    }
}

void addInGraph ( Graph * g , int p1 , int p2 )
{
    g->a[p1][p2] = 1 ;
}
