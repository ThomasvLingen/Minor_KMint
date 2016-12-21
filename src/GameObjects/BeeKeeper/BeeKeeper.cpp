//
// Created by jazula on 12/16/16.
//

#include <iostream>
#include "BeeKeeper.hpp"
#include "../../RandomUtil.hpp"
#include "../../graph/BeeField.hpp"

BeeKeeper::BeeKeeper(BeeField& field, Vertex* start_position)
: field(field)
, current_vertex(start_position)
, current_position(start_position->coordinates)
, _current_state(new BeeKeeperLostItState(*this))
{
    this->SetTexture(mApplication->LoadTexture("imker.png"));
    this->SetSize(40, 40);
}

void BeeKeeper::Draw()
{
    IGameObject::Draw();
}

void BeeKeeper::Update(float deltaTime)
{
    this->_current_state->update(deltaTime);

    this->SetOffset((uint32_t)this->current_position.x, (uint32_t)this->current_position.y);
}

void BeeKeeper::_step_towards_target(double dt)
{
    VectorDouble step_vector = this->_get_step_vector(dt);
    VectorDouble to_apply = step_vector;
    this->_apply_vector(to_apply);
}

VectorDouble BeeKeeper::_get_step_vector(double dt)
{
    VectorDouble step_vector(this->current_position - this->target_position);
    VectorDouble kill_me = step_vector.normalise() * speed * dt;

    // Check if total length to dest is higher than the length that we're about to take
    if (step_vector.get_length() > kill_me.get_length()) {
        return kill_me;
    } else {
        return step_vector;
    }
}

void BeeKeeper::_apply_vector(VectorDouble to_apply)
{
    this->current_position = this->current_position - to_apply;
}

void BeeKeeper::_target_random_neighbour()
{
    vector<Vertex*> neighbours = this->field.field.get_vertex_neighbours(this->current_vertex);

    if (neighbours.size() > 0) {
        this->_target_vertex(RANDOM.choice(neighbours));
    }
}

void BeeKeeper::_target_vertex(Vertex* v)
{
    this->target_vertex = v;
    this->target_position = v->coordinates;
}

void BeeKeeper::_arrive_at_target(Vertex* v)
{
    this->current_vertex = v;
}
