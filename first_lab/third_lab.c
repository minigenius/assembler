#include <stdio.h>

/*
        Автор: Батуев Цырен, АПК - 25
      Задание: Загрузить в регистр ECX значение 16-разрядной высокоуровневой переменной.
               Затем вывести это значение на экран,
               используя 32 разрядную высокоуровневую переменную.
    */

int main(){

    short in;
    int  out;
    printf("Введение значение: \n");
    scanf("%hd", &in);

    __asm__ volatile (

        ".intel_syntax noprefix\n\t"

        "movsx ecx, %1 \n\t"
        "mov    %0, ecx\n\t"

        ".att_syntax prefix\n\t"
        :"=&r" (out)
        :"r" (in)
        : "ecx"
    );

    printf("Значение: %d \n", out);
}
