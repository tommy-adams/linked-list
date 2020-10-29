#pragma once
#include <ostream>

template <typename T>
struct ListNode {
  T data;
  ListNode *next; // location of next node in the list
  ListNode *prev; // location of previous node in the list

  ListNode(T value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

template <typename T>
class LinkedList {
public:

    // LinkedList constructor
    LinkedList() {
        _front = nullptr;
        _back = nullptr;
        _size = 0;
    }

    // LinkedList destructor
    ~LinkedList() {
        // loop through the list and release the memory back to the heap for each node
        while (_front != nullptr) {
          ListNode<T> *temp = _front->next;
          delete _front;
          _front = temp;
        }
    }

    // see the data value at the back of the list
    T getBack() {
        return _back->data;
    }

    // see the data value at the front of the list
    T getFront() {
        return _front->data;
    }

    // get number of nodes in linked list
    int size() {
        return _size;
    }

    // add a data value to the front of the list
    void addFront(T value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->next = _front;

        // if the front exists, its previous variable points to the new front
        // if the front doesn't exist, this is the first and last node
        if (_front != nullptr) {
            _front->prev = newNode;
        } else {
            _back = newNode;
        }

        _front = newNode; // the new node is the new front
        _size++;
    }

    // add a data value to the back of the list
    void addBack(T value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->prev = _back;

        // if the back exists, its next variable points to the new back
        // if the back doesn't exist, this is the last and first node
        if (_back != nullptr) {
            _back->next = newNode;
        } else {
            _front = newNode;
        }

        _back = newNode; // the new node is the new back
        _size++;
    }

    // remove the node at the front
    void removeFront() {
        ListNode<T> *temp = _front->next;
        delete _front;
        _front = temp;

        // if _front was the only node, the list is empty after its removal
        if (_front == nullptr) {
            _back == nullptr;
            return;
        }

        _front->prev = nullptr; // there is no value previous to the front
        _size--;
    }

    // remove the first instance of the value in the list
    void removeValue(T value) {
        ListNode<T> *prev = nullptr;
        ListNode<T> *curr = _front;

        // if there are no nodes in the list, return
        if (_front == nullptr) {
          return;
        }

        while (curr->next != nullptr) {
          if (curr->data == value) {
            break;
          }
          prev = curr;
          curr = curr->next;
        }

        // this occurs if we've traversed the list and never found the data
        if (curr->data != value) {
            return;
        }

        ListNode<T> *nextNode = curr->next;
        // if the search value is the first item in the list, the nextNode is now the front
        // else, the previous node's next variable now points to the node after the current one
        if (prev == nullptr) {
            _front = nextNode;
        } else {
            prev->next = nextNode;
        }
        nextNode->prev = prev;
        delete curr; // release the memory back to the heap
        _size--;
    }

    // remove the value at the back of the list
    void removeBack() {
        ListNode<T> *temp = _back->prev;
        delete _back;
        _back = temp;

        // after removing the value, if the back is nullptr then it is an empty list
        if (_back == nullptr) {
            _front = nullptr;
            return;
        }

        _back->next = nullptr;
        _size--;
    }

    // return true if there are no nodes in the list
    bool isEmpty() {
        return _front == nullptr;
    }

    // overload the << operator to print out the list in the form of an array of values
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

    // overload the += operator to add a value to the back of the list
    friend void operator+=(LinkedList &list, T value) {
        list.addBack(value);
    }

    // overload the -= operator to remove the first node with a certain value
    friend void operator-=(LinkedList &list, T value) {
        list.removeValue(value);
    }

    // overload the -- operator to remove the last node in the list
    friend LinkedList<T> &operator--(LinkedList &list, int) {
        list.removeBack();
        return list;
    }

    // overload the -- operator to remove the first node in the list
    friend LinkedList<T> &operator--(LinkedList &list) {
        list.removeFront();
        return list;
    }

private:
  ListNode<T> *_front; // pointer to the location of the front node
  ListNode<T> *_back; // pointer to the location of the back node
  int _size;
};
