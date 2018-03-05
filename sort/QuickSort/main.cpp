#include <iostream>
#include <vector>
#include "quickSort.hpp"

using namespace std;
RamdomGen gen;

int main()
{
  vector<size_t> test_data;
  int gen_seed;
  cout << "input the data number\n";
  cin >> gen_seed;
  test_data = gen.RamdomNumber(gen_seed);
  QuickSort sort(test_data);
  sort.display();
  sort.quicksort();
  sort.display();   
  return 0;
}
