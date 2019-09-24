/*    顺序栈   */
//置空栈
SeqStack * InitStack()
{
  SeqStack * s;
  s = (SeqStack *)malloc(sizeof(SeqStack));
  s->top = -1;
  return s;
}

//判空栈
int Empty(SeqStack * s)
{
  if(s->top == -1) return 1;
  else return 0;
}
