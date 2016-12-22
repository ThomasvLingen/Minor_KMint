//
// Created by mafn on 12/22/16.
//

#include "BeeNet.hpp"
#include "BeeKeeper.hpp"
#include "../../UnusedMacro.hpp"

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
