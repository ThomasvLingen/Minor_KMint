//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "BeeKeeper.hpp"
#include "../../Math/VectorDouble.hpp"

BeeKeeper::BeeKeeper(BeeField& field, CoordinateDouble current_position)
: field(field)
, current_position(current_position)
  // TODO: This should not be hardcoded
, target_position({50,50})
{
    this->SetTexture(mApplication->LoadTexture("imker.png"));
    this->SetSize(40, 40);
}

void BeeKeeper::Draw()
{
    IGameObject::Draw();
}

void BeeKeeper::Update(float deltaTime)
{
    if (this->current_position != this->target_position) {
        this->_step_towards_target((double) deltaTime);
    }

    this->SetOffset((uint32_t)this->current_position.x, (uint32_t)this->current_position.y);
}

void BeeKeeper::_step_towards_target(double dt)
{
    VectorDouble step_vector = this->_get_step_vector(dt);
    VectorDouble to_apply = step_vector;
    this->_apply_vector(to_apply);
}

VectorDouble BeeKeeper::_get_step_vector(double dt)
{
    VectorDouble step_vector(this->current_position - this->target_position);
    VectorDouble kill_me = step_vector.normalise() * speed * dt;

    // Check if total length to dest is higher than the length that we're about to take
    if (step_vector.get_length() > kill_me.get_length()) {
        return kill_me;
    } else {
        return step_vector;
    }
}

void BeeKeeper::_apply_vector(VectorDouble to_apply)
{
    this->current_position = this->current_position - to_apply;
}
