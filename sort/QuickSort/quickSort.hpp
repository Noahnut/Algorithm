
#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

class RamdomGen
{
  friend class QuickSort;
  public:
   vector<size_t> RamdomNumber(int seed);

  private:
   vector<size_t> test_data;
};


class QuickSort
{
 public:
  QuickSort(vector<size_t> d): data(d) { } 
  void quicksort();
  size_t size(){return data.size();}
  void display();
 private:
  void sort(size_t start, size_t end);
  size_t partitation(size_t start, size_t end);
  void swap(size_t* lhs,size_t* rhs);

  vector<size_t> data;

};


#endif