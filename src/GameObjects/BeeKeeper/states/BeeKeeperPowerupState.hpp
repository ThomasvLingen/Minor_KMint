//
// Created by mafn on 1/5/17.
//

#ifndef MINOR_KMINT_BEEKEEPERPOWERUPSTATE_HPP
#define MINOR_KMINT_BEEKEEPERPOWERUPSTATE_HPP


#include "BeeKeeperState.hpp"

class BeeKeeperPowerupState : public BeeKeeperState {
public:
    BeeKeeperPowerupState(BeeKeeper& context);

    virtual void update(float delta_time) override;

private:

    void _set_path_to_powerup();
    void _arrived_at_powerup();
};


#endif //MINOR_KMINT_BEEKEEPERPOWERUPSTATE_HPP
