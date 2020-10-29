#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  LinkedList newList = LinkedList();

  string stringVal = "string";
  void *value = &stringVal;
  newList.addFront(value);
  cout << newList << endl;

  return 0;
}
