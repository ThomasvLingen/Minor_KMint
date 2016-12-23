//
// Created by mafn on 12/23/16.
//

#include "BeeKeeperReturnState.hpp"
#include "../BeeKeeper.hpp"
#include "../../../Pathfinding/Pathfinding.hpp"
#include "../../../graph/BeeField.hpp"

BeeKeeperReturnState::BeeKeeperReturnState(BeeKeeper& context)
: BeeKeeperState(context)
{
    this->_set_path_to_home();
}

void BeeKeeperReturnState::update(float delta_time)
{
    if (this->_context.current_position == this->_context.target_position) {
        this->_context._arrive_at_target(this->_context.target_vertex);

        // Target the next thingy in the path
        if (this->_context._path.size() > 0) {
            this->_context._target_next_vert_in_path();
        } else {
            // Hey, the path is empty and we've arrived at the target vector!
            this->_returned_home();
            this->_context.set_state(new BeeKeeperChaseState(this->_context));
        }
    } else {
        this->_context._step_towards_target(delta_time);
    }
}

void BeeKeeperReturnState::_set_path_to_home()
{
    vector<Vertex*> proposed_path = Pathfinding::astar(this->_context.field.field, this->_context.current_vertex, this->_context.field.home_vector);
    this->_context._path = std::deque<Vertex*>(proposed_path.begin(), proposed_path.end());
}

void BeeKeeperReturnState::_returned_home()
{
    this->_context.net.bees_in_net = 0;
}
