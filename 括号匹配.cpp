#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<char>s;
char c[22];
int len;
bool flag = true;
int main()
{
  s.push('#');
  scanf("%s",c);
  len = strlen(c);
  for (int i = 0; i < len; i ++)
  {
  	if (c[i] == '{' || c[i] == '[' || c[i] == '(')
  	{
  		s.push(c[i]);
	}
	if (c[i] == '}' || c[i] == ']' || c[i] == ')')
	{
		if (c[i] == ')' && s.top()!= '(')
		{
			flag = false;
			break;
		}
		if (c[i] == '}' && s.top() != '{')
		{
			flag = false;
			break;
		}
		if (c[i] == ']' && s.top() != '[')
		{
			flag = false;
			break;
		}
		s.pop();
	}
  }
  if (! s.empty())
  {
  	flag = false;
  }
  if (flag == true)
  printf("true");
  else
  printf("false");
  return 0;
}