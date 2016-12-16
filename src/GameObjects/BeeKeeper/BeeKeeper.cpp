//
// Created by jazula on 12/16/16.
//

#include "BeeKeeper.hpp"

BeeKeeper::BeeKeeper(BeeField& field, CoordinateInt current_position)
: field(field)
, current_position(current_position)
{
    this->SetTexture(mApplication->LoadTexture("lemmling_Cartoon_cow.png"));
    this->SetSize(40, 40);
}

void BeeKeeper::Draw()
{
    IGameObject::Draw();
}

void BeeKeeper::Update(float deltaTime)
{
    this->SetOffset((uint32_t)this->current_position.x, (uint32_t)this->current_position.y);
}
