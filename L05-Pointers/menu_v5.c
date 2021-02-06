#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
#define MAX_ASISTENCIA 5
#define MAX_CALIFICACIONES 4
#define MAX_NOMBRE 60
#define MAX_ALUMNOS 400

char mensaje[MAX] = "SCC";
//int matriculas[MAX_ALUMNOS] = {123456, 123789, 123567};
int *matriculas = NULL;
char nombres[MAX_ALUMNOS][MAX_NOMBRE] = {"Juan Carlos", "Karla", "Daniel"};
float calificaciones[MAX_ALUMNOS][MAX_CALIFICACIONES] = {{0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0} };
int asistencias[MAX_ALUMNOS][MAX_ASISTENCIA] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, };
bool estatus = true; //0 esta dado de baja caso si es 1 es que activo
//int asistencia = 1;
//int asistencias[5] = {1, 1, 1, 1, 1, 1};

//memoria dinamica
void inicializar_matriculas(int *m);


float promedio(float *c); //prototipo de una función
float minimo(float *c);
float maximo(float *c);
void imprimir_alumno();
void modificar_alumno();
void agregar_alumno();
void menu_modificacion_calificaciones(float c[][MAX_CALIFICACIONES]);
void imprimir_menu();
void inicializar_asistencia();
void imprimir_asistencias(const int posicion);
void pase_asistencia();
int posicion_alumno();

void inicializar_matriculas(int *m){
    m = (int *) malloc ( 3 * sizeof(int));
    if (m != NULL){
        m[0] = 123456;
        m[1] = 123789;
        m[2] = 123567;
    }
}

void inicializar_asistencia(){
    for (int filas = 0; filas < MAX_ALUMNOS; filas++){
        for (int columnas = 0; columnas < MAX_ASISTENCIA; columnas++){
            asistencias[filas][columnas] = 0;
        }
    }
}

void pase_asistencia(){
    int dia;
    printf("Pase de asistencia...\n");
    int posicion = posicion_alumno();
    printf("Indicar dia de asistencia [1 - %d]: ", MAX_ASISTENCIA);
    scanf("%d", &dia);
    printf("[0]=Falta o [1]=Asistencia: ");
    scanf("%d", &asistencias[posicion][dia - 1]);
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

void imprimir_asistencias(const int posicion){
    printf("Asistencias: ");
    for (int i = 0; i < MAX_ASISTENCIA-1; i++)
    {
        if (asistencias[posicion][i] == 1)
            printf("%s", "A, ");    
        else 
            printf("%s", "F, ");         
    }
    //if (asistencias[MAX_ASISTENCIA-1] == 1 ) printf("%s", "A"); else printf("%s", "F");
    (asistencias[posicion][MAX_ASISTENCIA-1] == 1)?printf("%s", "A"):printf("%s", "F");
    printf("\n");
}

void modificar_alumno(){
    puts("\tMenu para cambio de nombre...");
    int posicion = posicion_alumno();
    printf("El nombre del alumno es: %s\n", nombres[posicion]);
    printf("Ingresa el nuevo nombre: ");
    fflush(stdin);
    //scanf(" %s", nombre);
    //gets(nombre);
    fgets(nombres[posicion], 60, stdin);
}

void menu_modificacion_calificaciones(float c[][MAX_CALIFICACIONES]){
    int opt = 0;
    float r = 0.0;

    int posicion = posicion_alumno();

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
        case 1: printf("La calificación actual es: %f\n", c[posicion][0]);
                printf("Ingresa nueva calificación 1:");
                scanf("%f", &c[posicion][0]); 
            break;
        case 2: printf("La calificación actual es: %f\n", c[posicion][1]);
                printf("Ingresa nueva calificación 2:");
                scanf("%f", &c[posicion][1]);
            break;
        case 3: printf("La calificación actual es: %f\n", c[posicion][2]);
                printf("Ingresa nueva calificación 3:");
                scanf("%f", &c[posicion][2]);
            break;
        case 4: printf("La calificación actual es: %f\n", c[posicion][3]);
                printf("Ingresa nueva calificación f:");
                scanf("%f", &c[posicion][3]);
            break;
        
        default:
            break;
        }
    }
}

