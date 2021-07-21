struct stack{
  bool empty()
  {
  	return TOP == -1 ?  true:false;
  }
  void push(int x)
  {
  	c[++TOP] = x;
  }
  void pop()
  {
  	TOP --;
  }
  int top()
  {
  	return c[TOP];
  }
  int size()
  {
  	return TOP;
  }
  void clear()
  {
  	TOP = -1;
  }
  private:
  int TOP = -1;
  int c[101];
}x;