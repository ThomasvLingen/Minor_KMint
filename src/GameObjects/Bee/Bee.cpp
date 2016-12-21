//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "Bee.hpp"

Bee::Bee(BeeField& beeField, double max_speed)
: Vehicle(beeField, max_speed)
{
    this->SetTexture(mApplication->LoadTexture("bij.png"));
    this->SetSize(40, 40);
}

void Bee::Update(float deltaTime)
{
    Vehicle::Move(deltaTime * 1000);
    this->SetOffset((uint32_t)this->pos.x, (uint32_t)this->pos.y);
}

void Bee::Draw()
{
    IGameObject::Draw();
}
