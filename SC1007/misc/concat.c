#include <stdio.h>
#include <stdlib.h>

int concat(int a, int b);

int main(){
    int i,j, k;
    printf("Enter 2 numbers:\n");
    scanf("%d %d", &i, &j);
    k = concat(i,j);
    printf("Concatenated number: %d\n", k);
}

int concat(int a, int b){
    if(b/10 == 0){
        return a * 10 + b % 10;
    }
    return concat(a * 10 + b % 10, b/10);
}
