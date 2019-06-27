#include "circle.h"

Circle::Circle(double x,double y)
{
    _x=x;
    _y=y;
   // double xpos = SCREEN_WIDTH*4/5/2+_x;
    //double ypos = 400-_y;
    //center y400 x 560
    //Random r;
   // int xpos = r.Next(0,500);
   // int ypos = r.Next(0,500);
    _circle = sf::CircleShape(2);
    _circle.setPosition(sf::Vector2f(_x, _y));
    _circle.setFillColor(sf::Color::Red);//sf::Color(r_, g_, b_)
}

void Circle::step(int command)
{
//    _circle.move(vel);
//    _circle.rotate(1);
//    sf::Vector2f pos = _circle.getPosition();
//    if ((pos.x)>=WORK_PANEL-20)
//        vel = sf::Vector2f(-1*vel.x,1*vel.y);
//    if (pos.x<=0)
//        vel = sf::Vector2f(-1*vel.x,1*vel.y);
//    if ((pos.y)>=SCREEN_HEIGHT-20)
//        vel = sf::Vector2f(1*vel.x,-1*vel.y);
//    if (pos.y<=0)
//        vel = sf::Vector2f(1*vel.x,-1*vel.y);
}
void Circle::Draw(sf::RenderWindow& window)
{
    window.draw(_circle);
}
