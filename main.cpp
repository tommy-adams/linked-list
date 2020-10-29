#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  LinkedList<int> newList;

  int i = 1;
  newList.addFront(i);
  cout << newList << endl;

  return 0;
}
