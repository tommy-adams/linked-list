#pragma once
#include <ostream>

template <typename T>
struct ListNode {
  T data;
  ListNode *next;
  ListNode *prev;

  ListNode(T value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

template <typename T>
class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void addFront(T value);
  void addBack(T value);
  void removeFront();
  void removeValue(T value);
  void removeBack();
  bool isEmpty();
  friend std::ostream &operator<<(std::ostream &out, LinkedList &list);

private:
  ListNode<T> *_front;
  ListNode<T> *_back;
};
