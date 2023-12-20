#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	string expression;
  //string expression;
  TPostfix postfix;
  double res;

  setlocale(LC_ALL, "Russian");

  cout << "Введите арифметическое выражение: ";
  cin >> expression;
  cout << expression << endl;
  postfix.Infix(expression);

  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
 
  postfix.ToPostfix();  
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  
  res = postfix.Calculate();
  cout << "Результат выражения: " << res << endl;

  return 0;
}
