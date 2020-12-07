//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <vector>
#include "p4.h"

using namespace std;

void pregunta_4_case_1() {
    int n = 0;
    int m = 0;
    int sum = 0;
    cin >> n >> m >> sum;
    vector<int> vec1(n);
    vector<int> vec2(m);
    for(auto& item: vec1)
        cin >> item;
    for(auto& item: vec2)
        cin >> item;
    vector<pair <int, int>> result = get_equivalent_pair(vec1, vec2, sum);
    for(auto e : result){
        cout << e.first << " " << e.second << endl;
    }
}

