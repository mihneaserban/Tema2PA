#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>



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

    

    return 0 ;
}