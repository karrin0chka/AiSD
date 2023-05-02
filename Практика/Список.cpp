#include <iostream>
using namespace std;

class List{
    int a;
    double d;
    List * next;
    static int counter;
    static List * head;
    static List * tail;
        
    List(int _a = 0, double _d = 0.0) : a(_a), d(_d), next(NULL) {
                counter++;
    } 
    ~List(){
        counter--;              
    }
    public:
    
    static bool IsEmpty(){
        return (head == tail && head == NULL);          
    }
    
    static bool push_front(int a, double d){
        List * p = new List(a, d);
        if(!p) return false;
        if(IsEmpty()) head = tail = p; 
        else{
          p->next = head;
          head = p;
        }
        return true;
    }
    
    static bool push_back(int a, double d){
        List * p = new List(a, d);
        if(!p) return false;
        if(IsEmpty()) head = tail = p;
        else{
            tail->next = p;
            tail = p;
        }   
        return true;
    }
    
    static void print_list(){
    
        if(IsEmpty()) {
            cout<<"The List is empty :\n";
            return;
        }          
        List * p = head;
        while(p){
            cout<<"["<<p->a<<" "<<p->d<<"] --> ";
            p = p->next;
        }
        cout<<"NULL"<<endl;
    }
    
    
    static void delete_list(){
        if(IsEmpty()) return;
        List * p;
        while(head){
            p = head->next;
            delete head;
            head = p;
        }
        head = tail = NULL;
    }
    
    static bool pop_front(){        
        if(IsEmpty()) return false;       
        if(head == tail){
            delete head;
            head = tail = NULL;
        }                
        else{
            List * p = head->next;
            delete head;
            head = p;
        }
        return true;
    }
    
    
    static bool pop_back(){
        if(IsEmpty()) return false;       
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            List * p = head;    
            while((p->next)->next) p = p->next;
            delete tail;
            p->next = NULL;
            tail = p;
        }
        return true;
    }
    
    
    
};

int    List::counter = 0;
List * List::head = NULL;
List * List::tail = NULL;

int main()
{
    List::push_front(1, 2.2);
    List::push_front(2, 3.3);
    List::push_back(3,4.3);
    List::push_back(4,5.5);
    // [2 3.3] --> [1 2.2] --> [3 4.3] --> [4 5.5] --> NULL
   
     //List::delete_list();
    List::pop_front();
    List::pop_back();
    List::print_list();
    return 0;  
}

