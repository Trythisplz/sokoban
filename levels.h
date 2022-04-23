#ifndef LEVELS_H
#define LEVELS_H
#include "button.h"
#include "main.h"

class levels
{
    public:
        levels(RenderWindow*,Font*);
        int choose_level(RenderWindow*);
        void draw_level(RenderWindow*);
        void level_won(int);
    protected:

    private:
        vector <button> level;
};

#endif // LEVELS_H
