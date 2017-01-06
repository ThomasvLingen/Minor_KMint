//
// Created by mafn on 1/6/17.
//

#ifndef MINOR_KMINT_BEEKEEPERSTATISTICALFSM_HPP
#define MINOR_KMINT_BEEKEEPERSTATISTICALFSM_HPP

#include <functional>
#include <vector>
#include "../../../IGameObject.h"

using std::vector;
using std::string;
using std::function;

class BeeKeeperState;
class BeeKeeper;

struct BeeKeeperStatisticalFSMlet
{
    string name;
    int weight;
    function<BeeKeeperState*()> get_state;
};

class BeeKeeperStatisticalFSM : public IGameObject {
public:
    BeeKeeperStatisticalFSM(BeeKeeper& context);

    virtual void Draw() override;

    virtual void Update(float deltaTime) override;

    BeeKeeperState* get_next_state();

private:
    BeeKeeper& _context;
    const int start_weight = 10;

    vector<BeeKeeperStatisticalFSMlet> _FSMlets;

    vector<int> _get_FSMlet_weights();
    string _get_FSMlet_weight_percentage(BeeKeeperStatisticalFSMlet& fsmlet);
    int _get_total_weight();
};


#endif //MINOR_KMINT_BEEKEEPERSTATISTICALFSM_HPP
