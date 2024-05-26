#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct idk 
{
    int position ;
    float points ;
    char * team_name ;
    struct idk * next ;
} ;
typedef struct idk team ;


typedef struct 
{
    int V , E ;
    int ** a ;
    team * T ;

} Graph ;


Graph * createG () ;

void printGraph ( Graph * g , FILE * out ) ;

void addInGraph ( Graph * g , int p1 , int p2 ) ;