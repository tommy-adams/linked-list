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
    LinkedList() {
        _front = nullptr;
        _back = nullptr;
    }

    ~LinkedList() {
        while (_front != nullptr) {
          ListNode<T> *temp = _front->next;
          delete _front;
          _front = temp;
        }
    }

    void addFront(T value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->next = _front;
        _front = newNode;
    }

    void addBack(T value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->prev = _back;
        _back = newNode;
    }

    void removeFront() {
        ListNode<T> *temp = _front->next;
        delete _front;
        _front = temp;
    }

    void removeValue(T value) {
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

    void removeBack() {
        ListNode<T> *temp = _back->prev;
        delete _back;
        _back = temp;
    }

    bool isEmpty() {
        return _front == nullptr;
    }

    friend std::ostream &operator<<(std::ostream &out, LinkedList &list) {
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

private:
  ListNode<T> *_front;
  ListNode<T> *_back;
};
