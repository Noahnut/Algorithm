#ifndef _HEAPSORT_HPP
#define _HEAPSORT_HPP


#include <iostream>
#include <vector>

using namespace std;

class Test_data
{
  friend class heap_tree;
  public: 
   vector<size_t> RamdomNumberGen(unsigned range);
   void display_test(); 
  private:
   vector<size_t> test_data;
};


class heap_node
{
   friend class heap_tree;
   heap_node(int data = 0): data(data){ }
   heap_node& operator = (const heap_node& lhs){this->data = lhs.data; return *this;}
   size_t data;
};


class heap_tree
{
  
  public:
  ~heap_tree() 
  { 
    for(size_t i = 0; i < data_size; i++){
      delete HeapTree[i];
    }
    HeapTree.clear(); 
  }
   void Init_Heap_Tree(size_t size, vector<size_t> data);
 //  void Bulid_Heap_Tree(heap_node* node ,size_t data);
   void Max_Heapift(vector<heap_node*> heapTree, size_t node_position);
   void swap(heap_node* lhs, heap_node* rhs);
   void sort();
   void display();
   void display_sort();
   const size_t& operator[] (size_t i) const {return HeapTree[i]->data;}
   size_t& operator[] (size_t i) {return HeapTree[i]->data;}   
  private:
   size_t data_size;
   vector<size_t> sorting;
   vector<heap_node*> HeapTree;
};


#endif