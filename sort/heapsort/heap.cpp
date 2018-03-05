#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "heapsort.hpp"

using namespace std;

void
Test_data::display_test()
{
  for(size_t i = 0 ; i < test_data.size(); i++){
    cout << test_data[i] << " ";
  }
  cout << "\n";
}



vector<size_t> 
Test_data::RamdomNumberGen(unsigned range)
{
  unsigned seed = (unsigned)time(NULL);
  srand(seed);
  for(size_t i = 0; i < range; i++){
     size_t number = rand()%range;
     test_data.push_back(number);
  }
  return test_data;
}

void 
heap_tree::Init_Heap_Tree(size_t size, vector<size_t> data)
{
  Test_data test;
  data_size = size;
  heap_node* heap = new heap_node();
  heap->data = INT_FAST8_MIN;
  HeapTree.push_back(heap);
  for(size_t i = 0 ; i <= data_size ; i++){
      heap_node* heap = new heap_node();
      heap->data = data[i];
      HeapTree.push_back(heap);
  }
  for(size_t i = data_size / 2; i > 0; i--){
    Max_Heapift(HeapTree, i);
  }
}

void
heap_tree::Max_Heapift(vector<heap_node*> heapTree, size_t node_position)
{
   size_t left = node_position * 2;
   size_t right = node_position * 2 + 1;
   size_t largest = node_position;
   if(right <= data_size && heapTree[right]->data > heapTree[largest]->data){
     largest = right;
   }
   else largest = node_position;
   if(left <= data_size && heapTree[left]->data > heapTree[largest]->data){
     largest = left;
   }
   if(largest != node_position){
     swap(heapTree[largest], heapTree[node_position]);
     Max_Heapift(heapTree, largest);
   }
}

void 
heap_tree::sort()
{
  for(size_t i = data_size; i >= 2; i--){
    sorting.push_back(HeapTree[1]->data);
    swap(HeapTree[1], HeapTree[i]);
    data_size = data_size - 1;
    Max_Heapift(HeapTree, 1);
  }
}

void
heap_tree::display_sort()
{
  for(size_t i = 0; i <= sorting.size(); i++){
    cout << sorting[i] << " ";
  }
  cout << "\n";
}

void
heap_tree::display()
{
  for(size_t i = 1; i <= data_size; i++){
    cout << HeapTree[i]->data << " ";
    if(i % 10 == 0){
      cout << "\n";
    } 
  }
  cout << "\n";
}

void 
heap_tree::swap(heap_node* rhs, heap_node* lhs)
{
   heap_node temp = *rhs;
   *rhs = *lhs;
   *lhs = temp;
}

