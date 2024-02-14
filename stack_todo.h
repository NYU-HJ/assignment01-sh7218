#include "container.h"
class Stack: public Container{
  public:
    Node* head;
    int size;

    Stack(){
      head=NULL;
      size=0;
    }

    Stack(int v){
      // Your code here
      head = new Node(v);
      size = 1;
    }

    Stack(Stack& l){
      // Your code here
      head = nullptr;

      if(l.head != nullptr){
        head = new Node(l.head -> value);
        Node* current = head;
        Node* lCurrent = l.head->next;
        while (lCurrent != nullptr) {
          current->next = new Node(lCurrent-> value);
          current = current->next;
          lCurrent = lCurrent->next;
        }
      }
      size = l.size;
    }

    ~Stack(){
      // Your code here
      Node* current = head;
      while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
      }
    }

    void push(int value){
      // Your code here
      Node* newNode = new Node(value);
      head = newNode;
      size++;
    }

    int pop(){
      // Your code here
      if (head == nullptr) {
        cout << "the stack is empty";
      }
      Node* temp = head;
      int value = head->value;
      head = head->next;
      delete temp;
      size--;
      return value;
    }

    bool operator==(const Stack& rhs){
      // Your code here
      if (size != rhs.size) return false;
      Node* current1 = head;
      Node* current2 = rhs.head;
      while (current1 != nullptr) {
        if (current1->value !=current2-> value) return false;
        current1 = current1->next;
        current2 = current2->next;
      }
      return true;
    }

    bool operator!=(const Stack& rhs){
      // Your code here
       return !(*this==rhs); //refer to operator==
    }

    friend ostream& operator<<(ostream& os, Stack& l);
};
ostream& operator<<(ostream& os, Stack& l){
    // Your code here
    Node* current = l.head;
    os << "[";
    while (current != nullptr) {
      os << current-> value;
      if (current->next != nullptr) os << ", ";
      current = current->next;
    }
    os << "]";
    return os;
}
