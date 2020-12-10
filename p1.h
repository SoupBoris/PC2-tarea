//
// Created by rudri on 10/11/2020.
//

#ifndef POO1_PC2_P1_H
#define POO1_PC2_P1_H

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class mediana{

  std::priority_queue<T, vector<T> , greater<T>> minHeap;
  std::priority_queue<T, vector<T> , less<T>> maxHeap;

  public:
    mediana(){
      std::priority_queue<T, vector<T> , greater<T>> minHeap;
      std::priority_queue<T, vector<T> , less<T>> maxHeap;
    }

    mediana(initializer_list<T> list){
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

    void push(T data){

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

    void pop(){
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
