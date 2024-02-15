#include "container.h"
class List: public Container{
  public:
    Node* head;
    int size;

    List(){
      head=NULL;
      size=0;
    }

    List(int v){
      // Your code here
      head = new Node(v);
      size = 1;
    }

    List(List& l){
      // Your code here
      head = nullptr;
      size = 0;

      if(l.head != nullptr){
        head = new Node(l.head -> value);
        Node* current = head;
        Node* lCurrent = l.head->next;
  
        while (lCurrent != nullptr) {
          current->next = new Node(lCurrent-> value);
          current = current->next;
          lCurrent = lCurrent->next;
          size++;
        }
        size++;
      }
    }

    ~List(){
      // Your code here
        while (head != nullptr) {
          Node* temp = head;
          head = head-> next;
          delete temp;
        }
    }
    void add(int v){
      // Your code here
      Node* newNode = new Node(v);
      if (head == nullptr) {
        head = newNode;
      } else {
        Node* current = head;
        while (current->next != nullptr){
          current = current-> next;
        }
        current->next = newNode;
      }
      size++;
    }
    int pop(){
      // Your code here
      if (head == nullptr) {
        cout << "the list is empty";
      }
      Node* current = head;
      Node* prev = nullptr;
      
      while(current->next != nullptr) {
        prev = current;
        current = current->next;
      }
      int value = current->value;
      if(prev != nullptr) {
        prev->next = nullptr;
      } else {
        head = nullptr;
      }
      delete current;
      size--;
      return value;
    }
    bool operator==(const List& rhs){
      // Your code here
      if (size != rhs.size) return false;
      Node* current1 = head;
      Node* current2 = rhs.head;
      while (current1 != nullptr) {
        if (current1->value != current2->value) return false;
        current1 = current1->next;
        current2 = current2->next;
      }
      return true;
    }

    bool operator!=(const List& rhs){
      // Your code here
      return !(*this==rhs); //refer to operator==
    }
    friend ostream& operator<<(ostream& os, List& l);
};
ostream& operator<<(ostream& os, List& l){
    // Your code here
    Node* current = l.head;
    os << "[";
    while (current != nullptr){
      os << current-> value;
      if (current->next != nullptr) os << ", ";
      current = current->next;
    }
    os << "]";
    return os;
}
