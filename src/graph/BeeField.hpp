//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_BEEFIELD_HPP
#define MINOR_KMINT_BEEFIELD_HPP


#include "../IGameObject.h"
#include "Graph.hpp"
#include "../GameObjects/BeeKeeper/BeeKeeper.hpp"

class Bee;
class Powerup;

class BeeField : public IGameObject {
public:
    BeeField();

    virtual void Draw() override;
    virtual void Update(float deltaTime) override;

    Graph field;
    BeeKeeper* beekeeper;
    vector<Bee*> bees;
    vector<Bee*> bees_out_of_game;
    Powerup* powerup;
    Vertex* home_vector = nullptr;


private:
    const int _vertex_draw_width = 8;
    const size_t _num_of_bees = 100;

    SDL_Texture* _bg_image;

    void _init_field();
    void _init_renderables();

    void _draw_vertices();
    void _draw_edges();
    void _draw_background();

    void _reset_bees();
};


#endif //MINOR_KMINT_BEEFIELD_HPP
