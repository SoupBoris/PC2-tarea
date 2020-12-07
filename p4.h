//
// Created by rudri on 10/11/2020.
//

#ifndef POO1_UNIT6_P4_H
#define POO1_UNIT6_P4_H

#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

template <typename T, template<typename...> class Container>
vector<pair<T,T>> get_equivalent_pair(Container<T> params1, Container<T> params2, T sum){

    vector<pair<T,T>> result;
    unordered_set <T> HashStruct (params2.begin(), params2.end()); 

    for(auto e1: params1){
        auto temp = HashStruct.find(sum - e1);
        if(temp != HashStruct.end()){
            result.push_back({e1, *temp});
        }
    }

    return result;

}

void pregunta_4_case_1();

#endif //POO1_UNIT6_P4_H
