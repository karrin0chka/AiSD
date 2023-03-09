// Example program
#include <iostream>
#define _SIZE 5
using namespace std;

/*
    pop
    push
    empty
    top
    size
    swap
*/

class Stack
{
    int top = -1;
    int size = _SIZE;
    int *buffer = new int[size];

    bool full() const {
        return (top == size - 1);
    }

public:
    Stack() = default;
    Stack(const Stack &st) : top(st.top), size(st.size),
                             buffer(new int[size]) {
        for (int i = 0; i <= top; i++)
            buffer[i] = st.buffer[i];
    }

    Stack &operator=(const Stack &st) {
        if (this != &st) {
            if(size > st.get_size()) {
                for (int i = 0; i <= st.top; i++) 
                    buffer[i] = st.buffer[i];
                top = st.top;                
            }
        }
        else {
            int * new_buffer = new int[st.size];
        
        }
        return *this;
    }

    bool empty() const {
        return (top == -1);
    }

    bool pop() {
        if (empty())
            return false;
        top--;
        return true;
    }

    int get_size() const {
        return top + 1;
    }

    int get_top() const {
        if (empty())
            exit(1);
        return buffer[top];
    }

    bool push(int element) {
        if (full()) {
            int *new_buffer = new int[size * 2];
            if (!new_buffer)
                return false;
            for (int i = 0; i <= top; i++)
                new_buffer[i] = buffer[i];
            size *= 2;
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[++top] = element;
        return true;
    }
};

int main() {
    Stack st1;

    return 0;
}