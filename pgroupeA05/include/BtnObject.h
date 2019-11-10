#ifndef BTNOBJECT_H
#define BTNOBJECT_H

#include <BtnWin.h>


class BtnObject : public BtnWin
{
 public:
  BtnObject(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
  void setItem(Item *Item);
  virtual ~BtnObject();
  BtnObject(const BtnObject& other);
  BtnObject& operator=(const BtnObject& other);
  void action();
  std::string getDescription();


 protected:

 private:
  Item *item;
};

#endif // BTNOBJECT_H
