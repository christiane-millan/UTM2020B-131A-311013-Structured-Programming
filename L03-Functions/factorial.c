#include <stdio.h>

int factorial(int n){
    int resultado = 1;
    int i;
    for(i = 1; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}

int factorial_recursivo(int n){
    if ( n == 0 ){
        return 1;
    } else {
        return n * factorial_recursivo( n - 1);
    }
}


int main(){
    int n = 50;
    printf("EL factorial de %d es: %d\n", n, factorial(n));
    return 1;
}