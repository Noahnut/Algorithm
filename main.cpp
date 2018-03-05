#include <iostream>
#include <vector>
#include "heapsort.hpp"

using namespace std;

//class declaration 
heap_tree heapTree;
Test_data test;

int main()
{
  int range_number;
  cout << "enter the range number" << endl;
  cin >> range_number;
  vector<size_t> number;
  number = test.RamdomNumberGen(range_number);
  heapTree.Init_Heap_Tree(range_number, number);
  test.display_test();
  heapTree.display();
  heapTree.sort();
  heapTree.display_sort();
  return 0;
 
