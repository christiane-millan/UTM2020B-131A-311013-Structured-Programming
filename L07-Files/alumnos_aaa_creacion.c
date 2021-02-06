#include <stdio.h>

struct estudiant_{
    int id;
    int matricula;
    char name[60];
    float calificaciones[4];
    int asistencias[5];
};

typedef struct estudiant_ estudiante;

int main(){
    FILE *cfPtr;

    if((cfPtr = fopen("estudiantes.dat", "wb")) == NULL){
        puts("No se pudo abrir el archivo...\n");
    } else {
        estudiante estudiante_blanco = {0, 0, "", {0.0}, {-1}};

        for (int i = 0; i < 100; i++){
            fwrite(&estudiante_blanco, sizeof(estudiante), 1, cfPtr);
        }
        
        fclose(cfPtr);
    }

    return 0;
}