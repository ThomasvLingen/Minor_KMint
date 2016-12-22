//
// Created by mafn on 12/21/16.
//

#include <iostream>
#include "BeeKeeperChaseState.hpp"
#include "../../BeeKeeper/BeeKeeper.hpp"
#include "../../../graph/BeeField.hpp"
#include "../../../Pathfinding/Pathfinding.hpp"

BeeKeeperChaseState::BeeKeeperChaseState(BeeKeeper& context)
: BeeKeeperState(context)
{
    this->name = "Beekeeper chase state";

    this->_recalculate_path();
    this->_context._target_next_vert_in_path();
}

void BeeKeeperChaseState::update(float delta_time)
{
    // std::cout << "pos [" << this->_context.current_position.x << "," << this->_context.current_position.y << "]" << std::endl;
    // std::cout << "target [" << this->_context.target_position.x << "," << this->_context.target_position.y << "]" << std::endl;

    this->_context.net.catch_bees_in_range();

    if (this->_context.current_position == this->_context.target_position) {
        this->_context._arrive_at_target(this->_context.target_vertex);
        this->_recalculate_path();
        // Target the next thingy in the path
        if (this->_context._path.size() > 0) {
            this->_context._target_next_vert_in_path();
        }
    } else {
        this->_context._step_towards_target(delta_time);
    }
}

void BeeKeeperChaseState::_recalculate_path()
{
    Vertex* target = this->_get_target_vertex();

    if (target != nullptr) {
        vector<Vertex*> proposed_path = Pathfinding::astar(this->_context.field.field, this->_context.current_vertex, target);
        this->_context._path = std::deque<Vertex*>(proposed_path.begin(), proposed_path.end());
    }
}

Vertex* BeeKeeperChaseState::_get_target_vertex()
{
    Bee* closest_bee = this->_context._get_closest_bee();
    // std::cout << closest_bee->pos.x << " , " << closest_bee->pos.y << std::endl;

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
