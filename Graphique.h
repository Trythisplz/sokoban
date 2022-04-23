#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//#include <stack>
#include "Menu.h"
//#include "main.h"
#include "button.h"
#include "levels.h"
using namespace std;
using namespace sf;
class Graphique
{
    public:
        Graphique();
        virtual ~Graphique();
        bool start();
        int buttonInput();
        void input(Event, RenderWindow * );
        //Sprite
        Image icon;
        Texture boy;
        Sprite sprite_boy;
        Texture girl;
        Sprite sprite_girl;
        Texture boy_2;
        Sprite sprite_boy_2;
        Texture girl_2;
        Sprite sprite_girl_2;
        Sprite sprite_player;
        Texture wall;
        Sprite sprite_wall;
        Texture box_win;
        Sprite sprite_box_win;
        Texture goal;
        Sprite sprite_goal;
        Texture box;
        Sprite sprite_box;
        Texture background;
        Sprite sprite_background;
        Texture Manual;
        Sprite sprite_Manual;

        //buttons
        button *undo_b;
        button *restart_b;
        button *exit_b;
        button *next;
        button *return_b;

        //audio
        Music music;

        //menu
        menu *Menu;
        levels *lvl;

        //font
        Font font;

        RenderWindow *window;
        enum Dir{Down,Left,Right,Up};
        Vector2i anim;

        bool choose_char();
        bool Manual_f();
        bool about_us();

};
