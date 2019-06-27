#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate():sidebar(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    system = System();
    window.setFramerateLimit(60);

//    mouseIn = true;

//    mousePoint = sf::CircleShape();
//    mousePoint.setRadius(10.0);
//    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));


    _fxstring=sf::Text("f(x)=",font,38);
    _fxstring.setPosition(75,75);
    _fxstring.setColor(sf::Color::Green);
    _fxstring.setStyle(sf::Text::Regular);

    _showfunction=sf::Text(_expression,font,38);
    _showfunction.setPosition(175,75);
    _showfunction.setColor(sf::Color::Green);
    _showfunction.setStyle(sf::Text::Regular);


    _inputbox.setSize(sf::Vector2f(800,100));
    _inputbox.setOutlineThickness(2);
    _inputbox.setFillColor(sf::Color::Black);
    _inputbox.setOutlineColor(sf::Color::Green);
    _inputbox.setPosition(sf::Vector2f(156,46));
    _input=false;

    load();
    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }
    if(_input)
    {
        window.draw(_inputbox);
        window.draw(_fxstring);
        window.draw(_showfunction);
    }
    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){
    //cause changes to the data for the next frame
    if(_update)
    {
        if(!_function.empty())
        {
            system.Step(_function,original_X,original_y,_low,_high,_polar,defalut_size);
            _update=false;
        }

    }
}

void animate::render(){
       window.clear();
       Draw();

       window.display();


}

void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
         moveleftright=5/(((abs(_high)+abs(_low)))/1000);
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;
           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Left:
                    sidebar[0]="Move Left";
                       original_X+=moveleftright;
                       _low-=5;
                       _high-=5;
                       _update=true;
                   break;
               case sf::Keyboard::Right:

                        sidebar[0]="Move Right";
                       original_X-=moveleftright;
                       _low+=5;
                       _high+=5;
                       _update=true;

                   break;
               case sf::Keyboard::Up:
                        sidebar[0]="Move up";
                       original_y+=moveupdown;
                       _update=true;

                  break;
              case sf::Keyboard::Down:
                    sidebar[0]="Move Down";
                       original_y-=moveupdown;
                       _update=true;
                  break;
               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;
               case sf::Keyboard::Q:
                    sidebar[0]="Zoom in";
                       _low/=1.1;
                       _high/=1.1;
                       _update=true;
                   break;
               case sf::Keyboard::E:
                    sidebar[0]="Zoom out";

                    _low*=1.1;
                    _high*=1.1;
                    _update=true;

                   break;
               case sf::Keyboard::R:
                   sidebar[0]="Reset";
                   if(!_polar)
                   {
                       _low=-500;
                       _high=500;
                       original_X=560;
                       original_y=400;
                       defalut_size=125;
                   }else
                   {
                       _low=-180;
                       _high=180;
                       original_X=560;
                       original_y=400;
                       defalut_size=125;
                   }

                         _update=true;
                   break;
               case sf::Keyboard::Tab:

                       if(_polar)
                       {
                            sidebar[0]="";
                           _polar=false;
                           _low=-20;
                           _high=20;
                       }else
                       {
                            sidebar[0]="Polar";
                           _polar=true;
                           _low=-180;
                           _high=180;
                       }
                      _update=true;
                   break;
               case sf::Keyboard::Enter:
                   try {
                   if(_input)
                   {
                       if(invalidinput(_expression))
                       {
                           cout<<"Invalid "<<endl;;

                           sidebar[0]="Invalid Input";
                           _expression.clear();
                           _input=false;

                       }else
                       {
                           cout<<"valid"<<endl;

                           _function=_expression;
                           sidebar[0]="f(x)="+_function;
                            _expression.clear();
                           _input=false;
                           _update=true;

                       }

                   }else
                   {
                       _input=true;
                        _expression.clear();
                   }
               } catch (...) {
                    sidebar[0]="Invalid Input";
                    _expression.clear();
                    _input=false;

               }

               }
               break;
            case sf::Event::TextEntered:
              if(_input)
              {
                  if (event.text.unicode>=32 && event.text.unicode<127) {

                     _expression+=static_cast<char>(event.text.unicode);

                  }else if(event.text.unicode==8 && _expression.getSize()>0)
                  {
                     _expression.erase(_expression.getSize()-1,_expression.getSize());
                  }
                   _showfunction.setString(_expression);
                  break;
              }

            break;
           case sf::Event::MouseButtonPressed:
               if(event.mouseButton.button==sf::Mouse::Right)
               {
                   cout<<"mouse x:"<<event.mouseButton.x<<endl;
                    cout<<"mouse y:"<<event.mouseButton.y<<endl;
                   //cout<<"the right button was pressed"<<endl;
                    savefunction();
                    savefile();

               }
               if(event.mouseButton.button==sf::Mouse::Left)
               {
                   cout<<"mouse x:"<<event.mouseButton.x<<endl;
                    cout<<"mouse y:"<<event.mouseButton.y<<endl;
                    loadbutton();
                     sidebar[0]="f(x)="+_function;
                   //cout<<"the left button was pressed"<<endl;
               }
               break;
           }

       }
}

