#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

auto edge_compare2 = [](edge_t a, edge_t b) {
    return get<2>(a) < get<2>(b);
};

vector<edge_t> graph_t::kruskal_max() {
    // Variables
    vector<edge_t> result;
    // Copia del priority queue
    auto pq = edge_priority_queue_;
    // Algoritmo de Find Union (A traves de un objeto)
    find_union_t fu(vertices_.size());
    // Recorrer el priority queue mientras tenga aristas (edge)
    while (!pq.empty()) {
        // Obtengo la arista de menor peso
        auto edge = pq.top();
        pq.pop();
        // Verificacion de Ciclos si son diferentes los une
        if(fu.find(get<0>(edge)) != fu.find(get<1>(edge))) {
            fu.join(get<0>(edge), get<1>(edge));
            result.push_back(edge);
        }
    }
    return result;
}

vector<edge_t> graph_t::prim_max() {
    // Variables
    vector<edge_t> result;
    unordered_set<vertex_t> visited;
    edge_priority_queue_t available_edges(edge_compare2);
    // lambda
    auto is_visited = [&visited](vertex_t vx) {
        return visited.find(vx) != end(visited);
    };
    // Partir de la arista menor
    auto [v, a, w] = edge_priority_queue_.top();
    // Agrego todos los adjacentes a la lista de disponibles
    for (const auto& [a, w]: adjacent_[v])
        available_edges.push({ v, a, w});
    visited.insert(v);
    // Recorriendo aristas disponibles
    while ( !available_edges.empty()) {
        auto [v, a, w] = available_edges.top();
        available_edges.pop();
        if (!is_visited(a)) {
            visited.insert(a);
            result.emplace_back(v, a, w);
            for (const auto& [a2, w]: adjacent_[a])
                if (!is_visited(a2)) {
                    available_edges.push({ a, a2, w});
                }
        }
    }
    return result;
}


#endif
