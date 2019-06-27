#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include <sstream>
#include <fstream>
class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void savefile();
    void load();
    void loadbutton();
    bool invalidinput(string input);
    void savefunction();

private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                     //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar


    double moveleftright=10;
    double moveupdown=10;
    double defalut_size=125;
    double original_X=560;
    double original_y=400;
    bool _update=false;
    double _low=-500;
    double _high=500;
    bool _input=false;
    bool _polar=false;
    sf::RectangleShape _inputbox;
    sf::Text _fxstring;
    sf::String _expression;
    string _function;
    sf::Text _showfunction;



};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
