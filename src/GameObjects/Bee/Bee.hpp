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

    // This is in pixels
    const int radius = 20;

    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    void die();
private:
    BeeField& _field;
};


#endif //MINOR_KMINT_BEE_HPP
