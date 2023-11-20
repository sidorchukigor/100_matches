#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

int local_player(int matches)
{
    int player_input;
    printf("Введите количество спичек, которое хотите взять:\n");
    while(1)
    {
        scanf("%d", &player_input);
        if(player_input <=10 && player_input > 0){
            return matches - player_input;
        } else {
            printf("Неверное количество спичек, введите от 1 до 10:\n");
        }
    }
}

int easy_ai(int matches)
{
    int ai_take;
    srand(time(NULL));
    if (matches <= 10 && matches > 1) {
        ai_take = matches - 1;
    } else if (matches == 1) {
        ai_take = matches;
    } else {
        ai_take = rand() % 10 + 1;
    }
    return matches - ai_take;
}

int complex_ai(int matches)
{
    int ai_take;
     if (matches % 11 != 0 && matches > 1) {
        ai_take = (matches % 11) - 1;
    } else if (matches == 1) {
        ai_take = matches;
    } else if (matches == 11) {
        ai_take = 10;
    } else {
        ai_take = rand() % 10 + 1;
    }
    return matches - ai_take;
}

int game(int (*player1)(int), int (*player2)(int))
{
    int matches = 100;
    int playerTurn = 0;
    while(matches > 0)
    {
        printf("\nКоличество спичек в куче: %d\n", matches);
        if(!playerTurn){
            printf("Ход первого игрока\n");
            matches = (*player1)(matches);
            playerTurn = 1;
        } else {
            printf("Ход второго игрока\n");
            matches = (*player2)(matches);
            playerTurn = 0; 
        }
    }
    return playerTurn;
}