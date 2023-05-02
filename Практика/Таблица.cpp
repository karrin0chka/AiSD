#include <iostream>
#include <string>
using namespace std;


class Table{
    
    class Student{
        string name;
        int age;
        int id;
        static int counter;
        
        public:
        Student (string name, int age) : name(name), age(age) {
            counter++;
            id = counter;
        }
        static int get_counter(){
            return counter;
        }
        void print() const{
            cout<<" id = "<<id<<" name = "<<name<<" age = "<<age<<endl;
        }
        string get_name() const{
            return name;
        }
        int get_id() const{
            return id;
        }
    };
    
    class List{
    
        Student * object = NULL;  
        List * next = NULL;
        bool is_exist = true;
         
        public:
        List (Student * p) : object(p) {}
        List () = default;
        ~List() {
        }
        Student * get_object() const{
            return object;
        }
        bool get_flag() const{
            return is_exist;
        }
        List * get_next() const{
            return next;
        }
        void set_next(List * p){
            next = p;
        }
        void set_flag_false(){
            is_exist = false;
        }
    };
        
        List  **  buffer = NULL; // Таблица.
        int size = 100;  // Размер таблицы.
        int count = 0; // Кол-во всех объектов в таблице.
        int elem = 0; // Кол-во актуальных элементов в таблице.
    
    public:        
        Table () {
            buffer =  new List * [size]{NULL};   
        }
        ~Table(){
            List  * p;
            List * p_next;
            Student * st;
            for(int i = 0; i < size; i++){
                p = buffer[i];
                while(p){
                    if(p->get_flag()){
                        st = p->get_object();
                        delete st;
                    }
                    p_next = p->get_next();
                    delete p;
                    p = p_next;
                }
            }
            delete [] buffer;
        }
        
    bool inseart(string _name, int _age) {
         int code = get_hash_code(_name); 
         Student * sp = new Student(_name, _age);
         List * lp = new List(sp);
         if(sp == NULL || lp == NULL) return false;
         if(buffer[code] == NULL) buffer[code] = lp;
         else {
                lp->set_next(buffer[code]);
                buffer[code] = lp;
         }
         count++;
         elem++;
         return true;
    }
    
    void print(){   
        List * p;
        Student * sp;
        for(int i = 0; i < size; i++){
            p = buffer[i];
            while(p){
                if(p->get_flag()) {
                    sp = p->get_object();
                    sp->print();
                }
                p = p->get_next();
            }
        }
    }
    
    bool delete_by_name(string _name) {
        int code = get_hash_code(_name);
        List * p = buffer[code];
        Student * sp ;
        bool is_deleted = false;
        if(p == NULL) return false;
        while(p){
            if(p->get_flag()) {
                sp = p->get_object();
                if( sp->get_name() == _name )
                {
                    delete sp;
                    elem--;
                    p->set_flag_false();
                    is_deleted = true;
                }
            }
            p = p->get_next();
        } 
        return is_deleted;
    }
    
    bool delete_by_id(int _id){  
        List * p = NULL;    
        for(int i = 0; i < size; i++){
                p = buffer[i];
                if(p){
                    while(p){    
                        if(p->get_flag() && ((p->get_object())->get_id() == _id ) ){
                            delete  p->get_object();
                            p->set_flag_false();
                            return true;
                        }
                        p = p->get_next();
                    }
                }
        }
        return false;    
    }    
    /*
    bool select_by_name(string _name){
    
    }
      */  
    int get_hash_code (string str)
    {
        int hash_code = 0;
        for(int i = 0; i < str.size(); i++) hash_code += str[i]; 
        return hash_code % size;
    }
        
};

int Table::Student::counter;

int main()
{
    Table t1;
    t1.inseart("Petya",19);
    t1.inseart("Ivan", 20);
    t1.inseart("Petya",21);
    t1.delete_by_name("Petya");
    t1.inseart("Vasya",20);
    t1.delete_by_id(4);
    t1.print();
    
    return 0;
}
