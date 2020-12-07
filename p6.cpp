//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "p6.h"

using namespace std;

void pregunta_6_case_1() {
    binary_tree a(1);
    // Izquierda
    auto left_branch = a.add_left(a.get_root(), 2);
    left_branch = a.add_left(left_branch, 3);
    left_branch = a.add_left(left_branch, 4);
    left_branch = a.add_left(left_branch, 5);
    left_branch = a.add_left(left_branch, 6);
    // Derecha
    auto right_branch = a.add_right(a.get_root(), 7);
    right_branch = a.add_right(right_branch, 8);
    right_branch = a.add_right(right_branch, 9);
    right_branch = a.add_right(right_branch, 10);
    right_branch = a.add_right(right_branch, 11);
    // Calcular Diametro
    cout << a.are_siblings(left_branch, right_branch) << endl;
}

