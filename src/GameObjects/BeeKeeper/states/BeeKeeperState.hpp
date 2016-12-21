//
// Created by BOB on 12/1/16.
//

#ifndef MINOR_KMINT_BEEKEEPERSTATE_HPP
#define MINOR_KMINT_BEEKEEPERSTATE_HPP

#include <string>
#include "../../../graph/Vertex.hpp"

using std::string;

class BeeKeeper;

class BeeKeeperState {
public:
    BeeKeeperState(BeeKeeper& context);
    virtual void update(float delta_time) = 0;

    string name;
protected:
    BeeKeeper& _context;
};


#endif //MINOR_KMINT_BEEKEEPERSTATE_HPP
