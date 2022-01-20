//
//  main.cpp
//  SfmlPractice
//
//  Created by Polina Lyubavina on 9/20/21.
//

#include <iostream>

#include <SFML/Graphics.hpp>

#include <math.h>
    
using namespace sf;

int main()
{
  // Create the main program window.
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  // Create a shape to draw
    sf::CircleShape myCircle(50.f);

  myCircle.setFillColor(sf::Color(255, 255, 255)); // set the shape color to green

  float angle = 0.0;

  // Run the program as long as the main window is open.
  while (window.isOpen())
    {
      // Check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
      while (window.pollEvent(event))
        {
          // "close requested" event: we close the window
          if (event.type == sf::Event::Closed) {
            window.close();
          }
        }

      // clear the window with black color
      window.clear(sf::Color::Black);

      int x = 100 + cos( angle ) * 100;
      int y = 100 + sin( angle ) * 100;
      angle += 0.001;

      myCircle.setPosition( x, y );
      
      window.draw( myCircle );
      // end the current frame
      window.display();
    }

  return 0;
}

