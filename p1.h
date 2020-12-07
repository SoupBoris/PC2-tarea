//
// Created by rudri on 10/11/2020.
//

#ifndef POO1_PC2_P1_H
#define POO1_PC2_P1_H

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*

// Funciones para ubicar nodos en un heap
inline size_t get_left_child_index(size_t index) { return index * 2; }
inline size_t get_right_child_index(size_t index) { return index * 2 + 1; }
inline size_t get_parent_index(size_t index) { return index / 2; }

template <typename T, typename Compare>
size_t get_max_child_index(vector<T>& data, size_t index, Compare comp) {
  // Obtener los 2 hijos
  auto left_child_index = get_left_child_index(index);
  auto right_child_index = get_right_child_index(index);

  // Si no existe el hijo derecho se toma el hijo izquierdo
  if (right_child_index >= data.size())
    return left_child_index;
  //*************
  else if (comp(data[left_child_index], data[right_child_index]) == true)
  // else if (data[left_child_index] < data[right_child_index])
  //*************
    return right_child_index;
  else
    return left_child_index;  
}

template <typename T>
bool has_child(vector<T>& data, size_t index) {
  return get_left_child_index(index) < data.size();
}

template <typename T, typename Compare>
void percolate_up(vector<T>& data, size_t index, Compare comp) {
  // 1. Ubicar el padre
  auto parent_index = get_parent_index(index);
  // 2. Condiciones base
  if (parent_index == 0) return;  // Limite superior
  //*************
  if (comp(data[index], data[parent_index]) == true) return; // Para comparar hijo vs padre
  // if (data[index] < data[parent_index]) return; // Para comparar hijo vs padre
  //*************
  // 3. Condicion recursiva
  swap(data[index], data[parent_index]);
  percolate_up(data, parent_index, comp);
}

template <typename T, typename Compare>
void percolate_down(vector<T>& data, size_t index, Compare comp) {
  // 1. Obtener el mayor
  auto max_child_index = get_max_child_index(data, index, comp);
  // 2. Condiciones base
  // Comparar valor del index con el valor del max_child_index
  //*************
  if (comp(data[max_child_index], data[index]) == true) return; 
  // if (data[max_child_index] < data[index]) return; 
  //*************
  // Verificar si tiene hijos
  if (has_child(data, index) == false) return;
  // 3. Condicion recursiva
  swap(data[index], data[max_child_index]);
  percolate_down(data, max_child_index, comp); 
}

template <typename T, typename Compare>
void heapify(vector<T>& data, Compare comp) {
  for (size_t i = get_parent_index(data.size() - 1); i > 0; --i)
    percolate_down(data, i, comp);
}

template <typename T, typename Compare = less<int>>
class median{
  vector<T> data_;
  Compare comp;
public:
  // Constructores
  median(): data_(1) {}                               // Constructor por default
  median(const initializer_list<T>& list): data_(1) { // Constructor por parametros

    // Crear o construir un heap con push sucesivos
    //for (const auto& item: list) push(item);  // ---> O(n log n)
    
    data_.insert(end(data_), begin(list), end(list));
    heapify(data_, comp);   // ---> O(n);
  }

  // Top
  T top() { return data_[1]; }

  // Push
  void push(T value) {
    // 1. Agregar al final el valor
    data_.push_back(value);

    // 2. Ejecutar el percolate_up
    percolate_up(data_, size(), comp);
  }

  // Pop
  void pop() {
    // 1. intercambio del primero con el ultimo
    swap(data_[1], data_.back());

    // 2. Eliminar el ultimo
    data_.pop_back();

    // 3. Ejecutar el percolate_down
    percolate_down(data_, 1, comp);
  } 

  void pop_back(){
      data_.pop_back();
  }

  // Replace
  void replace (T old_value, T new_value) {
    // Buscar el valor anterior y reeemplazaro por el nuevo
    for (auto& item: data_)
      if (item == old_value)
        item = new_value;

    // Ejecutar el heapify
    heapify(data_, comp);
  }

  // Empty
  bool empty() { return data_.size() == 1; }
  // Size
  size_t size() { return data_.size() - 1; }

  float operator ()(){
        /*for(int i = 0; i < data_.size(); i++){
            cout << data_[i] << " ";
        }
        cout << endl;
       
        if( (data_.size()-1) % 2 == 0){
            int val0 = data_[(1 + data_.size())/2];
            int val1 = data_[(data_.size()/2)];
            float result = (float) ((float) val0 + (float)val1)/2;
            return result;
        }
        else{
            return data_[(1 + data_.size())/2];
        }
    }

};
*/

template <typename T>
class median{

  std::priority_queue<T, vector<T> , greater<T>> minHeap;
  std::priority_queue<T, vector<T> , less<T>> maxHeap;

  public:
    median(){
      std::priority_queue<T, vector<T> , greater<T>> minHeap;
      std::priority_queue<T, vector<T> , less<T>> maxHeap;
    }

    median(initializer_list<T> list){
        std::priority_queue<T, vector<T> , less<T>> temp;
        for(auto e : list){
        temp.push(e);
        }
        int size_ = temp.size();
        for(int i = 0; i < size_/2; i++){
            minHeap.push(temp.top());
            temp.pop();
        }
        size_=temp.size();
        for(int j=0; j < size_; j++){
            maxHeap.push(temp.top());
            temp.pop();
        }
    }

    void push_back(T data){

        if(data >= get_median()){
            minHeap.push(data);
        }
        else{
            maxHeap.push(data);
        }

        if(maxHeap.size() + 1 < minHeap.size()){
        T temp = minHeap.top();
        minHeap.pop();
        maxHeap.push(temp);
        }
        else if(maxHeap.size() > minHeap.size()){
        T temp = maxHeap.top();
        maxHeap.pop();
        minHeap.push(temp);
        }
    }

    void pop_back(){
      if(minHeap.size() >= maxHeap.size()){
        minHeap.pop();
      }
      else if(minHeap.size() < maxHeap.size()){
        maxHeap.pop();
      }
    }

    T get_median(){

        if(minHeap.empty()){
            return 0;
        }


        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2;
        }
        else if(maxHeap.empty() || minHeap.size() > maxHeap.top()){
            return minHeap.top();
        }
        else{
            return maxHeap.top();
        }
    }

    T operator() (){

        if(minHeap.empty()){
            return 0;
        }


        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2;
        }
        else if(maxHeap.empty() || minHeap.size() > maxHeap.top()){
            return minHeap.top();
        }
        else{
            return maxHeap.top();
        }
    }



};

void pregunta_1_case_1();



#endif //POO1_PC2_P1_H
