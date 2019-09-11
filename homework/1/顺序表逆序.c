//单链表
void Reverse(LinkList H)
{
  LNode *p,*q;
  p = H->next;
  H->next = NULL;
  while(p)
  {
     q = p;
     p = p->next;
     H->next = q;
     }
     }
