#include <iostream>
#include <stack>
using namespace std;

class Dequeue{
    stack <int> left;
    stack <int> right;
    int size = 0;
    
    public:
    
    Dequeue () = default;
    ~Dequeue() = default;
    
    int get_size() const{
        return size;
    }
    void reset(){
        while(!left.empty()) left.pop();
        while(!right.empty()) right.pop();
        size = 0;
    }
    int front()  {
        if(left.empty() && right.empty() ){
            cout<<"Dequeue is empty : \n";
            exit(1);
        }    
        else {
            if(right.empty()){
                    while(!left.empty()){
                        right.push(left.top());
                        left.pop();
                    }
            }     
        }    
        return right.top();
    }
    int back()  {
        if(left.empty() && right.empty()){
            cout<<"Dequeue is empty : \n";
            exit(1);
        }    
        else{
            if(left.empty()){
                    while(!right.empty()){
                        left.push(right.top());
                        right.pop();
                    }
            }     
        }    
        return left.top();
    } 
    
    void print() {
        stack <int> save;
        cout<<"head => ";
        while(!right.empty()){
            cout<<right.top()<<"-> ";
            save.push(right.top());
            right.pop();
        }
        while(!left.empty()){
            right.push(left.top());
            left.pop();
        }
        while(!right.empty()){
            cout<<right.top()<<"-> ";
            save.push(right.top());
            right.pop();
        }
        while(!save.empty()){
            right.push(save.top());
            save.pop();
        }
        cout<<" <= tail\n";
    }
    
    void push_front(int element){
        right.push(element);
        size++;
    }
        
    void push_back(int element){
        left.push(element);
        size++;
    }
    
    void pop_front() {
        if(right.empty() && left.empty()) return;
        if(right.empty()){
            while(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        right.pop();
        size--;
    }
    
    void pop_back() {
        if(right.empty() && left.empty()) return;
        if(left.empty()){
            while(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        left.pop();
        size--;
    }
};


int main()
{
  Dequeue d1;
  d1.push_front(1);
  d1.push_front(2);
  d1.push_front(3);
  d1.push_front(4);
  d1.push_back(5);
  d1.push_back(6); // 4 3 2 1 5 6
  d1.print();
  d1.pop_back();
  d1.pop_front();
  d1.print(); // 3 2 1 5
}

