//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_BEE_HPP
#define MINOR_KMINT_BEE_HPP


#include "../../IGameObject.h"
#include "../Vehicle.hpp"

class Bee : public IGameObject, public Vehicle {
public:
    Bee(BeeField& beeField, double max_speed, CoordinateDouble pos);

    virtual void Update(float deltaTime) override;

    virtual void Draw() override;
};


#endif //MINOR_KMINT_BEE_HPP
