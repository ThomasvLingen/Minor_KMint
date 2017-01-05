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
    this->SetTexture(mApplication->LoadTexture("taco.png"));
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
        this->mApplication->DrawLine(
            this->pos.x,
            this->pos.y,
            this->pos.x + this->heading.x*25,
            this->pos.y + this->heading.y*25
        );
    }
}

void Bee::get_caught(BeeNet& net)
{
    this->SetActive(false);

    // Move bee from BeeField's bees to the net
    VectorUtil::remove(this->_field.bees, this);
    net.caught_bees.push_back(this);
}

void Bee::get_set_free(BeeNet& net)
{
    this->SetActive(true);

    // Set our position to the net's position
    this->pos = net.get_position();

    // Move bee from net to Beefield's bees
    this->_field.bees.push_back(this);
    VectorUtil::remove(net.caught_bees, this);
}
