#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int a = 0, b = 1, c;
    printf("%d %d ", a, b);
    for(int i = 2; i < n; i++){
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}