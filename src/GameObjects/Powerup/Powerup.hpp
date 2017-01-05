//
// Created by mafn on 1/5/17.
//

#ifndef MINOR_KMINT_POWERUP_HPP
#define MINOR_KMINT_POWERUP_HPP


#include "../../IGameObject.h"
#include "../../graph/BeeField.hpp"

class Vertex;

class Powerup : public IGameObject {
public:
    Powerup(BeeField& field);

    Vertex* current_position;

    virtual void Update(float deltaTime) override;

private:
    BeeField& _garfield;

    void _jump_to_random_vector();
};


#endif //MINOR_KMINT_POWERUP_HPP
