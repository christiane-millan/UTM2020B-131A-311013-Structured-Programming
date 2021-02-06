#include <stdio.h>
#include <math.h>

int es_primo(int numero);

int main(){
    int resultado, primo = 0, no_primo = 0;
    for(int numero = 1; numero <= 10000; numero++) {
        resultado = es_primo(numero);
        if(resultado == 1){
            //printf("El numero %d es primo\n", numero);
            primo++;
        } else {
            //printf("El numero %d no es primo\n", numero);
            no_primo++;
        }
    } 

    printf("Numero de primos %d, numero de no primos %d\n", primo, no_primo);
    return 0;
}

//2,3,5,7
//4,6,8,9
int es_primo(int numero){
    for (int i = 2; i <= sqrt(numero); i++){
        if ( numero % i == 0){
            return 0;
        }
    }
    return 1;
}