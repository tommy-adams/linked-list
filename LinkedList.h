#pragma once
#include <ostream>

struct ListNode {
  void *data;
  ListNode *next;
  ListNode *prev;
  ListNode(void *value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void addFront(void *value);
  void addBack(void *value);
  void removeFront();
  void removeValue(void *value);
  void removeBack();
  bool isEmpty();
  friend std::ostream &operator<<(std::ostream &out, LinkedList &list);

private:
  ListNode *_front;
  ListNode *_back;
};
