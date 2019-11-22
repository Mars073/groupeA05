#include <View/Scenes/WindowStatus.h>

WindowStatus::WindowStatus()
{
    this->rectAll.setPosition(sf::Vector2f(50,50));
    this->rectAll.setSize(sf::Vector2f(500,400));
    this->rectAll.setOutlineThickness(5);
    this->rectAll.setOutlineColor(sf::Color(0,0,0));
    this->rectAll.setFillColor(sf::Color(75,52,251));

    this->rectMenu.setPosition(sf::Vector2f(60,60));
    this->rectMenu.setSize(sf::Vector2f(160,380));
    this->rectMenu.setOutlineThickness(5);
    this->rectMenu.setOutlineColor(sf::Color(255,255,255));
    this->rectMenu.setFillColor(sf::Color(253,67,0));

    this->p=SingletonGame::getInstance()->getPlayerPTR();

    this->choiceMenu=0;

    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="Weapon"){
            equipments.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }
    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="Armor"){
            equipments.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }

    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="Heal"){
            items.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }

    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="HealMp"){
            items.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }

}

WindowStatus::~WindowStatus()
{

    for (unsigned i = 0; i < equipments.size(); i++)
    {
        delete equipments.at(i);
    }

    for (unsigned i = 0; i < items.size(); i++)
    {
        delete items.at(i);
    }

}

WindowStatus::WindowStatus(const WindowStatus& other)
{
    this->rectAll=other.rectAll;

    this->rectMenu=other.rectMenu;

    this->p=other.p;

    this->choiceMenu=other.choiceMenu;

    this->equipments=other.equipments;

    this->items=other.items;
}

WindowStatus& WindowStatus::operator=(const WindowStatus& rhs)
{
    if (this != &rhs){
        this->rectAll=rhs.rectAll;

        this->rectMenu=rhs.rectMenu;

        this->p=rhs.p;

        this->choiceMenu=rhs.choiceMenu;

        for (unsigned i = 0; i < equipments.size(); i++)
        {
            delete equipments.at(i);
        }
        this->equipments=rhs.equipments;

        for (unsigned i = 0; i < items.size(); i++)
        {
            delete items.at(i);
        }
        this->items=rhs.items;
    }
    //assignment operator
    return *this;
}

void WindowStatus::draw(RenderTarget& target, RenderStates states) const
{
    target.setView(View(FloatRect(0, 0, SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT))); // HOT FIX
    Sprite sprite;
    Texture t = *TexturesManager::getInstance()->get("status");
    sprite.setTexture(t);
    target.draw(sprite, states);
    target.draw(rectAll, states);
    target.draw(rectMenu, states);
    Font f = *FontsManager::getInstance()->get("arial");
    for (int i = 0; i < MENU_LENGTH; i++)
    {
        Text text(i==selected_id?"> "+menu[i]:menu[i], f);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);
        text.setPosition(70, 70 + i*42);
        target.draw(text, states);
    }

    if(choiceMenu==0){
        Text textStatus(p->str(), f);
        textStatus.setCharacterSize(15);
        textStatus.setFillColor(sf::Color::Black);
        textStatus.setPosition(250, 60);
        target.draw(textStatus, states);
    }
    else if(choiceMenu==1){
        int nb1=0,nb2=8;

        for(unsigned i=0;i< ceil(((float)equipments.size()/8)) ;i++){
            if(nb2>equipments.size()){
                nb2=equipments.size();
            }
            if(selected_id_menu>=nb1&&selected_id_menu<nb2){
                drawItems(target,states,nb1,nb2,equipments,"Weapon","Armor","Weapons : ","Armors : ",selected_id_menu);
            }
            nb1+=8;
            nb2+=8;
        }
    }
    else if(choiceMenu==2){
        int nb1=0,nb2=8;

        for(unsigned i=0;i< ceil(((float)items.size()/8)) ;i++){
            if(nb2>items.size()){
                nb2=items.size();
            }
            if(selected_id_items>=nb1&&selected_id_items<nb2){
                drawItems(target,states,nb1,nb2,items,"Heal","HealMp","Heal hp : ","Heal mp : ",selected_id_items);
            }
            nb1+=8;
            nb2+=8;
        }
    }
}

