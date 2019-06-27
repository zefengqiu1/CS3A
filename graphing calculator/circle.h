#ifndef CIRCLE_H
#define CIRCLE_H
#include "particle.h"

class Circle:public Particle
{
public:
    Circle(double x,double y);
    void Draw(sf::RenderWindow& window);
    void step(int command);
private:
    sf::CircleShape _circle;
    double _x;
    double _y;
};

#endif // CIRCLE_H
