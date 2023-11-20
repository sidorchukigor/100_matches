#include <stdio.h>
#include "lib.h"

int main()
{
    int menuState = 6;
    int lastGameWinner = 0;
    int lastGameMode = 1;
    while (1) {
        switch (menuState) {
        case 1:
            printf("\nИгра против Локального игрока\n");
            lastGameWinner = game(local_player, local_player);
            lastGameMode = menuState;
            menuState = 7;
            break;
        case 2:
            printf("\nИгра против Лёгкого ИИ (ИИ - игрок 2)\n");
            lastGameWinner = game(local_player, easy_ai);
            lastGameMode = menuState;
            menuState = 7;
            break;
        case 3:
            printf("\nИгра против Сложного ИИ (ИИ - игрок 2)\n");
            lastGameWinner = game(local_player, complex_ai);
            lastGameMode = menuState;
            menuState = 7;
            break;
        case 4:
            printf("Выход...");
            return 0;
        case 5:
            menuState = lastGameMode;
            break;
        case 6:
            printf("\nИгра '100 спичек'\n");
            printf("Правила игры: Из кучки, первоначально содержащей 100 "
                   "спичек, двое "
                   "играющих поочередно берут по несколько спичек: не менее "
                   "одной и не "
                   "более десяти. Проигрывает взявший последнюю спичку.\n");
            printf("\nВыберите режим игры:\n1 - Против локального игрока\n2 - "
                   "Против "
                   "Лёгкого ИИ\n3 - Против Сложного ИИ\n4 - Выйти из игры\n");
            scanf("%d", &menuState);
            break;
        case 7:
            if (lastGameWinner == 0) {
                printf("\n%s  Победил игрок 1", "🏆");
            } else if (lastGameWinner == 1) {
                printf("\n%s  Победил игрок 2", "🏆");
            } else {
                printf("\nВо время игры произошла непредвиденная ошибка\n");
                return -1;
            }
            printf("\nВведите:\n5 - Чтобы повторить игру\n6 - Чтобы выйти в "
                   "меню\n");
            scanf("%d", &menuState);
            break;
        default:
            printf("Неизвестная команда, введите ещё раз\n");
            scanf("%d", &menuState);
            break;
        }
    }
}