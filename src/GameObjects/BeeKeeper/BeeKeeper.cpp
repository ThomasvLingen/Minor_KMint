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
, target_vertex(current_vertex)
, current_position(start_position->coordinates)
, target_position(start_position->coordinates)
, net(*this)
, fsm(*this)
{
    this->SetTexture(mApplication->LoadTexture("imker.png"));
    this->SetSize(40, 40);

    this->set_state(new BeeKeeperChaseState(*this));
}

void BeeKeeper::Draw()
{
    IGameObject::Draw();

    this->_draw_target_vert();
    this->_draw_beecount();
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

void BeeKeeper::_target_next_vert_in_path()
{
    // Move to the next vertex in our path
    if (!this->_path.empty()) {
        Vertex* move_here = this->_path.back();
        this->_path.pop_back();

        this->_target_vertex(move_here);
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

/// If there are no bees, a nullptr is returned
Bee* BeeKeeper::_get_closest_bee()
{
    auto bee_comparison = [this] (Bee* a, Bee* b) {
        CoordinateDouble& pos = this->current_position;

        return a->pos.get_raw_distance_to_point(pos) < b->pos.get_raw_distance_to_point(pos);
    };

    vector<Bee*>::iterator found_bee = std::min_element(this->field.bees.begin(), this->field.bees.end(), bee_comparison);

    if (found_bee != this->field.bees.end()) {
        return *found_bee;
    } else {
        return nullptr;
    }
}

void BeeKeeper::_draw_target_vert()
{
    if (this->_path.size() > 0) {
        this->mApplication->SetColor(Color {0, 255, 0, 255});

        Vertex* last_vert_in_path = this->_path.front();
        this->mApplication->DrawCircle(last_vert_in_path->coordinates.x, last_vert_in_path->coordinates.y, 8, true);
    }
}

void BeeKeeper::_draw_beecount()
{
    int num_of_bees = this->net.caught_bees.size();

    this->mApplication->SetColor(this->_white);
    this->mApplication->DrawRect(this->current_position.x - 10, this->current_position.y - 60, 20, 20, true);
    this->mApplication->SetColor(this->_black);
    this->mApplication->DrawText(std::to_string(num_of_bees), this->current_position.x, this->current_position.y - 50);
}


void BeeKeeper::set_state(BeeKeeperState* next_state)
{
    this->_current_state = next_state;
}

void BeeKeeper::_engage_super_mode()
{
    this->speed = this->super_speed;
    this->SetTexture(mApplication->LoadTexture("super_imker.png"));
}

void BeeKeeper::_disengage_super_mode()
{
    this->speed = this->normal_speed;
    this->SetTexture(mApplication->LoadTexture("imker.png"));
}
