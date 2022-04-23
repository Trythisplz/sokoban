#include "Graphique.h"
#include <fstream>
#include <stack>
const float win_w=800;
const float win_h=870;
const float button_w=130;
const float button_h=60;
const float decalage=70;
const float placement=((win_w-button_w)/2);
Graphique::Graphique()
{
	window = new RenderWindow(VideoMode(win_w, win_h), "Sokoban");
	icon.loadFromFile("res/icon.jpeg");
	window->setIcon(50,50, icon.getPixelsPtr());
	window->setFramerateLimit(60);

    if(!font.loadFromFile("res/nasalization.otf"))
        cout<<"erreur chargement font"<<endl;
    Menu = new menu(window,&this->font);

    lvl= new levels(window,&font);

	undo_b = new button ( 2*placement-decalage,win_h-button_h-50,button_w,button_h,30,&font,"Undo",Color(255,135,255));
	restart_b = new button ( placement,win_h-button_h-50,button_w,button_h,30,&font,"Restart",Color(290,160,221));
	exit_b = new button ( decalage,win_h-button_h-50,button_w,button_h,30,&font,"Exit",Color(221,160,171));

	next= new button (2*placement-decalage,win_h-button_h-50,button_w+30,button_h,30,&font,"Next Level",Color(221,100,221));
	return_b = new button ( placement,win_h-button_h-50,button_w,button_h,30,&font,"Return",Color(221,260,221));

	//setSprite
    if(!girl.loadFromFile("res/girl.png"))
        cout<<"prob"<<endl;
     girl.setSmooth(true);
    sprite_girl.setTexture(girl);

    if(!boy.loadFromFile("res/boy.png"))
        cout<<"prob"<<endl;
    boy.setSmooth(true);
    sprite_boy.setTexture(boy);
    sprite_player.setTexture(boy);

     if(!girl_2.loadFromFile("res/girl2.png"))
        cout<<"prob"<<endl;
     girl_2.setSmooth(true);
    sprite_girl_2.setTexture(girl_2);

    if(!boy_2.loadFromFile("res/boy2.png"))
        cout<<"prob"<<endl;
     boy_2.setSmooth(true);
    sprite_boy_2.setTexture(boy_2);

    if(!box.loadFromFile("res/box.jpg"))
        cout<<"prob"<<endl;
    sprite_box.setTexture(box);

    if(!box_win.loadFromFile("res/box_win.jpg"))
        cout<<"prob"<<endl;
    sprite_box_win.setTexture(box_win);

    if(!goal.loadFromFile("res/goal.jpg"))
        cout<<"prob"<<endl;
    sprite_goal.setTexture(goal);

    if(!wall.loadFromFile("res/wall.png"))
        cout<<"prob"<<endl;
    sprite_wall.setTexture(wall);

    if(!background.loadFromFile("res/background.jpg"))
        cout<<"prob"<<endl;
    sprite_background.setTexture(background);

     if(!Manual.loadFromFile("res/manual.jpeg"))
        cout<<"prob"<<endl;
    sprite_Manual.setTexture(Manual);
}
Graphique::~Graphique()
{
    delete window;
    delete Menu;
    delete lvl;
    delete undo_b;
    delete restart_b;
    delete exit_b;
    delete next;
    delete return_b;
}

void Graphique::input(Event event, RenderWindow *window)
{
    if (event.type==Event::Closed)
           window->close();

    if ( event.key.code==Keyboard::Escape)
        window->close();
}
int Graphique::buttonInput()
{
    float tx,ty;
    tx=Mouse::getPosition(*window).x;
    ty=Mouse::getPosition(*window).y;

    restart_b->update(tx,ty);
    if(restart_b->ispressed())
        return 1;

    undo_b->update(tx,ty);
    if (undo_b->ispressed())
        return 2;

    exit_b->update(tx,ty);
    if (exit_b->ispressed())
        return 3;
    return 0;
}

