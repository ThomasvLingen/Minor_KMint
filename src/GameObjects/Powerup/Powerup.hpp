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

    void jump_to_random_vector();

    virtual void Update(float deltaTime) override;

private:
    BeeField& _garfield;
};


#endif //MINOR_KMINT_POWERUP_HPP
