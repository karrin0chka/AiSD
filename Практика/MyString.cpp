#include <iostream>
#include <cstring>
using namespace std;

// 1.Необходимо реализовать для данного класса оператор копирующего присваивания. 2. Перегрузка оператора +=.3. Оператор +.
class String
{
    char *buffer = NULL;
    unsigned int size = 0;

public:
    String() = default; // для пустой строки

    String(const char *str) {
        if(str) {
            size = strlen(str);
            buffer = new char[size + 1];
            strcpy(buffer, str);
        }
    }

    String(const String &str) {
        size = str.size;
        buffer = new char[size + 1];
        strcpy(buffer, str.buffer);
    }

    ~String() {
        delete [] buffer;
    }

    char &operator[](int i) {
        if (i >= 0 && i < size)
            return buffer[i];
        else
            exit(1);
    }

    const char &operator[](int i) const {
        if (i >= 0 && i < size)
            return buffer[i];
        else
            exit(1);
    }

    String & operator=(const String &str) {
        if(buffer) {
            delete [] buffer;
        }
        size = strlen(str.buffer);
        buffer = new char[size + 1];
        strcpy(buffer, str.buffer);

        return *this;
    }

    String operator+(const String &str)
    {
        String newStr;

        int size_buffer = strlen(buffer);
        size = strlen(str.buffer);
        newStr.buffer = new char[size_buffer + size + 1];
        
        strcpy(&newStr.buffer[0], buffer);
        strcpy(&newStr.buffer[size_buffer], str.buffer);
        
        return newStr;
    }

    String &operator+=(const String &str)
    {
        String newStr;
        int size_buffer = strlen(buffer);
        size = strlen(str.buffer);
        newStr.buffer = new char[size_buffer + size + 1];

        strcpy(&newStr.buffer[0], buffer);
        strcpy(&newStr.buffer[size_buffer], str.buffer);

        *this = newStr;
        return *this;
    }


    friend ostream &operator<<(ostream &, const String &);
};

ostream &operator<<(ostream &out, const String &str) {

    if (str.buffer)
        out << str.buffer << endl;
    else
        out << "The string is empty\n";
    return out;
}

int main()
{
    String str1("f");
    String str2("Hello ");
    String str3("World");
    str1 = str2;
    cout << str1;

    String str4(str1);
    cout <<  str4;

    cout << str1[2] << endl;
    str1[2] = 'X';
    cout << str1;

    String result = str2 + str3;
    cout << result;

    str2 = "lk";
    cout << &str2 << endl;
    str3 = "sdd";
    str2 += str3;
    cout << str2;

    cout << &str2;
    return 0;
}