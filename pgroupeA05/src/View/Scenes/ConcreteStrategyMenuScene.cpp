#include <View/Scenes/ConcreteStrategyMenuScene.h>

ConcreteStrategyMenuScene::ConcreteStrategyMenuScene()
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

    this->rectMenuRight.setPosition(sf::Vector2f(240,60));
    this->rectMenuRight.setSize(sf::Vector2f(300,380));
    this->rectMenuRight.setOutlineThickness(5);
    this->rectMenuRight.setOutlineColor(sf::Color(255,255,255));
    this->rectMenuRight.setFillColor(sf::Color(253,67,0));

    this->choiceMenu=0;

}

ConcreteStrategyMenuScene::~ConcreteStrategyMenuScene()
{

}

ConcreteStrategyMenuScene::ConcreteStrategyMenuScene(const ConcreteStrategyMenuScene& other)
{
    this->rectAll=other.rectAll;

    this->rectMenu=other.rectMenu;

    this->rectMenuRight=other.rectMenuRight;

    this->choiceMenu=other.choiceMenu;
}

ConcreteStrategyMenuScene& ConcreteStrategyMenuScene::operator=(const ConcreteStrategyMenuScene& rhs)
{
    if (this != &rhs){
        this->rectAll=rhs.rectAll;

        this->rectMenu=rhs.rectMenu;

        this->rectMenuRight=rhs.rectMenuRight;

        this->choiceMenu=rhs.choiceMenu;
    }
    //assignment operator
    return *this;
}

void ConcreteStrategyMenuScene::draw(RenderTarget& target, RenderStates states) const
{
    target.setView(View(FloatRect(0, 0, SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT))); // HOT FIX
    Sprite sprite;
    Texture t = *TexturesManager::getInstance()->get("status");
    sprite.setTexture(t);
    Font f = *FontsManager::getInstance()->get("arial");
    target.draw(sprite, states);
    target.draw(Panel(rectAll), states);
    target.draw(Panel(rectMenu), states);
    target.draw(Panel(rectMenuRight), states);

    Text textHelp("<ENTER> Interact - <UP ARROW> Go up - <DOWN ARROW> Go down", f);
    textHelp.setCharacterSize(15);
    textHelp.setFillColor(sf::Color::Black);
    textHelp.setPosition(0, 0);
    textHelp.setStyle(sf::Text::Bold);
    target.draw(textHelp, states);

    Text textHelp2("<ESC> Go back", f);
    textHelp2.setCharacterSize(15);
    textHelp2.setFillColor(sf::Color::Black);
    textHelp2.setPosition(0, 20);
    textHelp2.setStyle(sf::Text::Bold);
    target.draw(textHelp2, states);

    for (int i = 0; i < MENU_LENGTH; i++)
    {
        Text text(i==selected_id?"> "+menu[i]:menu[i], f);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);
        text.setPosition(70, 70 + i*42);
        target.draw(text, states);
    }

    if(choiceMenu==0){
        Text textStatus(invent.Getplayer()->str(), f);
        textStatus.setCharacterSize(15);
        textStatus.setFillColor(sf::Color::Black);
        textStatus.setPosition(250, 60);
        target.draw(textStatus, states);
    }
    else if(choiceMenu==1){
        int nb1=0,nb2=8;

        for(unsigned i=0;i< ceil(((float)invent.Getequipments().size()/8)) ;i++){
            if(nb2>invent.Getequipments().size()){
                nb2=invent.Getequipments().size();
            }
            if(selected_id_menu>=nb1&&selected_id_menu<nb2){
                drawItems(target,states,nb1,nb2,invent.Getequipments(),"Weapon","Armor","Weapons : ","Armors : ",selected_id_menu);
            }
            nb1+=8;
            nb2+=8;
        }
    }
    else if(choiceMenu==2){
        int nb1=0,nb2=8;

        for(unsigned i=0;i< ceil(((float)invent.Getitems().size()/8)) ;i++){
            if(nb2>invent.Getitems().size()){
                nb2=invent.Getitems().size();
            }
            if(selected_id_items>=nb1&&selected_id_items<nb2){
                drawItems(target,states,nb1,nb2,invent.Getitems(),"Heal","HealMp","Heal hp : ","Heal mp : ",selected_id_items);
            }
            nb1+=8;
            nb2+=8;
        }
    }
}

