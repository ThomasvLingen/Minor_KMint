//
// Created by mafn on 12/22/16.
//

#include <iostream>
#include "BeeNet.hpp"
#include "BeeKeeper.hpp"
#include "../../UnusedMacro.hpp"
#include "../../graph/BeeField.hpp"
#include "../../Math/Circle.hpp"

BeeNet::BeeNet(BeeKeeper& context)
: _context(context)
, _radius(10)
, _last_growth_timestamp(this->mApplication->GetTimeSinceStartedMS())
{

}

void BeeNet::Draw()
{
    this->mApplication->SetColor(this->_draw_colour);
    this->mApplication->DrawCircle(
        (int)this->_context.current_position.x,
        (int)this->_context.current_position.y,
        this->_radius, true
    );
}

void BeeNet::Update(float deltaTime)
{
    UNUSED(deltaTime);
    int now = this->mApplication->GetTimeSinceStartedMS();

    if (now > this->_last_growth_timestamp + this->_net_growth_interval_ms) {
        this->_expand();
    }
}

void BeeNet::_expand()
{
    this->_last_growth_timestamp = this->mApplication->GetTimeSinceStartedMS();
    this->_radius += this->_net_growth;
}

void BeeNet::catch_bees_in_range()
{
    vector<Bee*> bees_in_range = this->_get_bees_in_net_range();

    for (Bee* bee : bees_in_range) {
        bee->die();
        this->bees_in_net++;

        std::cout << "Net contains " << this->bees_in_net << " bees." << std::endl;
    }
}

vector<Bee*> BeeNet::_get_bees_in_net_range()
{
    vector<Bee*> bees_in_range;

    Circle net_circle(this->_context.current_position, this->_radius);

    for (Bee* bee : this->_context.field.bees) {
        Circle bee_circle(bee->pos, bee->radius);

        if (Circle::do_intersect(net_circle, bee_circle)) {
            bees_in_range.push_back(bee);
        }
    }

    return bees_in_range;
}