void imprimir_alumno(){
    
    int posicion = posicion_alumno();

    printf("Matrícula: %d\n", matriculas[posicion]);
    printf("Nombre del alumno: %s\n", nombres[posicion]);
    // printf("Calificación 1: %.2f\n", calificacion1); //8.3
    // printf("Calificación 2: %.2f\n", calificacion2); //7.1
    // printf("Calificación 3: %.2f\n", calificacion3); //6.1
    // printf("Calificación f: %.2f\n", calificacionf); //9.9
    printf("Calificación 1: %.2f\n", calificaciones[posicion][0]); //8.3
    printf("Calificación 2: %.2f\n", calificaciones[posicion][1]); //7.1
    printf("Calificación 3: %.2f\n", calificaciones[posicion][2]); //6.1
    printf("Calificación f: %.2f\n", calificaciones[posicion][3]); //9.9
    float prom = promedio(calificaciones[posicion]);
    printf("Promedio : %.2f\n", prom);
    float m;
    m = minimo(calificaciones[posicion]);
    printf("Calificación mínima: %.2f\n", m);
    m = maximo(calificaciones[posicion]);
    printf("Calificación máxima: %.2f\n", m);
    imprimir_asistencias(posicion);
    fflush(stdin);
    getchar();
}

void agregar_alumno(){
    int posicion = posicion_alumno();
    printf("Ingresa la matrícula:");
    scanf("%d", &matriculas[posicion]);
    fflush(stdin);
    printf("Ingresa el nombre del alumno:");
    //scanf(" %s", nombre);
    fgets(nombres[posicion], 60, stdin);
}

void imprimir_alumno_por_fila(int posicion){
    printf("%d\t\t%s\t", matriculas[posicion], nombres[posicion]);
    for (int i = 0; i < MAX_CALIFICACIONES; i++){
        printf("%.2f\t", calificaciones[posicion][i]);
    }
    printf("\n");
}

void imprimir_alumnos_en_tabla(){
    system("clear");
    printf("----------------------------------------------\n");
    printf("Matricula\tNombre\t 1er\t2o\t3er\t Ord\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < MAX_ALUMNOS; i++){
        if (matriculas[i] == 0){
            break;
        } else {
            imprimir_alumno_por_fila(i);
        }
    }
    puts("Presione una tecla para continuar...");
    fflush(stdin);
    getchar();
    //putchar();
}

void imprimir_menu(){
    char mensaje2[MAX] = "SISTEMA DE CONTROL DE CALIFICACIONES";
    // mensaje = mensaje2;
    // mensaje = "SISTEMA DE CONTROL DE CALIFICACIONES";
    strcpy(mensaje, mensaje2);
    //strncpy(mensaje, mensaje2, 12);
    //strlen() tamaño
    //strcat()  strncat()
    //strcmp()
    //strncmp
    system("clear");
    printf("----------------------------------------------\n");
    printf("%s\n", mensaje);
    printf("----------------------------------------------\n");
    printf("Menu de opciones\n");
    printf("----------------------------------------------\n");
    printf("1. Agregar alumno\n");
    printf("2. Modificar alumno\n");
    printf("3. Modificar calificaciones\n");
    printf("4. Imprimir datos del alumno\n");
    printf("5. Lista de alumnos\n");
    printf("6. Pase de lista\n");
    printf("7. Salir\n");
    printf("Ingresa una opción: \n");
}

int main () {
    inicializar_asistencia();
    inicializar_matriculas(matriculas);
    srand(time(0));
    int opcion;
    while (1) {
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
            case 5: imprimir_alumnos_en_tabla();
                break;
            case 6: pase_asistencia();
                break;
            case 7:
                return 0;
                break;
            default:
                break;
        }

    }
    return 0;
}

// Definición de la función
float promedio(float *c){
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

float minimo(float *c){
    float min = c[0];
    for (int i = 1; i < MAX_CALIFICACIONES; i++){
        if (min > c[i]){
            min = c[i];
        }
    }
    return min;
}

float maximo(float *c){
    float max = c[0];
    for (int i = 1; i < MAX_CALIFICACIONES; i++){
        if (max < c[i]){
            max = c[i];
        }
    }
    return max;
}

int posicion_alumno(){
    int posicion;
    printf("\nIngresa la posicion [1 -  %d]: ", MAX_ALUMNOS);
    scanf("%d", &posicion);
    posicion--;
    return posicion;
}