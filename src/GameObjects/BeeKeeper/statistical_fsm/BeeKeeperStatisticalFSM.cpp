//
// Created by mafn on 1/6/17.
//

#include "BeeKeeperStatisticalFSM.hpp"
#include "../states/BeeKeeperReturnState.hpp"
#include "../states/BeeKeeperLostItState.hpp"
#include "../states/BeeKeeperPowerupState.hpp"
#include "../../../RandomUtil.hpp"

BeeKeeperStatisticalFSM::BeeKeeperStatisticalFSM(BeeKeeper& context)
: _context(context)
{
    this->_FSMlets.push_back({
        "Return state",
        this->start_weight,
        [this] () {
            return new BeeKeeperReturnState(this->_context);
        }
    });

    this->_FSMlets.push_back({
        "Lost it state",
        this->start_weight,
        [this] () {
            return new BeeKeeperLostItState(this->_context);
        }
    });

    this->_FSMlets.push_back({
        "Powerup state",
        this->start_weight,
        [this] () {
            return new BeeKeeperPowerupState(this->_context);
        }
    });
}

BeeKeeperState* BeeKeeperStatisticalFSM::get_next_state()
{
    int FSMlet_index = RANDOM.get_weighted_int(this->_get_FSMlet_weights());

    return this->_FSMlets[FSMlet_index].get_state();
}

vector<int> BeeKeeperStatisticalFSM::_get_FSMlet_weights()
{
    vector<int> weights;

    for (auto& FSMlet : this->_FSMlets) {
        weights.push_back(FSMlet.weight);
    }

    return weights;
}
