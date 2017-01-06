//
// Created by mafn on 1/6/17.
//

#ifndef MINOR_KMINT_BEEKEEPERSTATISTICALFSM_HPP
#define MINOR_KMINT_BEEKEEPERSTATISTICALFSM_HPP

#include <functional>
#include <vector>

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

class BeeKeeperStatisticalFSM {
public:
    BeeKeeperStatisticalFSM(BeeKeeper& context);
    BeeKeeperState* get_next_state();
private:
    BeeKeeper& _context;
    const int start_weight = 10;

    vector<BeeKeeperStatisticalFSMlet> _FSMlets;

    vector<int> _get_FSMlet_weights();
};


#endif //MINOR_KMINT_BEEKEEPERSTATISTICALFSM_HPP
