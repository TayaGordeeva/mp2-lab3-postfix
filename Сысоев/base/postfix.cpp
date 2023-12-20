#include "postfix.h"
#include "stack.h"
#include "iostream"
using namespace std;

string TPostfix::ToPostfix()
{  
	TStack<char> s(100);
	char o;
  for (int i = 0; i < size(infix); i++)
  {
	  int t=-5;
	  if ((int(infix[i]) - int('0') >= 0) && (int(infix[i]) - int('0') < 10)) t = -1;
	  else if (infix[i] == '(') t = 0;
	  else if (infix[i] == ')') t = -2;
	  else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/')) t = 1;
	  /*else throw ("wrong lexem");*/
	

	  switch (t)
	  {
		case -1:
			postfix += infix[i];
			break;

		case 0:
			s.Push(infix[i]);
			break;

		case 1:
			int l, k;
						
			if ((infix[i] == '+') || (infix[i] == '-')) l = 1;
			else l = 2;
			while (!(s.IsEmpty()))
			{
				o = s.Top();
				if ((o == '+') || (o == '-')) k = 1;
				else if ((o == '*') || (o == '/')) k = 2;
				else k = 0;

				if (l <= k) postfix += o;
				else {
					s.Push(o);
					break;
     			}
			}
			s.Push(infix[i]);
			break;

		case -2:
			o = s.Top();
			while ((o != '(') && (!s.IsEmpty()))
			{
				postfix += o;
				o =s.Top();
			}
			break;

		default:
			throw("wrong");
			
	  }
  }
  while (!(s.IsEmpty()))
			{
				postfix += s.Top();
			}

  return postfix;
}

 double TPostfix::Calculate() {
	 TStack <double> st(100);
	 double lft, rgt;
	 for (char lexem : postfix)
	 {
		 switch (lexem)
		 {
		 case '+':
			 rgt = st.Top();
			 lft = st.Top();
			 st.Push(lft + rgt);
			 break;
		 
		 case '-':
			 rgt = st.Top();
			 lft = st.Top();
			 st.Push(lft - rgt);
			 break;

		 case '*':
			 rgt = st.Top();
			 lft = st.Top();
			 st.Push(lft * rgt);
			 break;
		 
		 case '/':
			 rgt = st.Top();
			 lft = st.Top();
			 st.Push(lft / rgt);
			 break;

		 default:
			 st.Push(int(lexem)-int('0'));
		 }
		 
	 }
return st.Top();
}
