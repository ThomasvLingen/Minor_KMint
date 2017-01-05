//
// Created by mafn on 1/5/17.
//

#include <deque>
#include "BeeKeeperPowerupState.hpp"
#include "../../../Pathfinding/Pathfinding.hpp"
#include "../BeeKeeper.hpp"
#include "../../../graph/BeeField.hpp"
#include "../../Powerup/Powerup.hpp"

BeeKeeperPowerupState::BeeKeeperPowerupState(BeeKeeper& context)
: BeeKeeperState(context)
{
    this->_set_path_to_powerup();
}

void BeeKeeperPowerupState::update(float delta_time)
{
    if (this->_context.current_position == this->_context.target_position) {
        this->_context._arrive_at_target(this->_context.target_vertex);

        // Target the next thingy in the path
        if (this->_context._path.size() > 0) {
            this->_context._target_next_vert_in_path();
        } else {
            // Hey, the path is empty and we've arrived at the target vector!
            this->_arrived_at_powerup();
            this->_context.set_state(new BeeKeeperSuperState(this->_context));
        }
    } else {
        this->_context._step_towards_target(delta_time);
    }
}

void BeeKeeperPowerupState::_set_path_to_powerup()
{
    vector<Vertex*> proposed_path = Pathfinding::astar(this->_context.field.field, this->_context.current_vertex, this->_context.field.powerup->current_position);
    this->_context._path = std::deque<Vertex*>(proposed_path.begin(), proposed_path.end());
}

void BeeKeeperPowerupState::_arrived_at_powerup()
{
    this->_context.field.powerup->jump_to_random_vector();
    // According to specs, we have to empty net upon powerup
    this->_context.net.clear();
}
