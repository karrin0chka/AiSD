#include <iostream>
using namespace std;

class Dequeue {

class Node{

    int element;
    Node * next = NULL;
    Node * prev = NULL;
    
    public:
    ~Node() = default;
    
    Node (int n): element(n) {}
    
    int get_element() const{
        return element;
    }
    Node * get_next() const{
        return next;
    }
    Node * get_prev() const{
        return prev;
    }
    void set_element(int n){
        element = n;
    }
    void set_next(Node * pointer){
        next = pointer;
    }
    void set_prev(Node * pointer){
        prev = pointer;
    }
    
};
    Node * head = NULL;
    Node * tail = NULL;
    int counter = 0;
    
    public:
    
    Dequeue() = default;
    
    bool IsEmpty() const {
         return (counter == 0);
    }
    
    bool push_front(int n){
        Node * p = new Node(n);
        if(!p) return false;
        if(IsEmpty()) head = tail = p;
        else {
            head->set_prev(p);
            p->set_next(head);
            head = p;
        }
        counter++;
        return true;
    }
    bool push_back(int n){
        Node * p = new Node(n);
        if(!p) return false;    
        if(IsEmpty()) head = tail = p;
        else{
            tail->set_next(p);
            p->set_prev(tail);
            tail = p;
        }
        counter++;
        return true;   
    }
    
    bool pop_front(){
        if(IsEmpty())  return false;  
        if(counter == 1){
            delete head;
            head = tail = NULL;
        }
        else {
            Node * p = head->get_next();
            p->set_prev(NULL);
            delete head;
            head = p;
        }
        counter--;
        return true;
    }
    
    bool pop_back(){
        if(IsEmpty())  return false;
        if(counter == 1) {
            delete tail;
            head = tail = NULL;
        }
        else {
            Node * p = tail->get_prev();
            p->set_next(NULL);
            delete tail;
            tail = p;
        }
        counter--;
        return true;
    }

    int get_front() const{
        if(IsEmpty()) exit(1);
        return head->get_element();
    }
    int get_back() const{
        if(IsEmpty()) exit(1);
        return tail->get_element();
    }
    
    void get_node(){
            Node * p = head;
            while(p){
                cout<<p->get_element()<<" -> ";
                p = p->get_next();
            }
    }
    
void reset();

 //   Node * find_element(int n) {};
 //   void delete_element(int n) {};

friend ostream& operator<<(ostream& , Dequeue & );
};

ostream& operator<<(ostream& out, Dequeue & D){
        if(D.IsEmpty()) cout<<"Dequeue is empty \n";
        else D.get_node();
    return out;    
}


int main()
{
    Dequeue D1;
    D1.push_front(1);
    D1.push_front(2);
    D1.push_back(3); // 2 1 3
    //D1.pop_front(); // 1 3
   // D1.pop_back(); // 1
    cout<<D1.get_front()<<" "<<D1.get_back()<<endl;
    cout<<D1;
    return 0;
} 
