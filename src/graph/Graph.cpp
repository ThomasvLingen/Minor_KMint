//
// Created by mafn on 11/15/16.
//

#include "Graph.hpp"
#include <cmath>
#include <algorithm>

Graph::Graph()
{
}

void Graph::add_vertex(Vertex* vertex)
{
    this->_vertices.push_back(vertex);
}

void Graph::add_edge(Edge* edge)
{
    this->_edges.push_back(edge);
}

vector<Vertex*>& Graph::get_vertices()
{
    return this->_vertices;
}

vector<Edge*>& Graph::get_edges()
{
    return this->_edges;
}

float Graph::calculate_raw_distance_between_vertici(Vertex* first, Vertex* second)
{
    int delta_x = second->coordinates.x - first->coordinates.x;
    int delta_y = second->coordinates.y - first->coordinates.y;

    return (float)sqrt(pow(delta_x, 2) + pow(delta_y, 2));
}

vector<Vertex*> Graph::get_vertex_neighbours(Vertex* start)
{
    vector<Vertex*> neighbours;

    for (Edge* edge : this->_edges) {
        if (edge->first == start || edge->second == start) {
            // If something goes wrong, look here first
            (edge->first == start) ? neighbours.push_back(edge->second) : neighbours.push_back(edge->first);
        }
    }

    return neighbours;
}

Vertex* Graph::get_vertex_closest_to_point(CoordinateDouble pos)
{
    auto vertex_comparison = [pos] (Vertex* a, Vertex* b) {
        CoordinateDouble a_pos(a->coordinates);
        CoordinateDouble b_pos(b->coordinates);

        return a_pos.get_raw_distance_to_point(pos) < b_pos.get_raw_distance_to_point(pos);
    };

    vector<Vertex*>::iterator found_vertex = std::min_element(this->get_vertices().begin(), this->get_vertices().end(), vertex_comparison);

    if (found_vertex != this->get_vertices().end()) {
        return *found_vertex;
    } else {
        return nullptr;
    }
}
