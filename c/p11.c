#include <stdio.h>


void main(){
    int c;

    while((c = getchar()) != EOF){
        printf("%d\n", (c=getchar()) != EOF);
    }
}
