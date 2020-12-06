#include <stdio.h>
#include <stdlib.h>

int tiempo(int horas, int minutos, int segundos);


int main(){
    int horas, minutos, segundos;
    printf("Ingrese horas minutos segundos: ");
    scanf("%d %d %d", &horas, &minutos, &segundos);
    int resultado1 = tiempo(horas, minutos, segundos);
    printf("Ingrese horas minutos segundos: ");
    scanf("%d %d %d", &horas, &minutos, &segundos);
    int resultado2 = tiempo(horas, minutos, segundos);
    printf("%d\n", abs(resultado2 - resultado1));
}

//3h, 15m, 30s
//15h, 55m, 10s
//50h, 200m, 1000s
int tiempo(int horas, int minutos, int segundos){
    int segundos_totales = 0;
    segundos_totales = horas * 60 * 60;
    segundos_totales += minutos * 60;
    segundos_totales += segundos;
    segundos_totales = segundos_totales % 43200;
    return segundos_totales;
}