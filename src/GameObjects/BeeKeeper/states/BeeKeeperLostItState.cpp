//
// Created by mafn on 12/21/16.
//

#include <iostream>
#include "BeeKeeperLostItState.hpp"
#include "../BeeKeeper.hpp"

BeeKeeperLostItState::BeeKeeperLostItState(BeeKeeper& context)
: BeeKeeperState(context)
{
    this->name = "Beekeeper lost it state";

    this->_context._target_random_neighbour();
}

void BeeKeeperLostItState::update(float delta_time)
{
    if (this->_context.current_position == this->_context.target_position) {
        this->_context._arrive_at_target(this->_context.target_vertex);
        this->_context._target_random_neighbour();
    } else {
        this->_context._step_towards_target(delta_time);
    }
}
