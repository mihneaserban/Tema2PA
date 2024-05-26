#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "Queue_header.h"
#include "Graph_header.h"


int stages ( int n )
{
    int stg = 0 ;
    while( n )
    {
        stg ++ ; 
        n /= 2 ;
    }
    return stg - 1 ;
}

#define max_teams 32

#define WHITESPACE " \t\r\n\v\f"

void trimString ( char * str )
{
    int index = strlen(str) - 1 ;
    while( strchr( WHITESPACE , str[index] ) != NULL )
        index -- ;

    str[index+1] = 0 ;

}

///// functii liste 

void addAtBegging ( team **head , char name[] , float val , int pos )
{
    team * newNode = (team*)malloc(sizeof(team)) ;
    newNode->team_name = (char*)malloc(strlen(name)*sizeof(char)) ;
    
    strcpy( newNode->team_name , name ) ;
    newNode->points = val ;
    newNode->position = pos ;

    newNode->next = *head ;
    *head = newNode ;
}

void printRecList ( team *head , FILE * f_out )
{
    if( head != NULL )
    {
        fprintf( f_out , "%s " , head->team_name ) ;
        fprintf( f_out , "%d\n" , head->position ) ;
        printRecList(head->next,f_out);
    }
}

    // functia de mai jos cauta in lista asociata grafului pozitia unei echipe 
int searchPos ( team * head , char name[] )
{
    int position ;

    while( head != NULL )
    {
        if( strcmp( head->team_name , name ) == 0 )
            {
                position = head->position ;
                return position ;
            }

        head = head->next ;
    }
}

    // functie de comparare a doua float-uri cu precizie de 2 zecimale 

// functia ajuta la aproximarea cu 2 zecimale pentru a fi utillizata mai jos la comparare
float custom_round ( float number , int decimals )  
{
    float factor = 1.0f;
    for (int i=0 ; i<decimals; i++) {
        factor *= 10.0f;
    }
    if (number >= 0) {
        return (float)((int)(number * factor + 0.5f)) / factor;
    } else {
        return (float)((int)(number * factor - 0.5f)) / factor;
    }
}

int compare_float ( float a , float b )  
{
    // Rotunjim valorile la două zecimale
    float rounded_a = custom_round( a ,2 ) ;
    float rounded_b = custom_round( b ,2 ) ;

    
    if (fabs(rounded_a - rounded_b) < 0.01) {
        return 0 ; // Valorile sunt egale
    } else if (rounded_a < rounded_b) {
        return -1 ; // Prima valoare este mai mică
    } else {
        return 1 ; // Prima valoare este mai mare
    }
}



int main( int argc , char * argv[] )
{
    
    // deschiderea fisierelor 

    FILE * input , * out_graf , * out_scor ;

    if ( ( input = fopen(argv[1],"r") ) == NULL )
        printf("Error") ;

    if ( ( out_graf = fopen(argv[2],"w") ) == NULL )
        printf("Error") ;

    if ( ( out_scor = fopen(argv[3],"w") ) == NULL )
        printf("Error") ;

    int i ;
    char name[50] ;
    float pts ;

        // crearea grafului 

    // definirea
    Graph * g = createG( max_teams ) ;
    

    // citirea din input si crearea cozilor 

    Queue * winners = createQueue() ;
    Queue * losers = createQueue() ;
    Queue * games = createQueue() ;

    for( i=0 ; i<max_teams ; i++ )
    {
        fscanf( input , "%f" , &pts ) ;
        fseek( input , 1 , SEEK_CUR ) ;
        fgets( name , 50 , input ) ;

        trimString( name ) ;

        addAtBegging( &(g->T) , name , pts , i ) ;

        enQueue( games , name , pts ) ;

    }    

    //

    int Stages = stages ( max_teams ) ;
    
    
    int copy = max_teams , aux = max_teams ;
    float pts1 , pts2 ;
    char name1[50] , name2[50] ;

    for( i=1 ; i<=Stages ; i++ )
    {
        copy = aux ;

        while( copy > 1 )
        {
            deQueue( games , name1 , &pts1 ) ;
            deQueue( games , name2 , &pts2 ) ;
            
            int comp = compare_float( pts1 , pts2 ) ;
            if( comp == 1 )
            {
                enQueue( winners , name1 , pts1 ) ;
                enQueue( losers , name2 , pts2 ) ;
            }   
            else if ( comp == -1 )
            {
                enQueue( losers , name1 , pts1 ) ;
                enQueue( winners , name2 , pts2 ) ;
            }
            else if ( comp == 0 )
            {
                if( strcmp( name1 , name2 ) > 0 )
                {
                    enQueue( winners , name1 , pts1 ) ;
                    enQueue( losers , name2 , pts2 ) ;
                }
                else
                {
                    enQueue( losers , name1 , pts1 ) ;
                    enQueue( winners , name2 , pts2 ) ;
                }
            }
            copy -= 2 ;
        }

        // aici cream matricea de adiacenta a grafului 
        // luam cate un element din coada de losers si unul din winners si le aflam pozitia in lista
        // si in matricea de adiacenta punem pe pozitia pierzatorului valoarea 1

        ///////////////
    
        while( isEmpty_Q ( losers ) == 0 ) 
        {
            deQueue( losers , name , &pts ) ;
                strcpy( name1 , name ) ;
            deQueue( winners , name , &pts ) ;
                strcpy( name2 , name ) ;

            int p1 = searchPos( g->T , name1 ) ;
            int p2 = searchPos( g->T , name2 ) ;

            addInGraph( g , p1 , p2 ) ;
            
            enQueue( games , name , pts ) ;
        }    

        ///////////////

        aux /= 2 ;


    }

    printGraph( g , out_graf ) ;

    return 0 ;
}