#include <iostream>
#include <cstdlib>
#define N 5
using namespace std;

class Dequeue {
    int start = -1;
    int end = -1;
    int size = N;
    int * buffer = new int[size];
    
    bool IsFull() const {
        return  (end + 1) % size == start ;
    } 
    
    bool OneElement() const {
        return (start == end && start != -1);
    }
    
public:
    Dequeue() = default;
    ~Dequeue() {
        delete [] buffer;
    }

    Dequeue(const Dequeue & obj) : start(obj.start), end(obj.end), size(obj.size), buffer(new int[size]) {        
        int i = obj.start, j = 0;
        for(int i = 0; i < size; i++) 
            buffer[i] = obj.buffer[i];       
    }
    
    bool IsEmpty() const {
        return (start == end && start == -1);
    }
    
    int get_count() const {
        return (end >= start) ? (end - start + 1) : size - (start - end - 1);                                               
    }
    
    int get_front() const {
        if(IsEmpty()) 
            exit(1);
        return buffer[start];
    }
    
    int get_back() const {
        if(IsEmpty())
            exit(1);
        return buffer[end];
    }
    
    void print() const {
        if(IsEmpty()) return ;
        int i = start;
        while(i != end) {
            cout << buffer[i] << " -> ";
            i = (i + 1)  %size;
        }
        cout << buffer[i] << endl;       
    }
    
    bool pop_front() {
        if(IsEmpty()) 
            return false;
        if(OneElement()) 
            start = end = -1;
        else 
            start = (start + 1) % size;
        return true;
    }
    
    bool pop_back() {
        if(IsEmpty()) 
            return false;
        if(OneElement()) 
            start = end = -1;
        else 
            end = (end - 1 + size) % size;
        return true;
    }

    bool push_front(int element) {
        if(IsEmpty())  
            start = end = 0;
        else {
            if(IsFull()) {
                int * new_buffer = new int[size*2];
                int j = start, i = 0;
                while(j != end) {
                    new_buffer[i] = buffer[j];
                    i++;
                    j = (j + 1) % size;
                }
                new_buffer[i] = buffer[j];
                delete [] buffer;
                buffer = new_buffer;
                start = 0;
                end = i;
                size *= 2;
            }
            start = (start - 1 + size)%size;
        }
        buffer[start] = element;
        return true;
    }

    bool push_back(int element) {
        if(IsEmpty())  
            start = end = 0;
        else {
            if(IsFull()) {
                int * new_buffer = new int[size*2];
                int j = start, i = 0;
                while(j != end) {
                    new_buffer[i] = buffer[j];
                    i++;
                    j = (j + 1) % size;
                }
                new_buffer[i] = buffer[j];
                delete [] buffer;
                buffer = new_buffer;
                start = 0;
                end = i;
                size *= 2;
            }
            end = (end + 1) % size;
        }
        buffer[end] = element;
        return true;
    }

    const Dequeue & operator=(const Dequeue &obj) { // копирующее присвоение
        if (&buffer != &obj.buffer) {
            size = obj.size;
            int i = obj.start, j = 0;
            while (i != obj.end) {
                buffer[j] = obj.buffer[i];
                i = (i + 1) % size;
                j++;
            }
            start = 0;
            end = j;
            buffer[end] = obj.buffer[i];
        }
        return *this;
    }
};

int main() {
    Dequeue q1;
    q1.push_front(1);
    q1.push_back(2);
    q1.push_front(3);
    q1.push_front(4);
    q1.push_back(5);
    q1.pop_back();
    q1.pop_front();
    
    Dequeue q2(q1);
    q1.print();
    q2.print();

    q2 = q1;
    q1.print();
    q2.print();

    return 0;  
}