void ConcreteStrategyMenuScene::drawItems(RenderTarget& target, RenderStates states,int nb1,int nb2,std::vector<Item*>listofItem,std::string type1,std::string type2,std::string type1Desc,std::string type2Desc,short int id) const{
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
            textType1.setPosition(250, 60);
            textType1.setStyle(sf::Text::Bold | sf::Text::Underlined);
            target.draw(textType1, states);
        }
        if(listofItem.at(i)->GetitemType()==type2 && !isType2){
            isType2=true;
            Text textType2(type2Desc, f);
            textType2.setCharacterSize(15);
            textType2.setFillColor(sf::Color::Black);
            textType2.setStyle(sf::Text::Bold | sf::Text::Underlined);
            if(i==nb1){
                textType2.setPosition(250, 60+ (menuItem)*42);
            }
            else{
                textType2.setPosition(250, 40+ (menuItem+1)*42);
            }

            target.draw(textType2, states);
        }
        Text textItems(i==id?"> "+listofItem.at(i)->strEquipment():listofItem.at(i)->strEquipment(), f);
        textItems.setCharacterSize(15);
        textItems.setFillColor(sf::Color::Black);
        if(!isType2 || nb2==listofItem.size() && listofItem.size()>=9 && !isType2 || i==nb1 && listofItem.at(i)->GetitemType()==type2 || listofItem.size()>=9 && checkNextSpace || listofItem.size()<8 && listofItem.at(0)->GetitemType()==type2){
            textItems.setPosition(250, 40 + (menuItem+1)*42);
            if(i==nb1 && listofItem.at(i)->GetitemType()==type2){
               checkNextSpace=true;
            }
        }
        else{
            textItems.setPosition(250, 30 + (menuItem+2)*42);
        }
        target.draw(textItems, states);
        menuItem++;

        if(nb2<listofItem.size()){
            Text textArrowDown("Go down", f);
            textArrowDown.setCharacterSize(20);
            textArrowDown.setFillColor(sf::Color::Black);
            textArrowDown.setPosition(455, 410);
            target.draw(textArrowDown, states);
        }

        if(id>=8){
            Text textArrowUp("Go up", f);
            textArrowUp.setCharacterSize(20);
            textArrowUp.setFillColor(sf::Color::Black);
            textArrowUp.setPosition(455, 60);
            target.draw(textArrowUp, states);
        }
    }
}

void ConcreteStrategyMenuScene::eventHandler(Event event)
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
                            if(selected_id_menu<invent.Getequipments().size()){
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
                            if(invent.Getequipments().size()>0){
                                invent.Getplayer()->changeEquipment(invent.Getequipments().at(selected_id_menu)->GetitemName());
                            }
                            choiceMenu=0;
                            break;
                        }
                    default: // no default action
                    break;
                }
                selected_id_menu = max(0, min((int)selected_id_menu, (int)(invent.Getequipments().size() - 1)));
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
                            if(selected_id_items<invent.Getitems().size()){
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
                            if(invent.Getitems().size()>0){
                                invent.Getplayer()->heals(invent.Getitems().at(selected_id_items));
                                invent.deleteItem(selected_id_items);
                            }
                            choiceMenu=0;
                            break;
                        }
                    default: // no default action
                    break;
                }
                selected_id_items = max(0, min((int)selected_id_items, (int)(invent.Getitems().size() - 1)));
                break;
            }
            default: // no default action
            break;
        }
    }
}


