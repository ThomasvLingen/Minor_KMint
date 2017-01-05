//
// Created by mafn on 12/21/16.
//

#include <iostream>
#include "BeeKeeperLostItState.hpp"
#include "../BeeKeeper.hpp"
#include "../../../graph/BeeField.hpp"

BeeKeeperLostItState::BeeKeeperLostItState(BeeKeeper& context)
: BeeKeeperState(context)
, _last_bee_lost_timestamp(context.mApplication->GetTimeSinceStartedMS())
{
    this->name = "Beekeeper lost it state";

    this->_context._target_random_neighbour();
}

void BeeKeeperLostItState::update(float delta_time)
{
    if (this->_context.current_position == this->_context.target_position) {
        this->_context._arrive_at_target(this->_context.target_vertex);

        if (this->_context.net.caught_bees.size() == 0) {
            this->_context.set_state(new BeeKeeperReturnState(this->_context));
            return;
        }

        this->_context._target_random_neighbour();
    } else {
        this->_context._step_towards_target(delta_time);
    }

    int now = this->_context.mApplication->GetTimeSinceStartedMS();
    if (now > this->_last_bee_lost_timestamp + this->_lost_bee_interval) {
        this->_lose_bee();
    }
}

void BeeKeeperLostItState::_lose_bee()
{
    this->_last_bee_lost_timestamp = this->_context.mApplication->GetTimeSinceStartedMS();
    this->_context.net.lose_bee();
}
