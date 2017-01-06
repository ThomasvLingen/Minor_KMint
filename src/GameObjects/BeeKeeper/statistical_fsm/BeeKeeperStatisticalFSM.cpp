//
// Created by mafn on 1/6/17.
//

#include "BeeKeeperStatisticalFSM.hpp"
#include "../states/BeeKeeperReturnState.hpp"
#include "../states/BeeKeeperLostItState.hpp"
#include "../states/BeeKeeperPowerupState.hpp"
#include "../../../RandomUtil.hpp"
#include "../../../UnusedMacro.hpp"

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

string BeeKeeperStatisticalFSM::_get_FSMlet_weight_percentage(BeeKeeperStatisticalFSMlet& fsmlet)
{
    double weight_percentage = ((double)fsmlet.weight / (double)this->_get_total_weight()) * 100;

    return std::to_string(weight_percentage) + "%";
}

int BeeKeeperStatisticalFSM::_get_total_weight()
{
    int total_weight = 0;

    for (auto& fsmlet : this->_FSMlets) {
        total_weight += fsmlet.weight;
    }

    return total_weight;
}

void BeeKeeperStatisticalFSM::Draw()
{
    this->mApplication->SetColor({0, 0, 0, 0xFF});

    int draw_x = 300;
    int draw_y = 610;

    for (auto& FSMlet : this->_FSMlets) {
        this->mApplication->DrawText(
            FSMlet.name + ": "  +this->_get_FSMlet_weight_percentage(FSMlet),
            draw_x,draw_y
        );

        draw_y += 15;
    }
}

void BeeKeeperStatisticalFSM::Update(float deltaTime)
{
    UNUSED(deltaTime);
}
