#include <stdio.h>

int main(){
    FILE *cfPtr;  

    if ((cfPtr = fopen("alumnos.txt", "w")) == NULL){
        puts("No se pudo abrir el archivo");
    } else {
        puts("Ingresar matrícula, nombre del alumno");
        puts("Ingresa EOF (End of File) para terminar la captura");

        int matricula;
        char nombre[60];

        scanf("%d %59s", &matricula, nombre);
        while(!feof(stdin)){
            fprintf(cfPtr, "%d %s\n", matricula, nombre);
            printf("Igresar más datos: ");
            scanf("%d %59s", &matricula, nombre);
        }
        fclose(cfPtr);
    }
    return 0;
}