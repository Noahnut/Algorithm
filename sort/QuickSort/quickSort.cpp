#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "quickSort.hpp"

using namespace std;

void 
QuickSort::swap(size_t* lhs,size_t* rhs)
{
    size_t temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

vector<size_t>
RamdomGen::RamdomNumber(int range)
{
   unsigned seed = (unsigned)time(NULL);
   srand(seed);
   for(int i = 0 ; i < range; i++){
       int number = rand()%range;
       test_data.push_back(number); 
   }
   return test_data;
}


void
QuickSort::quicksort()
{
  sort(0, data.size());
}

void
QuickSort::sort(size_t start, size_t end)
{
  size_t number = end;
  if(start < end && end <= data.size()){
  //  int ramNumber = rand()%number;
  //  swap(&data[end-1], &data[ramNumber]);
    size_t partition_position = partitation(start, end);  
    sort(start, partition_position-1);
    sort(partition_position+1, end);
  }  
}

size_t
QuickSort::partitation(size_t start, size_t end)
{
  if(end == data.size()){
      end = end - 1;
  }
  size_t pivot = data[end];
  size_t divide;
  if(start == 0){divide = 0;}
  else{divide = start;} 
  for(size_t i = start; i < end; i++){
      if(data[i] <= pivot){
          swap(&data[divide],&data[i]);
           ++divide;
      }
  }
  swap(&data[divide], &data[end]);
  return divide;
}


void
QuickSort::display()
{ 
    for(size_t i = 0; i < size(); i++){
        cout << data[i] << " ";
    }
    cout << endl;
}