void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}


void animate::savefile()
{
    ofstream outfile;
    outfile.open("functions.txt");
    for(int i=1;i<18;i++)
    {
        if(!sidebar[i].empty())
        {
            outfile<<sidebar[i]<<endl;
        }
    }

    outfile.close();
}

void animate::load()
{
    ifstream infile;
    string function;
    int line=1;
    infile.open("functions.txt");
    while(infile)
    {
        getline(infile,function);
        sidebar[line]=function;
        line++;
    }
    infile.close();
}

void animate::loadbutton()
{
    if(sf::Mouse::getPosition(window).x>=1124 && sf::Mouse::getPosition(window).x<=1392&&
           sf::Mouse::getPosition(window).y>=68 && sf::Mouse::getPosition(window).y<=94 )
    {
        if(!sidebar[1].empty()&&!_input)
        {
            _function=sidebar[1];
            _update=true;

        }
    }

    if(sf::Mouse::getPosition(window).x>=1124 && sf::Mouse::getPosition(window).x<=1392&&
           sf::Mouse::getPosition(window).y>=108 && sf::Mouse::getPosition(window).y<=140 )
    {
        if(!sidebar[2].empty()&&!_input)
        {
            _function=sidebar[2];
            _update=true;

        }
    }

    if(sf::Mouse::getPosition(window).x>=1124 && sf::Mouse::getPosition(window).x<=1392&&
           sf::Mouse::getPosition(window).y>=156 && sf::Mouse::getPosition(window).y<=186 )
    {
        if(!sidebar[3].empty()&&!_input)
        {
            _function=sidebar[3];
            _update=true;

        }
    }

}

bool animate::invalidinput(string expression)
{
    cout<<expression.length()<<endl;
      cout<<expression<<endl;
      string tri;
      if(expression=="")
          throw "Invalid Input";
          //return true;
      for(int i=0;i<expression.length();i++)
      {
          if(isupper(expression[i]))
          {
               throw "Invalid Input";
              //return true;
          }
      }

      for(int i=0;i<expression.length();i++)
      {

          if(!isalpha(expression[i])&&
                  !isnumber(expression[i])&&
                  expression[i]!='+'&&
                  expression[i]!='-'&&
                  expression[i]!='*'&&
                  expression[i]!='/'&&
                  expression[i]!='^'&&
                  expression[i]!='('&&
                  expression[i]!=')'&&
                   expression[i]!='.'
                  )
               throw "Invalid Input";
          //return true;

      }

      Stack<char> parencheck;
      for(int i=0;i<expression.length();i++)
      {
          switch (expression[i]) {
              case'(':
                  parencheck.push('(');
              break;
              case')':
                  parencheck.pop();
              break;
          }
      }

      if(!parencheck.empty())
      {
          throw "Invalid Input";
          // return true;
      }

       for(int i=0;i<expression.length();i++)
       {
           if(isalpha(expression[i])&& expression[i]!='x')
           {
               tri+=expression[i];
           }else if(!tri.empty() && !isalpha(expression[i]))
           {
               if(tri=="sin"||tri=="cos"||tri=="tan"||tri=="csc"||tri=="cot"||tri=="sec"||tri=="pi")
               {
                   tri.clear();
               }else
                   throw "Invalid Input";
           }
       }

       if(!tri.empty())
       {
            throw "Invalid Input";
           //return true;
       }

      return false;
}
void animate::savefunction()
{
    if(sf::Mouse::getPosition(window).x>=1124 && sf::Mouse::getPosition(window).x<=1392&&
           sf::Mouse::getPosition(window).y>=68 && sf::Mouse::getPosition(window).y<=94 )
    {
        if(!_input)
        {
            sidebar[1]=_function;
            _update=true;

        }
    }

    if(sf::Mouse::getPosition(window).x>=1124 && sf::Mouse::getPosition(window).x<=1392&&
           sf::Mouse::getPosition(window).y>=108 && sf::Mouse::getPosition(window).y<=140 )
    {
        if(!_input)
        {
            sidebar[2]=_function;
            _update=true;

        }
    }

    if(sf::Mouse::getPosition(window).x>=1124 && sf::Mouse::getPosition(window).x<=1392&&
           sf::Mouse::getPosition(window).y>=156 && sf::Mouse::getPosition(window).y<=186 )
    {
        if(!_input)
        {
            sidebar[3]=_function;
            _update=true;

        }
    }
}
