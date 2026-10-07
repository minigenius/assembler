#include <stdio.h>
/*
        Автор: Батуев Цырен, АПК-25
        Задание: Записать в регистр Al значение 0xAB, результат вывести, используя высокоуровневую переменную
    */
int main(){
    int result;
    __asm__ volatile (
        ".intel_syntax noprefix\n\t"
        "mov al, 0xAB\n\t"
        "movzx %0, al\n\t"
        ".att_syntax prefix\n\t"
        :"=r" (result)
        :
        : "eax"
    );

    printf("Значение, которое было записано в регистр AL: %d \n", result);

}
