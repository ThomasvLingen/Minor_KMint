//
// Created by mafn on 12/16/16.
//

#ifndef MINOR_KMINT_BEEFIELD_HPP
#define MINOR_KMINT_BEEFIELD_HPP


#include "../IGameObject.h"
#include "Graph.hpp"
#include "../GameObjects/BeeKeeper/BeeKeeper.hpp"

class Bee;

class BeeField : public IGameObject {
public:
    BeeField();

    virtual void Draw() override;
    virtual void Update(float deltaTime) override;

    Graph field;
    BeeKeeper* beekeeper;
    vector<Bee*> bees;


private:
    const int _vertex_draw_width = 8;
    const int _num_of_bees = 50;

    SDL_Texture* _bg_image;

    void _init_field();
    void _init_renderables();

    void _draw_vertices();
    void _draw_edges();
    void _draw_background();
};


#endif //MINOR_KMINT_BEEFIELD_HPP
