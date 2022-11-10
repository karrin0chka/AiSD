// leetcode
#include <iostream>
#include <stack>
using namespace std;
/*
  (   0
  )   нет приоритета
  - + 1
  * / 2
  ~   3
  
  1. ( всегда кладется на верхушку стека
  2. ) выталкивает все операторы из стека до первой открытой скобки и вместе с ней они удаляются
  3. операторы с наименьшим или равным приоритетом выталкивают весх остальных операторов из стека
  4. оператор ~(унарный минус) всегда кладется на верхушку стека
  
  2*(-5+--3) => 2*(~5+~~3)  
  очередь: 2 5 ~ 3 ~ ~ + *    стек:
  
  -(4+--(3-2)) => (-1)*(4+(-1)*(-1)*(3-2)) => -1 4 -1 -1 * 3 2 - * + *
*/

double getResult(string & str) {
  stack <double> st;
  double temp = 0, a = 10;
  double first, second;
  bool point = false;
  for (int i = 0; i < str.size(); i++) {
  	if (str[i] >= '0' && str[i] <= '9') {
		while (str[i] != ' ') {
			if (str[i] == '.') {
				point = true;
				i++;
				continue;
			}
			if (point) {
				temp = temp + 1.0 * (str[i] - '0') / a;
				a *= 10;
			}
			else 
				temp = temp * 10 + str[i] - '0';
			i++;
		}
		st.push(temp);
		temp = 0;
		point = false;
		a = 10;
	}
	else {
		first = st.top();
		st.pop();
		second = st.top();
		st.pop();
		switch (str[i]) {
			case '+' :
				st.push(first + second);
				break;
			case '-' :
				st.push(first - second);
				break;
			case '*' :
				st.push(first * second);
				break;
			case '/' :
				st.push(second / first);
				break;
			case '~' :
				st.push(second);
				st.push(-first);
				break;	
		}	
		i++;  // чтобы перейти пробел
  	}  
  }
	return st.top();
};

int main() {  
	string str = "21.3 ~ 1 + 2";
	cout << str;
    return 0;
}
