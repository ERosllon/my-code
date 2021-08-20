#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int>s1;
stack<char>s2;
char c[1001];
int len;
int pri(char x)
{
  if (x == '+' || x == '-')
  {
	  return 0;
  }
  if (x == '*' || x == '/')
  {
	  return 1;
  }
  if (x == ')')
  {
  	return 2;
  }
  return 3;
}
void ope(char z)
{
  int x = s1.top();
  s1.pop();
  int y = s1.top() ;
  s1.pop();
  switch(z)
  {
  	case '+':
  		s1.push(x + y);
  		break;
  	case '-':
  		s1.push(y - x);
  		break;
  	case '*':
  		s1.push(y * x);
  		break;
  	case '/':
  		s1.push(y / x);
  		break;
  }
  return;
}
int main()
{
  scanf ("%s", c);
  len = strlen(c);
  for (int i = 0; i < len; i ++)
  {
  	if (c[i] >= '0' && c[i] <= 9)
  	s1.push(c[i] - '0');
  	else
  	{
  		if (s2.empty())
  		  s2.push (c[i]);
  		else
  		{
	  		int temp = pri(c[i]);
	  		if (c[i] == ')')
	  		{
	  			while (s2.top() != '(')
	  			{
	  				ope(s2.top());
	  				s2.pop();
				}
				s2.pop();
			}
			else if (c[i] == '(')
			{
				s2.push(c[i]);
			}
			else
			{
				if (temp <= pri(s2.top()))
				{
					ope(s2.top());
					s2.pop();
					s2.push(c[i]); 	
				}
				else 
				{
					s2.push(c[i]);
				}
			}	
		}
	}
  }
  while (!(s1.empty() || s2.empty()))
  {
  	 ope (s2.top());
  	 s2.pop();
  }
  printf ("%d", s1.top());
  s1.pop ();
  return 0;
}
