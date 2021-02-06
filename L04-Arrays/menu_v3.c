#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100
#define MAX_ASISTENCIA 5
#define MAX_CALIFICACIONES 4
#define MAX_NOMBRE 60

int matricula = 123456;
char nombre[MAX_NOMBRE] = "Juan Carlos";
float calificaciones[MAX_CALIFICACIONES] = {0.0, 0.0, 0.0, 0.0};
int asistencias[MAX_ASISTENCIA] = {1, 1, 1, 1, 1};
bool estatus = true; //0 esta dado de baja caso si es 1 es que activo
//int asistencia = 1;
//int asistencias[5] = {1, 1, 1, 1, 1, 1};

float promedio(float c[]); //prototipo de una función
float minimo(float c[]);
float maximo(float c[]);
void imprimir_alumno();
void modificar_alumno();
void agregar_alumno();
void menu_modificacion_calificaciones(float c[]);
void imprimir_menu();
void inicializar_asistencia();
void imprimir_asistencias();
void pase_asistencia();

void inicializar_asistencia(){
    // asistencias[0] = 0;
    // asistencias[1] = 0;
    // asistencias[2] = 0;
    // asistencias[3] = 0;
    // asistencias[4] = 0;
    //asistencias[5] = 0;
    //i =  0, 1, 
    for (int i = 0; i < MAX_ASISTENCIA; i++)
    {
        asistencias[i] = 0;
    }
}

void pase_asistencia(){
    int dia;
    printf("Pase de asistencia...\n");
    printf("Indicar dia de asistencia [1 - %d]: ", MAX_ASISTENCIA);
    scanf("%d", &dia);
    printf("[0]=Falta o [1]=Asistencia: ");
    scanf("%d", &asistencias[dia - 1]);
}

// void imprimir_asistencias(){
//     printf("Asistencias: ");
//     for (int i = 0; i < MAX_ASISTENCIA; i++)
//     {
//         if (asistencias[i] == 1)
//             if( i == MAX_ASISTENCIA-1)
//                 printf("%s", "A, ");
//             else 
//                 printf("%s", "A, ");    
//         else 
//             if( i == MAX_ASISTENCIA-1)
//                 printf("%s", "F");
//             else
//                 printf("%s", "F, ");         
//     }
//     printf("\n");
// }

void imprimir_asistencias(){
    printf("Asistencias: ");
    for (int i = 0; i < MAX_ASISTENCIA-1; i++)
    {
        if (asistencias[i] == 1)
            printf("%s", "A, ");    
        else 
            printf("%s", "F, ");         
    }
    //if (asistencias[MAX_ASISTENCIA-1] == 1 ) printf("%s", "A"); else printf("%s", "F");
    (asistencias[MAX_ASISTENCIA-1] == 1)?printf("%s", "A"):printf("%s", "F");
    printf("\n");
}

void modificar_alumno(){
    puts("\tMenu para cambio de nombre...");
    printf("El nombre del alumno es: %s\n", nombre);
    printf("Ingresa el nuevo nombre: ");
    fflush(stdin);
    //scanf(" %s", nombre);
    //gets(nombre);
    fgets(nombre, 60, stdin);
}

void menu_modificacion_calificaciones(float c[]){
    int opt = 0;
    float r = 0.0;
    while(opt != 5) {
        printf("1. Modificar calificación 1:\n");
        printf("2. Modificar calificación 2:\n");
        printf("3. Modificar calificación 3:\n");
        printf("4. Modificar calificación f:\n");
        printf("5. Salir:\n");

        printf("Ingresa una opción:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1: printf("La calificación actual es: %f\n", c[0]);
                printf("Ingresa nueva calificación 1:");
                scanf("%f", &c[0]); 
            break;
        case 2: printf("La calificación actual es: %f\n", c[1]);
                printf("Ingresa nueva calificación 2:");
                scanf("%f", &c[1]);
            break;
        case 3: printf("La calificación actual es: %f\n", c[2]);
                printf("Ingresa nueva calificación 3:");
                scanf("%f", &c[2]);
            break;
        case 4: printf("La calificación actual es: %f\n", c[3]);
                printf("Ingresa nueva calificación f:");
                scanf("%f", &c[3]);
            break;
        
        default:
            break;
        }
    }
}

void imprimir_alumno(){
    printf("Matrícula: %d\n", matricula);
    printf("Nombre del alumno: %s\n", nombre);
    // printf("Calificación 1: %.2f\n", calificacion1); //8.3
    // printf("Calificación 2: %.2f\n", calificacion2); //7.1
    // printf("Calificación 3: %.2f\n", calificacion3); //6.1
    // printf("Calificación f: %.2f\n", calificacionf); //9.9
    printf("Calificación 1: %.2f\n", calificaciones[0]); //8.3
    printf("Calificación 2: %.2f\n", calificaciones[1]); //7.1
    printf("Calificación 3: %.2f\n", calificaciones[2]); //6.1
    printf("Calificación f: %.2f\n", calificaciones[3]); //9.9
    float prom = promedio(calificaciones);
    printf("Promedio : %.2f\n", prom);
    float m;
    m = minimo(calificaciones);
    printf("Calificación mínima: %.2f\n", m);
    m = maximo(calificaciones);
    printf("Calificación máxima: %.2f\n", m);
    imprimir_asistencias();
}

void agregar_alumno(){
    printf("Ingresa la matrícula:");
    scanf("%d", &matricula);
    fflush(stdin);
    printf("Ingresa el nombre del alumno:");
    //scanf(" %s", nombre);
    fgets(nombre, 60, stdin);
    // printf("Ingresa calificación 1:");
    // scanf("%f", &calificacion1);
    // printf("Ingresa calificación 2:");
    // scanf("%f", &calificacion2);
    // printf("Ingresa calificación 3:");
    // scanf("%f", &calificacion3);
    // printf("Ingresa calificación final:");
    // scanf("%f", &calificacionf);
}

void imprimir_menu(){
    printf("Menu de opiones\n");
    printf("1. Agregar alumno\n");
    printf("2. Modificar alumno\n");
    printf("3. Modificar calificaciones\n");
    printf("4. Imprimir datos del alumno\n");
    printf("5. Pase de lista\n");
    printf("6. Salir\n");
    printf("Ingresa una opción: \n");
}

int main () {
    inicializar_asistencia();
    srand(time(0));
    int opcion;
    while (opcion != 6) {
        imprimir_menu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: agregar_alumno();
                break;
            case 2: modificar_alumno();
                break;
            case 3: menu_modificacion_calificaciones(calificaciones);
                break;
            case 4: imprimir_alumno();
                break;
            case 5: pase_asistencia();
                break;
            case 6:
                break;
            default:
                break;
        }

    }
    return 0;
}

// Definición de la función
float promedio(float c[]){
    float prom;
    float acumulador = 0.0;
    for (int i = 0; i < MAX_CALIFICACIONES - 1; i++)
    {
        acumulador += c[i];
    }
    prom = acumulador / MAX_CALIFICACIONES - 1;
    prom = prom + c[MAX_CALIFICACIONES - 1] / 2;
    return prom;
}

float minimo(float c[]){
    float min = c[0];
    for (int i = 1; i < MAX_CALIFICACIONES; i++){
        if (min > c[i]){
            min = c[i];
        }
    }
    return min;
}

float maximo(float c[]){
    float max = c[0];
    for (int i = 1; i < MAX_CALIFICACIONES; i++){
        if (max < c[i]){
            max = c[i];
        }
    }
    return max;
}