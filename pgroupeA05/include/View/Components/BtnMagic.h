#ifndef BTNMAGIC_H
#define BTNMAGIC_H

#include <View/Components/BtnWin.h>
#include "Model/Magic.h"


class BtnMagic : public BtnWin
{
 public:
  BtnMagic(int positionX =0,int positionY = 0,int tailleX =0,int tailleY=0,std::string textButton="");
  virtual ~BtnMagic();
  BtnMagic(const BtnMagic& other);
  BtnMagic& operator=(const BtnMagic& other);

  Magic* Getmagic() { return magic; }
  void Setmagic(Magic* val) { magic = val; }
  BtnMagic* Clone();
  void action();
  std::string getDescription()const;

 protected:

 private:
  Magic* magic;
};

#endif // BTNMAGIC_H
