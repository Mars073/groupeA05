#include "View/DrawableBattleCharacter.h"

DrawableBattleCharacter::DrawableBattleCharacter(BattleCharacter* _character, Vector2f _position):position(_position)
{
    setCharacter(_character);
}

DrawableBattleCharacter::~DrawableBattleCharacter()
{
    //dtor
}

void DrawableBattleCharacter::setPosition(int x, int y) {
    setPosition((float) x, (float) y);
}

void DrawableBattleCharacter::setPosition(float x, float y)
{
    setPosition(Vector2f(x, y));
}

void DrawableBattleCharacter::setPosition(Vector2f _position)
{
    position = _position;
    if (character)
    {
        textureOffset = Vector2f(B_WIDTH/2, B_HEIGHT+B_WIDTH/2) - Vector2f(texture.getSize().x/2.f, texture.getSize().y/2.f);
    }
}

void DrawableBattleCharacter::setCharacter(BattleCharacter* _character)
{
    character = _character;
    texture = *tm->get("mob_"+character->GetcharaName());
    setPosition(position); // refresh offset
}
void DrawableBattleCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!character)
    {
        Text err("NoChar", *fm->get("arial"));
        err.setPosition(position);
        target.draw(err);
        return;
    }
    /** Draw HP */
    if (character->Gethp() > 0)
    {
        RectangleShape hp(position);
        hp.setFillColor(Color::Green);
        hp.setSize(Vector2f(
            ((float)character->Gethp())/character->GetmaxHp()*B_WIDTH,
            B_HEIGHT
        ));
        target.draw(hp);
    }
    /** Draw MP */
    if (character->Getmp() > 0)
    {
        RectangleShape mp(position + Vector2f(0, B_WIDTH + B_HEIGHT));
        mp.setFillColor(Color::Cyan);
        mp.setSize(Vector2f(
            ((float)character->Getmp())/character->GetmaxMp()*B_WIDTH,
            B_HEIGHT
        ));
        target.draw(mp);
    }
    /** Draw Sprite centered */
    Sprite sprite(texture);
    sprite.setPosition(position + textureOffset);
    target.draw(sprite);
}
