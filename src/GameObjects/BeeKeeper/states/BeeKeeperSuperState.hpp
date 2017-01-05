//
// Created by mafn on 1/5/17.
//

#ifndef MINOR_KMINT_BEEKEEPERSUPERSTATE_HPP
#define MINOR_KMINT_BEEKEEPERSUPERSTATE_HPP


#include "BeeKeeperState.hpp"

class BeeKeeperSuperState : public BeeKeeperState {
public:
    BeeKeeperSuperState(BeeKeeper& context);

    virtual void update(float delta_time) override;

private:
    const size_t _max_bees_in_net = 30;

    void _set_next_state();
    void _recalculate_path();
    Vertex* _get_target_vertex();
};


#endif //MINOR_KMINT_BEEKEEPERSUPERSTATE_HPP
