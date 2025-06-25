#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 5
/*Идея проекта: Консольная игра "Угадай число"
Описание
Программа загадывает случайное число в заданном диапазоне (например, от 1 до 100), а пользователь пытается его угадать.
После каждой попытки программа подсказывает, больше или меньше загаданное число, чем введённое.
Игра продолжается, пока пользователь не угадает число.
В конце выводится количество попыток.

*  УГАДАЙ ЧИСЛО ОТ 1 ДО 100 *
*                           *
*                           *
*                           *
*****************************
 */
 void draw();
int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int random = rand() % 100 + 1;
    int a = 0;
    int flag = 0;
    draw();
    while (flag == 0){
        if (scanf("%d", &a) != 1) {
        printf("n/a");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        continue;
        }
        if (a > 100) {
            printf("ЧИСЛО БОЛЬШЕ СТА!");
        }
        else if (a == random) {
            printf("ВЫ УГАДАЛИ!!!");
            flag = 1;
        }
        else if (a < random) {
            printf("Неправильно, ваше число меньше загаданного!");
        }
        else if (a > random) {
            printf("Неправильно, ваше число больше загаданного!");
        }
    }
}

void draw() {
    //printf("33[H33[J");
    for (int i=0; i<HEIGHT; i++) {
        for (int j = 0; j < WIDTH - 1; j++) {
            if (j == 0 || j == WIDTH - 2) {
                printf("*");
            }
            if (i == HEIGHT - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
            if (j == 2 && i == 0) {
                printf("УГАДАЙ ЧИСЛО ОТ 1 ДО 100");
                j += 24;
            }
        }
        printf("\n");
    }
}


