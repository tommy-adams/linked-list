#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  LinkedList<int> newList;

  newList.addFront(1);
  newList.addBack(2);
  newList.addFront(3);
  newList.addBack(4);
  cout << newList << endl;

  newList.removeFront();
  newList.removeValue(1);
  newList.removeBack();
  cout << newList << endl;

  cout << newList.getFront() << endl;
  cout << newList.getBack() << endl;

  newList.removeBack();
  if (newList.isEmpty()) {
      cout << "List is empty!" << endl;
  } else {
      cout << "List is not empty." << endl;
  }

  return 0;
}
