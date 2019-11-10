#ifndef BTNMAGIC_H
#define BTNMAGIC_H

#include <BtnWin.h>
#include "Magic.h"


class BtnMagic : public BtnWin
{
 public:
  BtnMagic(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
  virtual ~BtnMagic();
  BtnMagic(const BtnMagic& other);
  BtnMagic& operator=(const BtnMagic& other);

  Magic* Getmagic() { return magic; }
  void Setmagic(Magic* val) { magic = val; }

  void action();
  std::string getDescription();

 protected:

 private:
  Magic* magic;
};

#endif // BTNMAGIC_H
