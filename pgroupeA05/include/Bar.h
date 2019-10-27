#ifndef BAR_H
#define BAR_H
#include <SFML/Graphics.hpp>
#include <ostream>
#include "string"

class Bar
{
 public:
  Bar();
  Bar(int posX,int posY,int sizeX,int sizeY);
  virtual ~Bar();
  Bar(const Bar& other);
  Bar& operator=(const Bar& other);

  int GetposX() { return posX; }
  void SetposX(int val) { posX = val; }
  int GetposY() { return posY; }
  void SetposY(int val) { posY = val; }
  int GetsizeX() { return sizeX; }
  void SetsizeX(int val) { sizeX = val; }
  int GetsizeY() { return sizeY; }
  void SetsizeY(int val) { sizeY = val; }
  sf::Color Getcolor() { return color; }
  void Setcolor(sf::Color val);
  void setBarLifeTaille(float current,float maxx);
  sf::RectangleShape getRect()const;
  sf::RectangleShape getFond()const;


 protected:

 private:
  int posX;
  int posY;
  int sizeX;
  int sizeY;
  float current;
  sf::Color color;
  sf::RectangleShape rect;
  sf::RectangleShape fond;
};

#endif // BAR_H
