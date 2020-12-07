//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <initializer_list>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
#include "p2.h"

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
class distance_{
    priority_queue<DistNode<T>, vector<DistNode<T>>, compare_Dist<T>> heapData;

    T originX;
    T originY;
public:
    distance_(int posX, int posY){
        originX = posX;
        originY = posY;
    }

    void operator=(initializer_list<pair<T,T>> list){
        for(auto it = list.begin(); it != list.end(); it++){
            heapData.push(DistNode<T>((*it).first, (*it).second, originX, originY));
        }
    }

    void push_back(pair<T,T> positions){
        heapData.push(DistNode<T>(positions.first, positions.second, originX, originY));
    }


    pair<T, T> pop_back(){
        DistNode<T> temp = heapData.top();
        return temp.position;
    }



    vector<pair<T,T>> operator() (int n){
        vector<pair<T,T>> result;

        for(int i = 0; i < n; i++){
            result.push_back((heapData.top()).position);
            heapData.pop();
        }
        return result;
    }

    

    int get_size(){
        return heapData.size();
    }


};

void pregunta_2() {

}


