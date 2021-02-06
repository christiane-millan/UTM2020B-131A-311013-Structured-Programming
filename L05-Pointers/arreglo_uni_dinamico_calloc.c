#include <stdio.h>
#include <stdlib.h>

void leer_calorias(int a[], int tam);
float promedio_calorias(int a[], int tam);

int main(){
    //int cal[10];
    int *calorias = NULL;
    int tamanno;

    printf("Ingresa cantidad de días en que se registrarán las calorías:");
    scanf("%d", &tamanno);

    //malloc (reserva el espacio pero no borra lo que existe)
    //calloc (reserva el espacio per borra lo que existe)
    calorias = (int *) calloc (tamanno, sizeof(int));
    if (calorias != NULL){
       //leer_calorias(calorias, tamanno);
       printf("El promedio de calorías consumidas en %d días fue %.2f\n"
        , tamanno
        , promedio_calorias(calorias, tamanno));
        free(calorias);
    } else {
        printf("No se pudo reservar la memoria\n");
    }
    
    
    
    return 0;
}


void leer_calorias(int a[], int tam){
    for (int i = 0; i < tam; i++){
        printf("Ingrese las calorias consumidas en el dia: ");
        scanf("%d", &a[i]);
    }
    
}

float promedio_calorias(int a[], int tam){
    int suma = 0;
    for (int i = 0; i < tam; i++){
        suma += a[i];
    }
    return (suma/tam);
}