void WindowStatus::drawItems(RenderTarget& target, RenderStates states,int nb1,int nb2,std::vector<Item*>listofItem,std::string type1,std::string type2,std::string type1Desc,std::string type2Desc,short int id) const{
    Font f = *FontsManager::getInstance()->get("arial");
    int menuItem=0;
    bool isType2=false;
    bool isType1=false;
    bool checkNextSpace=false;

    for (int i = nb1; i < nb2; i++)
    {
        if(listofItem.at(i)->GetitemType()==type1 && !isType1){
            isType1=true;
            Text textType1(type1Desc, f);
            textType1.setCharacterSize(15);
            textType1.setFillColor(sf::Color::Black);
            textType1.setPosition(250, 50);
            target.draw(textType1, states);
        }
        if(listofItem.at(i)->GetitemType()==type2 && !isType2){
            isType2=true;
            Text textType2(type2Desc, f);
            textType2.setCharacterSize(15);
            textType2.setFillColor(sf::Color::Black);
            if(i==nb1){
                textType2.setPosition(250, 50+ (menuItem)*42);
            }
            else{
                textType2.setPosition(250, 50+ (menuItem+1)*42);
            }

            target.draw(textType2, states);
        }
        Text textItems(i==id?"> "+listofItem.at(i)->strEquipment():listofItem.at(i)->strEquipment(), f);
        textItems.setCharacterSize(15);
        textItems.setFillColor(sf::Color::Black);
        if(!isType2 || nb2==listofItem.size() && listofItem.size()>=9 && !isType2 || i==nb1 && listofItem.at(i)->GetitemType()==type2 || listofItem.size()>=9 && checkNextSpace || listofItem.size()<8 && listofItem.at(0)->GetitemType()==type2){
            textItems.setPosition(250, 50 + (menuItem+1)*42);
            if(i==nb1 && listofItem.at(i)->GetitemType()==type2){
               checkNextSpace=true;
            }
        }
        else{
            textItems.setPosition(250, 50 + (menuItem+2)*42);
        }
        target.draw(textItems, states);
        menuItem++;

        if(nb2<listofItem.size()){
            Text textArrowDown("Go down", f);
            textArrowDown.setCharacterSize(20);
            textArrowDown.setFillColor(sf::Color::Black);
            textArrowDown.setPosition(460, 420);
            target.draw(textArrowDown, states);
        }

        if(id>=8){
            Text textArrowUp("Go up", f);
            textArrowUp.setCharacterSize(20);
            textArrowUp.setFillColor(sf::Color::Black);
            textArrowUp.setPosition(460, 50);
            target.draw(textArrowUp, states);
        }
    }
}

/*void WindowStatus::drawEquipment(RenderTarget& target, RenderStates states,int nb1,int nb2) const{
    Font f = *FontsManager::getInstance()->get("arial");
    int menuEquipment=0;
    bool isArmor=false;
    bool isWeapon=false;
    bool checkNextSpace=false;

    for (int i = nb1; i < nb2; i++)
    {
        if(equipments.at(i)->GetitemType()=="Weapon" && !isWeapon){
            isWeapon=true;
            Text textWeapon("Weapons : ", f);
            textWeapon.setCharacterSize(15);
            textWeapon.setFillColor(sf::Color::Black);
            textWeapon.setPosition(250, 50);
            target.draw(textWeapon, states);
        }
        if(equipments.at(i)->GetitemType()=="Armor" && !isArmor){
            isArmor=true;
            Text textArmor("Armors : ", f);
            textArmor.setCharacterSize(15);
            textArmor.setFillColor(sf::Color::Black);
            textArmor.setPosition(250, 50+ (i+1)*42);
            //if(nb2==equipments.size() && equipments.size()>=9){
            if(i==nb1){
                textArmor.setPosition(250, 50+ (menuEquipment)*42);
            }
            else{
                textArmor.setPosition(250, 50+ (menuEquipment+1)*42);
            }
            target.draw(textArmor, states);
        }
        Text textEquipment(i==selected_id_menu?"> "+equipments.at(i)->strEquipment():equipments.at(i)->strEquipment(), f);
        textEquipment.setCharacterSize(15);
        textEquipment.setFillColor(sf::Color::Black);
        //if(!isArmor || nb2==equipments.size()  && equipments.size()>=9){
        if(!isArmor || nb2==equipments.size() && equipments.size()>=9 && !isArmor || i==nb1 && equipments.at(i)->GetitemType()=="Armor" || equipments.size()>=9 && checkNextSpace || equipments.size()<8 && equipments.at(0)->GetitemType()=="Armor"){
            textEquipment.setPosition(250, 50 + (menuEquipment+1)*42);
            if(i==nb1 && equipments.at(i)->GetitemType()=="Armor"){
               checkNextSpace=true;
            }
        }
        else{
            textEquipment.setPosition(250, 50 + (menuEquipment+2)*42);
        }
        target.draw(textEquipment, states);
        menuEquipment++;

        if(nb2<equipments.size()){
            Text textArrowDown("Go down", f);
            textArrowDown.setCharacterSize(20);
            textArrowDown.setFillColor(sf::Color::Black);
            textArrowDown.setPosition(460, 420);
            target.draw(textArrowDown, states);
        }

        if(selected_id_menu>=8){
            Text textArrowUp("Go up", f);
            textArrowUp.setCharacterSize(20);
            textArrowUp.setFillColor(sf::Color::Black);
            textArrowUp.setPosition(460, 50);
            target.draw(textArrowUp, states);
        }
    }
}*/

