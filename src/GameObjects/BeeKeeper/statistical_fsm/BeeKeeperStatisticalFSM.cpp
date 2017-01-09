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
    this->_last_used_fsmlet_index = FSMlet_index;
    this->_fsmlet_start_timestamp = this->mApplication->GetTimeSinceStartedMS();

    return this->_FSMlets[FSMlet_index].get_state();
}

void BeeKeeperStatisticalFSM::adjust_fsmlets(int bees_caught)
{
    if (bees_caught == 0) {
        this->_FSMlets[this->_last_used_fsmlet_index].weight -= 1;
        return;
    }

    int now = this->mApplication->GetTimeSinceStartedMS();
    int diff = now - this->_fsmlet_start_timestamp;

    double new_average = diff / bees_caught;

    if (this->time_per_bee_averages.size() > 0) {
        if (this->better_than_average(new_average)) {
            this->_FSMlets[this->_last_used_fsmlet_index].weight += 1;
        } else {
            // this->_FSMlets[this->_last_used_fsmlet_index].weight -= 1;
        }
    }

    this->time_per_bee_averages.push_back(new_average);

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

double BeeKeeperStatisticalFSM::average_time_per_bee()
{
    double total = 0;

    for (double time_per_bee : this->time_per_bee_averages) {
        total += time_per_bee;
    }

    return total / this->time_per_bee_averages.size();
}

bool BeeKeeperStatisticalFSM::better_than_average(double time_per_bee)
{
    return time_per_bee > this->average_time_per_bee();
}
