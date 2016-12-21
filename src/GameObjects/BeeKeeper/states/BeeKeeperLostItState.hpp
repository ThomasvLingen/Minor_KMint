//
// Created by mafn on 12/21/16.
//

#ifndef MINOR_KMINT_BEEKEEPERLOSTITSTATE_HPP
#define MINOR_KMINT_BEEKEEPERLOSTITSTATE_HPP


#include "BeeKeeperState.hpp"

class BeeKeeperLostItState : public BeeKeeperState {
public:
    BeeKeeperLostItState(BeeKeeper& context);

    virtual void update(float delta_time) override;

private:
};


#endif //MINOR_KMINT_BEEKEEPERLOSTITSTATE_HPP
