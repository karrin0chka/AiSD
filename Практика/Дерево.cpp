#include <iostream>
#include <string>
using namespace std;

class Tree{
    
    class List{
        unsigned int size;
        unsigned char ch;
        bool is_leaf = true;
        List * left = NULL;
        List * right = NULL;
        
        public:
        List (unsigned int _size, unsigned char _ch, bool flag)  {
                size = _size;
                ch = _ch;
                is_leaf = flag;
        }
    };
    
    List * root = NULL;
    int counter = 0; // Общее кол-во узлов дерева.
    
    public:    
    
    Tree() = default;
    
    void define (int * array ){
        string str[10];
         
    }
};

int main()
{
    int A[10] = {5, 10, 13, 15, 20, 30, 33, 36, 67, 100};
    
    return 0;
}


