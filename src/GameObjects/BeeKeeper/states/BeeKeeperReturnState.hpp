//
// Created by mafn on 12/23/16.
//

#ifndef MINOR_KMINT_BEEKEEPERRETURNSTATE_HPP
#define MINOR_KMINT_BEEKEEPERRETURNSTATE_HPP


#include "BeeKeeperState.hpp"

class BeeKeeperReturnState : public BeeKeeperState {
public:
    BeeKeeperReturnState(BeeKeeper& context);

    virtual void update(float delta_time) override;
private:

    void _set_path_to_home();
    void _returned_home();
};


#endif //MINOR_KMINT_BEEKEEPERRETURNSTATE_HPP
