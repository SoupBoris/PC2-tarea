//
// Created by rudri on 10/11/2020.
//

#ifndef POO1_PC2_P2_H
#define POO1_PC2_P2_H
#include <iostream>
#include <initializer_list>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

template <typename T>
struct DistNode{
    pair <T, T> position;
    T distOrigin;

    DistNode(T posX_, T posY_, T originX = 0, T originY = 0){
        position = make_pair(posX_, posY_);
        distOrigin = sqrt(posX_*posX_ + posY_*posY_);
    }  

};

template <typename T>
struct compare_Dist{
    bool operator()(DistNode<T> a, DistNode<T> b){
        return a.distOrigin > b.distOrigin;
    }
};

//priority_queue<DistNode<T>, vector<T>, compare 

template <typename T>
class distancia{
    priority_queue<DistNode<T>, vector<DistNode<T>>, compare_Dist<T>> heapData;

    T originX;
    T originY;
public:
    distancia(int posX, int posY){
        originX = posX;
        originY = posY;
    }

    void operator=(initializer_list<pair<T,T>> list){
        for(auto it = list.begin(); it != list.end(); it++){
            heapData.push(DistNode<T>((*it).first, (*it).second, originX, originY));
        }
    }

    void push(pair<T,T> positions){
        heapData.push(DistNode<T>(positions.first, positions.second, originX, originY));
    }


    pair<T, T> pop(){
        DistNode<T> temp = heapData.top();
        return temp.position;
    }



    vector<pair<T,T>> operator() (int n){
        vector<pair<T,T>> result;

        for(int i = 0; i < n; i++){
            result.push((heapData.top()).position);
            heapData.pop();
        }
        return result;
    }

    

    int get_size(){
        return heapData.size();
    }


};

#endif //POO1_PC2_P2_H
