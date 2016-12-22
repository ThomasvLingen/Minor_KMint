//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "Bee.hpp"
#include "../../graph/BeeField.hpp"
#include "../../VectorUtil.hpp"

Bee::Bee(BeeField& beeField, double max_speed, CoordinateDouble pos)
: Vehicle(beeField, max_speed, pos)
, _field(beeField)
{
    this->SetTexture(mApplication->LoadTexture("bij.png"));
    this->SetSize(40, 40);
}

void Bee::Update(float deltaTime)
{
    if (this->mIsActive) {
        Vehicle::Move(deltaTime * 1000);
        this->SetOffset((uint32_t)this->pos.x, (uint32_t)this->pos.y);
    }
}

void Bee::Draw()
{
    if (this->mIsActive) {
        IGameObject::Draw();
    }
}

void Bee::die()
{
    this->SetActive(false);

    VectorUtil::remove(this->_field.bees, this);
}
