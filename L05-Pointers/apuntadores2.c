#include <stdio.h>
#define MAX 4

int main(){
    int b[] = {10, 20, 30, 40};
    int *p_b;
    int a;

    p_b = b;

    puts("Arreglo usando indices");
    for (int i = 0; i < MAX; i++){
        printf("b[%d] = %d\n", i, b[i]);
    }
    
    puts("Arreglo usando el nombre del arreglo más indireccion");
    for (int i = 0; i < MAX; i++){
        printf("*(b + %d) = %d\n", i, *(b + i));
    }

    puts("Arreglo usando el apuntador más indice");
    for (int i = 0; i < MAX; i++){
        printf("p_b[%d] = %d\n", i, p_b[i]);
    }

    puts("Arreglo usando el apuntador más indireccion");
    for (int i = 0; i < MAX; i++){
        printf("*(p_b + %d) = %d\n", i, *(p_b + i));
    }

    return 0;
}