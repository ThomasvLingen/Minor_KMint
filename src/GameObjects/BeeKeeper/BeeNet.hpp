//
// Created by mafn on 12/22/16.
//

#ifndef MINOR_KMINT_BEENET_HPP
#define MINOR_KMINT_BEENET_HPP

#include "../../IGameObject.h"
#include <vector>

using std::vector;

class BeeKeeper;
class Bee;

class BeeNet : public IGameObject {
public:
    BeeNet(BeeKeeper& context);

    int bees_in_net = 0;

    virtual void Draw() override;
    virtual void Update(float deltaTime) override;

    void catch_bees_in_range();

private:
    const Color _draw_colour = { 0x0, 0x0, 0xFF, 0x80};
    const int _net_growth = 10;
    const int _net_growth_interval_ms = 1000;

    BeeKeeper& _context;

    int _radius;

    int _last_growth_timestamp;

    void _expand();
    vector<Bee*> _get_bees_in_net_range();
};


#endif //MINOR_KMINT_BEENET_HPP
