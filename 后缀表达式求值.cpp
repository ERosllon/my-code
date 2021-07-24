#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<double>s1, s2;
int ans, len, x, y;
char op;
char c[22];
int main()
{
  scanf("%s",c);
  len = strlen(c);
  for (int i = 0; i < len; i ++)
  {
  	if (c[i] >= '0' && c[i] <= '9')
  	s1.push(c[i]-'0');
  	else
  	{
  	x = s1.top();
  			s1.pop();
  			y = s1.top();
  			s1.pop();
  	switch(c[i])
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
    }
  }
  printf("%lf",s1.top());
  return 0;
}
