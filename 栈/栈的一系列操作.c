/*    顺序栈   */
//置空栈
SeqStack * InitStack()
{
  SeqStack * s;
  s = (SeqStack *)malloc(sizeof(SeqStack));
  s->top = -1;
  return s;
}

