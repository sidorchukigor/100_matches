#ifndef HEADER_FILE
#define HEADER_FILE

int local_player(int matches);
int easy_ai(int matches);
int complex_ai(int matches);
int game(int (*player1)(int), int (*player2)(int));

#endif