void WindowStatus::eventHandler(Event event)
{
    if (event.type == Event::KeyPressed)
    {
        switch(choiceMenu){
        case 0:
            {
                switch (event.key.code)
                {
                case Keyboard::Up:
                    {
                        selected_id--;
                        break;
                    }
                case Keyboard::Down:
                    {
                        selected_id++;
                        break;
                    }
                case Keyboard::Escape:
                    {
                        gotoPreviousScene();
                        return;
                    }
                case Keyboard::Enter:
                    {
                        switch(selected_id)
                        {
                        case 0:
                            {
                                //status
                                choiceMenu=0;
                                break;
                            }
                        case 1:
                            {
                                //equipment
                                choiceMenu=1;
                                break;
                            }
                        case 2:
                            {
                                //items
                                choiceMenu=2;
                                break;
                            }
                        case 3:
                            {
                                //return to game
                                gotoPreviousScene();
                                return;
                            }

                        default:
                            {
                                break;
                            }
                        }
                        break;
                    }

                    default: // no default action
                    break;
                }
                selected_id = max(0, min((int)selected_id, (int) (MENU_LENGTH - 1)));
                break;
            }
            case 1:
            {
               switch (event.key.code)
                {
                    case Keyboard::Up:
                        {
                            if(selected_id_menu>0){
                                selected_id_menu--;
                            }
                            break;
                        }

                    case Keyboard::Down:
                        {
                            if(selected_id_menu<equipments.size()){
                                selected_id_menu++;
                            }
                            break;
                        }
                    case Keyboard::Escape:
                        {
                            choiceMenu=0;
                            break;
                        }
                    case Keyboard::Enter:
                        {
                            if(equipments.size()>0){
                                p->changeEquipment(equipments.at(selected_id_menu)->GetitemName());
                            }
                            choiceMenu=0;
                            break;
                        }
                    default: // no default action
                    break;
                }
                selected_id_menu = max(0, min((int)selected_id_menu, (int)(equipments.size() - 1)));
                break;
            }
            case 2:
            {
               switch (event.key.code)
                {
                    case Keyboard::Up:
                        {
                            if(selected_id_items>0){
                                selected_id_items--;
                            }
                            break;
                        }

                    case Keyboard::Down:
                        {
                            if(selected_id_items<items.size()){
                                selected_id_items++;
                            }
                            break;
                        }
                    case Keyboard::Escape:
                        {
                            choiceMenu=0;
                            break;
                        }
                    case Keyboard::Enter:
                        {
                            if(items.size()>0){
                                p->heals(items.at(selected_id_items));
                                int tmp = indexOfHeal(items.at(selected_id_items));
                                delete items.at(tmp);
                                items.erase(items.begin() + tmp);
                            }
                            choiceMenu=0;
                            break;
                        }
                    default: // no default action
                    break;
                }
                selected_id_items = max(0, min((int)selected_id_items, (int)(items.size() - 1)));
                break;
            }
            default: // no default action
            break;
        }
    }
}

int WindowStatus::indexOfHeal(Item* item) const
{
    for (unsigned i = 0; i < items.size(); i++){
        if (*(items.at(i)) == *item){
            return i;
        }
    }
    return -1;
}


