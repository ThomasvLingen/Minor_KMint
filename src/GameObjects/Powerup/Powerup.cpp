//
// Created by mafn on 1/5/17.
//

#include "Powerup.hpp"
#include "../../RandomUtil.hpp"
#include "../../UnusedMacro.hpp"

Powerup::Powerup(BeeField& field)
: _garfield(field)
{
    this->SetTexture(this->mApplication->LoadTexture("bij.png"));
    this->SetSize(50, 50);

    this->_jump_to_random_vector();
}

void Powerup::Update(float deltaTime)
{
    UNUSED(deltaTime);
    this->SetOffset(
        (uint32_t)this->current_position->coordinates.x,
        (uint32_t)this->current_position->coordinates.y
    );
}

void Powerup::_jump_to_random_vector()
{
    this->current_position = RANDOM.choice(this->_garfield.field.get_vertices());
}
