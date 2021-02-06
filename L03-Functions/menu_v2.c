#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100
#define MAX_ASISTENCIA 5

int matricula = 123456;
char inicial_nombre = 'A';
float calificacion1 = 9.0;
float calificacion2 = 8.9;
float calificacion3 = 7.9;
float calificacionf = 8.9;
int asistencias[MAX_ASISTENCIA] = {1, 1, 1, 1, 1};
bool estatus = true; //0 esta dado de baja caso si es 1 es que activo
//int asistencia = 1;
//int asistencias[5] = {1, 1, 1, 1, 1, 1};

float promedio(float c1, float c2, float c3, float cf); //prototipo de una función
float minimo(float c1, float c2, float c3, float cf);
float maximo(float c1, float c2, float c3, float cf);
void imprimir_alumno();
void agregar_alumno();
void menu_modificacion_calificaciones(float* c1, float* c2, float* c3, float* cf);
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

void menu_modificacion_calificaciones(float* c1, float* c2, float* c3, float* cf){
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
        case 1: printf("La calificación actual es: %f\n", *c1);
                printf("Ingresa nueva calificación 1:");
                scanf("%f", c1); 
            break;
        case 2: printf("La calificación actual es: %f\n", *c2);
                printf("Ingresa nueva calificación 2:");
                scanf("%f", c2);
            break;
        case 3: printf("La calificación actual es: %f\n", *c3);
                printf("Ingresa nueva calificación 3:");
                scanf("%f", c3);
            break;
        case 4: printf("La calificación actual es: %f\n", *cf);
                //printf("Ingresa nueva calificación f:");
                //scanf("%f", cf);
                //numero = rand () % (N-M+1) + M;   // Este está entre M y N // Entero
                
                r = (float) rand() / RAND_MAX; //casting
                *cf = 6.0 + r * (10.0 - 6.0); // Es un flotante entre M=6.0 y N= 10.0
            break;
        
        default:
            break;
        }
    }
}

void imprimir_alumno(){
    printf("Matrícula: %d\n", matricula);
    printf("Inicial del nombre: %c\n", inicial_nombre);
    printf("Calificación 1: %.2f\n", calificacion1); //8.3
    printf("Calificación 2: %.2f\n", calificacion2); //7.1
    printf("Calificación 3: %.2f\n", calificacion3); //6.1
    printf("Calificación f: %.2f\n", calificacionf); //9.9
    float prom = promedio(calificacion1, calificacion2, calificacion3, calificacionf);
    printf("Promedio : %.2f\n", prom);
    float m;
    m = minimo(calificacion1, calificacion2, calificacion3, calificacionf);
    printf("Calificación mínima: %.2f\n", m);
    m = maximo(calificacion1, calificacion2, calificacion3, calificacionf);
    printf("Calificación máxima: %.2f\n", m);
    imprimir_asistencias();
}

void agregar_alumno(){
    printf("Ingresa la matrícula:");
    scanf("%d", &matricula);
    //fflush(stdin);
    printf("Ingresa el inical del nombre del alumno:");
    scanf(" %c", &inicial_nombre);
    printf("Ingresa calificación 1:");
    scanf("%f", &calificacion1);
    printf("Ingresa calificación 2:");
    scanf("%f", &calificacion2);
    printf("Ingresa calificación 3:");
    scanf("%f", &calificacion3);
    printf("Ingresa calificación final:");
    scanf("%f", &calificacionf);
}

void imprimir_menu(){
    printf("Menu de opiones\n");
    printf("1. Agregar alumno\n");
    printf("2. Modificar calificaciones\n");
    printf("3. Imprimir datos del alumno\n");
    printf("4. Pase de lista\n");
    printf("5. Salir\n");
    printf("Ingresa una opción: \n");
}

int main () {
    inicializar_asistencia();
    srand(time(0));
    int opcion;
    while (opcion != 5) {
        imprimir_menu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: agregar_alumno();
                break;
            case 2: menu_modificacion_calificaciones(&calificacion1, &calificacion2, &calificacion3, &calificacionf);
                break;
            case 3: imprimir_alumno();
                break;
            case 4: pase_asistencia();
                break;
            case 5:
                break;
            default:
                break;
        }

    }
    return 0;
}

// Definición de la función
float promedio(float c1, float c2, float c3, float cf){
    int potencia = pow(2,3);
    float prom = (((c1 + c2 + c3) / 3) + (cf)) /2;
    return prom;
}

float minimo(float c1, float c2, float c3, float cf){
    float min = c1; 
    if (c1 > c2) { 
        min = c2; 
    }
    if (min > c3){ 
        min = c3; 
    }
    if (min > cf) { 
        min = cf;
    }
    return min;
}

float maximo(float c1, float c2, float c3, float cf){
    float max = c1; 
    if (c1 < c2) { 
        max = c2; 
    }
    if (max < c3){ 
        max = c3; 
    }
    if (max < cf) { 
        max = cf;
    }
    return max;
}