bool Graphique::about_us()
{
    window->clear();
    Text text;
    text.setCharacterSize(30);
    text.setColor(Color::Black);
    text.setFont(font);
    text.setString("this page is under construction");
    window->draw(sprite_background);
    window->draw(text);
    return_b->render(window);
    window->display();
       while (window->isOpen())
       {
           Event event;
            while (window->pollEvent(event))
            {
                float x1,y1;
                x1=Mouse::getPosition(*window).x;
                y1=Mouse::getPosition(*window).y;
                return_b->update(x1,y1);
                if(return_b->ispressed())
                    return start();
            }
         input(event,window);
        }
}
bool Graphique::Manual_f()
{
   window->clear();
   window->draw(sprite_Manual);
   return_b->render(window);
   window->display();
   while (window->isOpen())
       {
           Event event;
           input(event,window);
            while (window->pollEvent(event))
            {
                float x1,y1;
                x1=Mouse::getPosition(*window).x;
                y1=Mouse::getPosition(*window).y;
                return_b->update(x1,y1);
                if(return_b->ispressed())
                    return start();
            }
        }
}
bool Graphique::choose_char()
{
    const int spacing=100;
    const int x=spacing*2+320;
    window->clear();
    window->draw(sprite_background);
    sprite_box.setPosition(spacing,(win_h-button_h)/2);
    window->draw(sprite_box);
    sprite_boy.setPosition(spacing,(win_h-button_h)/2);
    sprite_boy.setScale(2.5,2.5);
    sprite_girl_2.setPosition((win_w-x)*2/3+spacing+160,(win_h-button_h)/2);
    sprite_girl_2.setScale(2.5,2.5);
    sprite_boy_2.setPosition((win_w-x)/3+spacing+80,(win_h-button_h)/2);
    sprite_boy_2.setScale(2.5,2.5);
    sprite_girl.setPosition((win_w-x)+spacing+240,(win_h-button_h)/2);
    sprite_girl.setScale(2.5,2.5);
    sprite_boy.setTextureRect(IntRect(32,0,32,32));
    sprite_girl.setTextureRect(IntRect(32,0,32,32));
    sprite_boy_2.setTextureRect(IntRect(32,0,32,32));
    sprite_girl_2.setTextureRect(IntRect(32,0,32,32));
    window->draw(sprite_boy);
    window->draw(sprite_girl);
    window->draw(sprite_boy_2);
    window->draw(sprite_girl_2);
    return_b->render(window);
    window->display();
    while (window->isOpen())
       {
            Event event;
            input(event, window);
            while (window->pollEvent(event))
            {
                float x1,y1;
                x1=Mouse::getPosition(*window).x;
                y1=Mouse::getPosition(*window).y;
                return_b->update(x1,y1);
                if(return_b->ispressed())
                    return start();
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    window->clear();
                    if(sprite_boy.getGlobalBounds().contains(x1,y1))
                        {
                            sprite_player.setTexture(boy);
                            sprite_box.setPosition(150,(win_h-button_h)/2);
                           }
                   else if(sprite_girl.getGlobalBounds().contains(x1,y1))
                        {sprite_player.setTexture(girl);
                        sprite_box.setPosition(450,(win_h-button_h)/2);}
                   else if(sprite_boy_2.getGlobalBounds().contains(x1,y1))
                        {sprite_player.setTexture(boy_2);
                        sprite_box.setPosition(300,(win_h-button_h)/2);}
                   else if(sprite_girl_2.getGlobalBounds().contains(x1,y1))
                        {sprite_player.setTexture(girl_2);
                        sprite_box.setPosition(600,(win_h-button_h)/2);}

                window->draw(sprite_background);
                window->draw(sprite_box);
                window->draw(sprite_boy);
                window->draw(sprite_girl);
                window->draw(sprite_boy_2);
                window->draw(sprite_girl_2);
                return_b->render(window);
                window->display();}
            }
       }
}
bool Graphique::start()
{
    window->draw(sprite_background);
    Menu->draw_menu(window);
    window->display();
    Event event;
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            float tx,ty;
            tx=Mouse::getPosition(*window).x;
            ty=Mouse::getPosition(*window).y;
            Menu->update_menu(tx,ty);
            if (Menu->play->ispressed())
                return true;
            if(Menu->choose_char->ispressed())
                return choose_char();
            if(Menu->manual->ispressed())
                return Manual_f();
            if(Menu->about->ispressed())
                return about_us();
        }
        input(event, window);
    }
}
