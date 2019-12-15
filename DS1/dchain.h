#include "stdlib.h"
#include "stdio.h"

typedef int ElemType;
typedef struct Dnode {
    ElemType data;
    struct Dnode *prior, *next;
} *DuLinkList;

void createDlist(DuLinkList &l, int n) {
    DuLinkList p, t;
    l = (DuLinkList) malloc(sizeof(Dnode));
    t = l;
    for (int i = 1; i <= n; i++) {
        p = (DuLinkList) malloc(sizeof(Dnode));
        p->data = i;
        p->prior = t;
        t->next = p;
        t = p;
        printf("%d ", p->data);
    }
    p->next = l;
    l->prior = p;

}

//a1，a3，...，an，...，a4，a2
void adjust(DuLinkList L) {
    int i=0;
    DuLinkList p,q,s,r;
    q=L;
    p=L;
    p=p->next;
    r=p;
    while (p->next!=L){
        s=p->next;
        i++;
        if(i%2==0){
          q->prior=p;
          p->next=q;
          q=q->prior;
          p=s;
          r->next=s;
          s->prior=r;
          r=r->next;
        } else
            p=p->next;
    }
    p->next=q;
    q->prior=p;
}

void PrintDList(DuLinkList L) {
    DuLinkList p=L->next;
    while (p!=L) {
        printf("%d    ", p->data);
        p = p->next;
    }
}