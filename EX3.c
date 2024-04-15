#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>



int main(int argc , char * argv[]){
    int i , value ; 
    char *ptr ;
    sscanf( argv[1] , "%x" , &value );
    printf("%x represente ainssi ",value);
for( i = 0 ; i < sizeof(value) ; i++ ){
    
    ptr = (char *) &value ;
    printf("%x \t",ptr[i]); 
    
    }
    printf("\n");
return (0);
}
