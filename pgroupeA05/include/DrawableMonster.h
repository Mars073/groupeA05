#ifndef DRAWABLEMONSTER_H
#define DRAWABLEMONSTER_H

#include "Util/TexturesManager.h"
#include "Bestiary.h"

#include "string"
#include "SFML/Graphics.hpp"

class DrawableMonster
{
 public:
  DrawableMonster(std::string &Snom);
  DrawableMonster();
  virtual ~DrawableMonster();
  DrawableMonster(const DrawableMonster& other);
  DrawableMonster& operator=(const DrawableMonster& other);

  Monster* GetMs() { return ms; }
  void SetMs(Monster *val) { ms = val; }
  sf::Texture Gettext() { return text; }
  void Settext(sf::Texture val) { text = val; }
  string Getnom() { return nom; }
  void Setnom(string val) { nom = val; }
  void SetTexture(string nom);

  void SetSprite(sf::Texture val);
  sf::Sprite getSprite(){return sprite;}




 protected:

 private:
  TexturesManager *textureManager;
  Bestiary bs;
  Monster *ms;
  sf::Texture text;
  sf::Sprite sprite;
  string nom;
};

#endif // DRAWABLEMONSTER_H
