//
// Created by jazula on 12/16/16.
//

#ifndef MINOR_KMINT_BEEKEEPER_HPP
#define MINOR_KMINT_BEEKEEPER_HPP


#include <deque>
#include <vector>

#include "../../IGameObject.h"
#include "../../graph/CoordinateInt.hpp"
#include "../../graph/CoordinateDouble.hpp"
#include "../../Math/VectorDouble.hpp"
#include "../../graph/Vertex.hpp"
#include "states/BeeKeeperState.hpp"
#include "states/BeeKeeperLostItState.hpp"


using std::vector;

class BeeField;

class BeeKeeper : public IGameObject {
    friend class BeeKeeperState;
    friend class BeeKeeperLostItState;
public:
    BeeKeeper(BeeField& field, Vertex* start_position);

    BeeField& field;
    Vertex* current_vertex;
    Vertex* target_vertex = nullptr;
    CoordinateDouble current_position;
    CoordinateDouble target_position;

    virtual void Draw() override;

    virtual void Update(float deltaTime) override;

private:
    const int speed = 100;

    std::deque<Vertex*> _path;
    BeeKeeperState* _current_state;

    void _step_towards_target(double dt);
    void _apply_vector(VectorDouble to_apply);
    VectorDouble _get_step_vector(double dt);

    void _target_random_neighbour();
    void _target_vertex(Vertex* v);
    void _arrive_at_target(Vertex* v);
};


#endif //MINOR_KMINT_BEEKEEPER_HPP
