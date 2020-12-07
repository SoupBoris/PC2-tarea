//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include "p3.h"

using namespace std;

template <typename Container>
void remove_duplicates(Container& cont) {
    unordered_set<typename Container::value_type> hashStruct; 

    for(const auto& e : cont) {
        hashStruct.insert(e);
    }

    Container temp;

    for(const auto& e : hashStruct) {
        temp.push_back(e);
    }

    cont = temp;
}

