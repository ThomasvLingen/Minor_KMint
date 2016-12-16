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
    this->SetTexture(mApplication->LoadTexture("lemmling_Cartoon_cow.png"));
    this->SetSize(40, 40);
}

void BeeKeeper::Draw()
{
    IGameObject::Draw();
}

void BeeKeeper::Update(float deltaTime)
{
    if (this->current_position != this->target_position) {
        this->_step_towards_target();
    }

    this->SetOffset((uint32_t)this->current_position.x, (uint32_t)this->current_position.y);
}

void BeeKeeper::_step_towards_target()
{
    this->_apply_vector(this->_get_step_vector());
}

VectorDouble BeeKeeper::_get_step_vector()
{
    VectorDouble step_vector(this->current_position - this->target_position);

    if (step_vector.get_length() > this->speed) {
        return step_vector.normalise() * speed;
    } else {
        return step_vector;
    }
}

void BeeKeeper::_apply_vector(VectorDouble to_apply)
{
    this->current_position = this->current_position - to_apply;
}
