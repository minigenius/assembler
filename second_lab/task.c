#include <stdio.h>
#include <stdlib.h>

/*
        Автор: Цырен Батуев, АПК-25
      Задание: Дано натуральное двузначное число (10 <= n <= 99), чему равна сумма его цифр?
    */

int main(){

    int number, result;
    printf("Введите двузначное число: ");
    scanf("%d", &number);

    if (number < 10 || number > 99) {
        printf("Ошибка: число не двузначное");
        exit(EXIT_FAILURE);
    }

    __asm__ volatile (

        ".intel_syntax noprefix\n\t"
        "mov eax, %1 \n\t"
        "mov edx,  0 \n\t"
        "mov ebx, 10 \n\t"

        "div ebx     \n\t"

        "add eax, edx\n\t"
        "mov %0, eax \n\t"
        ".att_syntax prefix\n\t"
        :"=&r" (result)
        :"r" (number)
        : "eax", "edx", "ebx"
    );

    printf("Сумма цифр двузначного числа: %d", result);
    return 0;
}
