#include <stdio.h>

int main(){
    FILE *cfPtr;  

    if ((cfPtr = fopen("alumnos.txt", "r")) == NULL){
        puts("No se pudo abrir el archivo");
    } else {
        
        int matricula;
        char nombre[60];

        fscanf(cfPtr, "%d %s", &matricula, nombre);
        
        while(!feof(cfPtr)){
            printf("%d %s\n", matricula, nombre);
            fscanf(cfPtr, "%d %s", &matricula, nombre);
        }

        fclose(cfPtr);
    }
    return 0;
}