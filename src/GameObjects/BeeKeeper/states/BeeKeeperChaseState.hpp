//
// Created by mafn on 12/21/16.
//

#ifndef MINOR_KMINT_BEEKEEPERCHASESTATE_HPP
#define MINOR_KMINT_BEEKEEPERCHASESTATE_HPP


#include "BeeKeeperState.hpp"

class BeeKeeperChaseState : public BeeKeeperState {
public:
    BeeKeeperChaseState(BeeKeeper& context);

    virtual void update(float delta_time) override;

private:

    const size_t _max_bees_in_net = 10;

    void _set_next_state();

    void _recalculate_path();
    Vertex* _get_target_vertex();
};


#endif //MINOR_KMINT_BEEKEEPERCHASESTATE_HPP
