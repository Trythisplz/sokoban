#ifndef GAME_H
#define GAME_H
#include "Graphique.h"
#include "Console.h"
#include "levels.h"
class Game
{
    public:
        Game(){};
        void Game_start();

    private:
        Console Cgame;
        Graphique Ggame;
        void printmap();
        void move_char(Event,string);
        void restart_f(string);
        void level_menu(); //mechekel
        void win_f(int);
        void play(short int);
        bool lose();
};

#endif // GAME_H
