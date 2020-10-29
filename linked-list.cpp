#include "LinkedList.h"

LinkedList::LinkedList() {
  _front = nullptr;
  _back = nullptr;
}

LinkedList::~LinkedList() {
  while (_front != nullptr) {
    ListNode *temp = _front->next;
    delete _front;
    _front = temp;
  }
}

void LinkedList::addFront(void *value) {
  ListNode *newNode = new ListNode(value);
  newNode->next = _front;
  _front = newNode;
}

void LinkedList::addBack(void *value) {
  ListNode *newNode = new ListNode(value);
  newNode->prev = _back;
  _back = newNode;
}

void LinkedList::removeFront() {
  ListNode *temp = _front->next;
  delete _front;
  _front = temp;
}

void LinkedList::removeValue(void *value) {
  ListNode *prev = nullptr;
  ListNode *curr = _front;

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

  ListNode *nextNode = curr->next;
  prev->next = nextNode;
  nextNode->prev = prev;
  delete curr;
}

void LinkedList::removeBack() {
  ListNode *temp = _back->prev;
  delete _back;
  _back = temp;
}

bool LinkedList::isEmpty() {
  return _front == nullptr;
}

std::ostream &operator<<(std::ostream &out, LinkedList &list) {
    out << "{";
    if (!list.isEmpty()) {
        out << list._front->data;
        ListNode *curr = list._front->next;
        while (curr != nullptr) {
            out << ", " << curr->data;
            curr = curr->next;
        }
    }
    out << "}";
    return out;
}
