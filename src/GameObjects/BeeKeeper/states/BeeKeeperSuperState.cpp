//
// Created by mafn on 1/5/17.
//

#include <deque>
#include <iostream>
#include "BeeKeeperSuperState.hpp"
#include "../../../Pathfinding/Pathfinding.hpp"
#include "../BeeKeeper.hpp"
#include "../../../graph/BeeField.hpp"

BeeKeeperSuperState::BeeKeeperSuperState(BeeKeeper& context)
: BeeKeeperState(context)
{
    this->_context._engage_super_mode();

    this->_recalculate_path();
    this->_context._target_next_vert_in_path();
}

void BeeKeeperSuperState::update(float delta_time)
{
    this->_context.net.catch_bees_in_range(this->_max_bees_in_net);

    if (this->_context.current_position == this->_context.target_position) {
        this->_context._arrive_at_target(this->_context.target_vertex);

        if (this->_context.net.bees_in_net() >= this->_max_bees_in_net || this->_context.field.bees.size() == 0) {
            this->_set_next_state();
            return;
        }

        this->_recalculate_path();
        // Target the next thingy in the path
        if (this->_context._path.size() > 0) {
            this->_context._target_next_vert_in_path();
        }
    } else {
        this->_context._step_towards_target(delta_time);
    }
}

void BeeKeeperSuperState::_recalculate_path()
{
    Vertex* target = this->_get_target_vertex();

    if (target != nullptr) {
        vector<Vertex*> proposed_path = Pathfinding::astar(this->_context.field.field, this->_context.current_vertex, target);
        this->_context._path = std::deque<Vertex*>(proposed_path.begin(), proposed_path.end());
    }
}

Vertex* BeeKeeperSuperState::_get_target_vertex()
{
    Bee* closest_bee = this->_context._get_closest_bee();

    if (closest_bee != nullptr) {
        Vertex* closest_vert_to_bee = this->_context.field.field.get_vertex_closest_to_point(closest_bee->pos);

        if (closest_vert_to_bee != nullptr) {
            return closest_vert_to_bee;
        } else {
            std::cout << "A bee was found, but there is no closest vertex while recalcing the path for the keeper" << std::endl;
            return nullptr;
        }
    } else {
        std::cout << "Not a single bee was found while recalcing the path for the keeper" << std::endl;
        return nullptr;
    }
}

void BeeKeeperSuperState::_set_next_state()
{
    this->_context._disengage_super_mode();
    this->_context.set_state(new BeeKeeperReturnState(this->_context));
}
