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
#include "states/BeeKeeperChaseState.hpp"
#include "BeeNet.hpp"
#include "states/BeeKeeperReturnState.hpp"
#include "states/BeeKeeperPowerupState.hpp"
#include "states/BeeKeeperSuperState.hpp"
#include "statistical_fsm/BeeKeeperStatisticalFSM.hpp"


using std::vector;

class BeeField;
class Bee;

class BeeKeeper : public IGameObject {
    friend class BeeKeeperState;
    friend class BeeKeeperLostItState;
    friend class BeeKeeperChaseState;
    friend class BeeKeeperReturnState;
    friend class BeeKeeperPowerupState;
    friend class BeeKeeperSuperState;
    friend class BeeNet;
public:
    BeeKeeper(BeeField& field, Vertex* start_position);

    BeeField& field;
    Vertex* current_vertex;
    Vertex* target_vertex = nullptr;
    CoordinateDouble current_position;
    CoordinateDouble target_position;

    BeeNet net;

    virtual void Draw() override;
    virtual void Update(float deltaTime) override;

    void set_state(BeeKeeperState* next_state);

private:
    const int normal_speed = 100;
    const int super_speed = normal_speed * 3;
    int speed = normal_speed;

    const Color _white = {0xFF, 0xFF, 0xFF, 0xFF};
    const Color _black = {0,    0,    0,    0xFF};

    std::deque<Vertex*> _path;
    BeeKeeperState* _current_state;
    BeeKeeperStatisticalFSM _fsm;

    void _step_towards_target(double dt);
    void _apply_vector(VectorDouble to_apply);
    VectorDouble _get_step_vector(double dt);

    void _target_random_neighbour();
    void _target_vertex(Vertex* v);
    void _target_next_vert_in_path();

    void _arrive_at_target(Vertex* v);

    Bee* _get_closest_bee();

    void _draw_target_vert();
    void _draw_beecount();

    void _engage_super_mode();
    void _disengage_super_mode();
};


#endif //MINOR_KMINT_BEEKEEPER_HPP
