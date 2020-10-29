#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
  _front = nullptr;
  _back = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  while (_front != nullptr) {
    ListNode<T> *temp = _front->next;
    delete _front;
    _front = temp;
  }
}

template <typename T>
void LinkedList<T>::addFront(T value) {
  ListNode<T> *newNode = new ListNode<T>(value);
  newNode->next = _front;
  _front = newNode;
}

template <typename T>
void LinkedList<T>::addBack(T value) {
  ListNode<T> *newNode = new ListNode<T>(value);
  newNode->prev = _back;
  _back = newNode;
}

template <typename T>
void LinkedList<T>::removeFront() {
  ListNode<T> *temp = _front->next;
  delete _front;
  _front = temp;
}

template <typename T>
void LinkedList<T>::removeValue(T value) {
  ListNode<T> *prev = nullptr;
  ListNode<T> *curr = _front;

  if (_front == nullptr) {
    return;
  }

  while (curr->next) {
    if (curr->data == value) {
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  if (curr->next == nullptr) {
    return;
  }

  ListNode<T> *nextNode = curr->next;
  prev->next = nextNode;
  nextNode->prev = prev;
  delete curr;
}

template <typename T>
void LinkedList<T>::removeBack() {
  ListNode<T> *temp = _back->prev;
  delete _back;
  _back = temp;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
  return _front == nullptr;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, LinkedList<T> &list) {
    out << "{";
    if (!list.isEmpty()) {
        out << list._front->data;
        ListNode<T> *curr = list._front->next;
        while (curr != nullptr) {
            out << ", " << curr->data;
            curr = curr->next;
        }
    }
    out << "}";
    return out;
}
