//
// Created by rudri on 10/11/2020.
//

#ifndef POO1_UNIT6_P7_H
#define POO1_UNIT6_P7_H

#include <queue>
#include <unordered_map>
#include "graph.h"

using namespace std;

bool graph_t::is_connected(){

    vertex_t curVertex = this->vertices_[0];
    std::queue<vertex_t> q;
    std::unordered_map<vertex_t, bool> visited;
    for(auto p : this->vertices_)  visited[p.second] = false;
    q.push(curVertex);
    visited[curVertex] = true;
    while(!q.empty()){
        curVertex = q.front();
        q.pop();
        for(auto edge : curVertex.edges){
            if(!visited[edge->vertexes[1]]){
                visited[edge->vertexes[1]] = true;
                q.push(edge->vertexes[1]);
            }
        }
    }
    for(auto p : visited) if(!p.second) return false;
    return true;
}

#endif //POO1_UNIT6_P7_H
