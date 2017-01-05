//
// Created by mafn on 12/22/16.
//

#ifndef MINOR_KMINT_BEENET_HPP
#define MINOR_KMINT_BEENET_HPP

#include "../../IGameObject.h"
#include "../../graph/CoordinateDouble.hpp"
#include <vector>

using std::vector;

class BeeKeeper;
class Bee;

class BeeNet : public IGameObject {
public:
    BeeNet(BeeKeeper& context);

    vector<Bee*> caught_bees;

    virtual void Draw() override;
    virtual void Update(float deltaTime) override;

    CoordinateDouble get_position();

    void catch_bees_in_range(int max_bees_in_net);
    void lose_bee();

    void clear();
    size_t bees_in_net();

private:
    const Color _draw_colour = { 0x0, 0x0, 0xFF, 0x80};
    const int _net_growth = 10;
    const int _net_growth_interval_ms = 1000;

    BeeKeeper& _context;

    int _radius;

    int _last_growth_timestamp;

    void _expand();

    void _catch_bee(Bee* to_catch);
    vector<Bee*> _get_bees_in_net_range();
};


#endif //MINOR_KMINT_BEENET_HPP
