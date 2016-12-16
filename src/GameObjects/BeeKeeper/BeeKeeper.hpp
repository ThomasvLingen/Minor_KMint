//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_BEEKEEPER_HPP
#define MINOR_KMINT_BEEKEEPER_HPP


#include "../../IGameObject.h"
#include "../../graph/CoordinateInt.hpp"
#include "../../graph/CoordinateDouble.hpp"
#include "../../Math/VectorDouble.hpp"


class BeeField;

class BeeKeeper : public IGameObject {
public:
    BeeKeeper(BeeField& field, CoordinateDouble current_position);

    BeeField& field;
    CoordinateDouble current_position;
    CoordinateDouble target_position;

    virtual void Draw() override;

    virtual void Update(float deltaTime) override;

private:
    const int speed = 10;

    void _step_towards_target();
    void _apply_vector(VectorDouble to_apply);
    VectorDouble _get_step_vector();
};


#endif //MINOR_KMINT_BEEKEEPER_HPP
