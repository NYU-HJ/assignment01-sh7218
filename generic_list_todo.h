#include <iostream>
using namespace std;
template <typename E> 

class ArrayListNode{
  public:
    E value;
    ArrayListNode* next;
    ArrayListNode(E v){
      value=v;
      next=NULL;
    }
};

template <class T> 
class ArrayList{
  public:
    ArrayListNode<T>* head;
    int size;
    ArrayList(){
        head=NULL;
        size=0;
    }

    ArrayList(T v){ //With-parameters constructor was missing (from the original code template) so I added 
      head = new ArrayListNode<T>(v);
      size = 1;
    }

    ArrayList(ArrayList<T>& l){
        // your code here
        head=nullptr;
        if (l.head == nullptr){
          return;
        }
        ArrayListNode<T>* current = l.head;
        ArrayListNode<T>* last = new ArrayListNode<T>(current-> value);
        head = last;
        current = current->next;

        while (current != nullptr) {
          last->next = new ArrayListNode<T>(current->value);
          last = last->next;
          current = current->next;
        }
        size = l.size;
    }
    ~ArrayList(){
        // your code here
        ArrayListNode<T>* current = head;
        while(current != nullptr) {
          ArrayListNode<T>* next = current->next;
          delete current;
          current = next;
        }
    }
    void add(T v){
        // your code here
        ArrayListNode<T>* newNode = new ArrayListNode<T>(v);
        if(head == nullptr) {
          head = newNode;
        } else {
          ArrayListNode<T>* current = head;
          while (current->next != nullptr) {
            current = current->next;
          }
          current->next = newNode;
        }
        size++;
    }
    T pop(){
      // your code here
      if (head == nullptr) {
        cout << "the arraylist is empty";
      }

      if(head->next == nullptr) {
        T value = head->value;
        delete head; 
        head = nullptr;
        size--;
        return value;
      }
      
      ArrayListNode<T>* current = head;
      while (current ->next->next !=nullptr) {
        current = current->next;
      }
      T value = current->next->value;
      delete current ->next;
      current->next = nullptr;
      size--;
      return value;
    }

    bool operator==(const ArrayList<T>& rhs){
      // your code here
      if (size != rhs.size) return false;

      ArrayListNode<T>* current1 = head;
      ArrayListNode<T>* current2 = rhs.head;
      while (current1 != nullptr) {
        if (current1->value !=current2-> value) return false;
        current1 = current1->next;
        current2 = current2->next;
      }
      return true;
    }

    bool operator!=(const ArrayList<T>& rhs){
      // your code here
      return !(*this ==rhs); //refer to operator==
    }
    template <class E> 
    friend ostream& operator<<(ostream& os, ArrayList<E>& l);
};
template <class E> 
ostream& operator<<(ostream& os, ArrayList<E>& l){
    // your code here
    ArrayListNode<E>* current = l.head;
    os << "[";
    while (current != nullptr) {
      os << current-> value;
      if (current->next != nullptr) os << ", ";
      current = current->next;
    }
    os << "]";
    return os;
}