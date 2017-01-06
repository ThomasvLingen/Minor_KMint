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
, _radius(this->_net_start_radius)
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

void BeeNet::catch_bees_in_range(int max_bees_in_net)
{
    int num_of_bees_to_catch = max_bees_in_net - this->bees_in_net();

    if (num_of_bees_to_catch < 0) {
        // Something is horribly wrong lol
        return;
    }

    vector<Bee*> bees_in_range = this->_get_bees_in_net_range();
    // I probably should have solved this the imperative way instead of making it a magic one-liner.
    // But what this basically does is initialise bees_to_catch with the amount of bees that we want to catch.
    // In the case that bees_in_range is smaller than num_of_bees... then it will be a copy of bees_in_range.
    // Otherwise it will be the first num_of_bees... elements of bees_in_range.
    vector<Bee*> bees_to_catch (
        bees_in_range.begin(),
        std::next(
            bees_in_range.begin(),
            std::min((size_t)num_of_bees_to_catch, bees_in_range.size())
        )
    );

    for (Bee* bee : bees_to_catch) {
        this->_catch_bee(bee);
    }
}

void BeeNet::_catch_bee(Bee* to_catch)
{
    to_catch->get_caught(*this);
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

size_t BeeNet::bees_in_net()
{
    return this->caught_bees.size();
}

void BeeNet::clear()
{
    // We dump bees in BeeField::bees_out_of_game
    vector<Bee*>& target = this->_context.field.bees_out_of_game;
    target.insert(target.end(), this->caught_bees.begin(), this->caught_bees.end());
    this->caught_bees.clear();
}

void BeeNet::lose_bee()
{
    if (this->caught_bees.size() > 0) {
        this->caught_bees[0]->get_set_free(*this);
    }
}

CoordinateDouble BeeNet::get_position()
{
    return this->_context.current_position;
}

void BeeNet::reset_size()
{
    this->_radius = this->_net_start_radius;
}
