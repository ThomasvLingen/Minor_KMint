//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_BEEKEEPER_HPP
#define MINOR_KMINT_BEEKEEPER_HPP


#include "../../IGameObject.h"
#include "../../graph/CoordinateInt.hpp"


class BeeField;

class BeeKeeper : public IGameObject {
public:
    BeeKeeper(BeeField& field, CoordinateInt current_position);

    BeeField& field;
    CoordinateInt current_position;
    CoordinateInt target_position;

    virtual void Draw() override;

    virtual void Update(float deltaTime) override;
};


#endif //MINOR_KMINT_BEEKEEPER_HPP
