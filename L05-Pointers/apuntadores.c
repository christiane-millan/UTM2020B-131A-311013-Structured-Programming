#include <stdio.h>

int main(void){
    int count = 5;
    //declaración
    int *p_count;

    //incializar el apuntador
    p_count = &count;

    //acceso de manera directa
    printf("count: %d\n", count);
    //acceso de manera indirecta
    printf("p_count %d\n", *p_count);

    printf("La dirección de count: %p\n",&count);
    printf("La dirección de p_count: %p\n",&p_count);
    printf("La dirección almacenada de p_count %p\n", p_count);

    printf("Ejemplo de * y & %p\n", &*p_count);
    printf("Ejemplo de * y & %p\n", *&p_count);
    return 0;
}