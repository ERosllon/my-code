#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<char>s;
char c[101];
int len;
int pri(char x)
{
	if (x == '+' || x == '-')
	{
		return 2;
	}
	if (x == '*' || x == '/')
	{
		return 1;
	}
	if (x == ')')
	{
		return 0;
	}
	return 10;
}
int main()
{
  scanf("%s", c);
  len = strlen(c);
  for (int i = 0; i < len; i ++)
  {
    if (c[i] >= '0' && c[i] <= '9')
    {
    	printf("%c", c[i]);
	}
	else
	{
		if (s.empty())
		  s.push(c[i]);
		else
		{
			if (c[i] == ')')
			{
				while (s.top() != '(')
				{
					printf("%c", s.top());
					s.pop();
				}
				s.pop();
				
			}
			else if (c[i] == '(')
			{
				s.push(c[i]);
			}
			else
			if (pri(c[i]) >= pri(s.top()))
			{
				printf ("%c", s.top());
				s.pop();
				s.push(c[i]);
			}
			else
			{
				s.push(c[i]);
			}
		}
	}
  }
  while (!s.empty())
  {
  	 printf("%c", s.top());
  	 s.pop();
  }
  return 0;
}
