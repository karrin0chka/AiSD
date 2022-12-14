#include <iostream>
#include <cstdlib>
#define N 5
using namespace std;

class Dequeue
{
    int buffer[N];
    int start = -1, end = 0;

public:
    Dequeue() = default;

    bool IsEmpty() const
    {
        return (start == -1);
    }

    bool IsFull() const
    {
        return ((end + 1) % N == start);
    }

    bool InsertStart(int element)
    {
        if (IsFull())
            return false;
        if (IsEmpty())
            start = end = 0;
        else if (start == 0)
            start = N - 1;
        else
            start--;
        buffer[start] = element;
        return true;
    }

    bool InsertEnd(int element)
    {
        if (IsFull())
            return false;
        if (IsEmpty())
            start = end = 0;
        else
            end = (end + 1) % N;
        buffer[end] = element;
        return true;
    }

    bool DeleteStart()
    {
        if (IsEmpty())
            return false;
        if (start == end)
            start = end = -1;
        else
            start = (start + 1) % N;
        return true;
    }

    bool DeleteEnd()
    {
        if (IsEmpty())
            return false;
        if (start == end)
            start = end = -1;
        else if (end == 0)
            end = N - 1;
        else
            end--;
        return true;
    }

    void print() const
    {
        if (IsEmpty())
            cout << "The qeueu is empty \n";
        else if (end == start)
            cout << buffer[start] << endl;
        else
        {
            cout << "start = ";
            int i = start;
            while (i != end)
            {
                cout << buffer[i] << " -> ";
                i = (i + 1) % N;
            }
            cout << buffer[i] << endl;
        }
    }
};

int main()
{
    Dequeue d1;
    d1.InsertStart(1);
    d1.InsertStart(2);
    d1.InsertStart(3);
    d1.DeleteStart();
    d1.InsertEnd(4);
    d1.DeleteEnd();

    d1.print();
    return 0;
}