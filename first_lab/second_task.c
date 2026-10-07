#include <stdio.h>

/*
        Автор: Цырен Батуев, АПК-25
        Задание: Поместить в регистры AH, BX, EDX значения высокоуровневых перменных, заданные из консоли.
                 Вывести на экран эти значения, используя другие высокоуровневые переменные.
    */

int main(){
    int in1, in2, in3, out1, out2, out3;
    printf("Введите числа a,b,c: ");
    scanf("%d%d%d", &in1, &in2, &in3);

    __asm__ volatile(
        ".intel_syntax noprefix\n\t"

        "mov ecx,  %3 \n\t"
        "mov  ah,  cl \n\t"
        "mov ecx,  %4 \n\t"
        "mov  bx,  cx \n\t"
        "mov edx,  %5 \n\t"

        "movzx %0, ah \n\t"
        "movzx %1, bx \n\t"
        "mov   %2, edx \n\t"

        ".att_syntax prefix\n\t"
        :"=&r" (out1), "=&r" (out2), "=&r" (out3)
        : "r" (in1), "r" (in2), "r" (in3)
        : "eax", "ebx", "edx", "ecx"

    );

    printf("AH = %d, BX = %d, EDX = %d \n", out1, out2, out3);
}
