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
  cout << newList << endl; // should print {3, 1, 2, 4}

  newList.removeFront();
  newList.removeValue(1);
  newList.removeBack();
  cout << newList << endl; // should print {2}

  cout << newList.getFront() << endl; // should print 2
  cout << newList.getBack() << endl; // should print 2

  newList.removeBack();
  if (newList.isEmpty()) {
      cout << "List is empty!" << endl;
  } else {
      cout << "List is not empty." << endl;
  }

  newList += 3;
  newList += 5;
  newList += 11;
  newList += 2;
  cout << newList << endl; // should print {3, 5, 11, 2}

  newList -= 5;
  cout << newList << endl; // should print {3, 11, 2}

  newList--;
  cout << newList << endl; // should print {3, 11}

  --newList;
  cout << newList << endl; // should print {11}

  return 0;
}
