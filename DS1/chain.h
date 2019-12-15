#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define LLIST_SIZE 10
//文件相对路径
char FILE_NAME[100] = "/Users/gikosei/Desktop/DS+/output";

typedef int status;
typedef int ElemType; //数据元素类型定义
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

status InitList(LinkList L) {
    if (L && L->next) {
        printf("List already exits!\n");
        return ERROR;
    } else {
        LinkList L = (LinkList) malloc(sizeof(LNode));
        L->next = NULL;
        return OK;
    }
}

status DestroyList(LinkList L) {
    if (!L)
        return OK;
    else {
        LinkList free_p=L;
        LinkList next_p=free_p->next;
        while (next_p){
            free(free_p);
            free_p=next_p;
            next_p=next_p->next;
        }
        free(next_p);
        return OK;
    }
}


void CreateList(LinkList *L, int number) {
    LinkList p, t;
    *L = (LinkList) malloc(sizeof(LNode));
    t = (*L);
    for (int i = 0; i < number; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = i;
        t->next = p;
        t = p;
        printf("%d ", p->data);
    }
    p->next = NULL;
}

void PrintList(LinkList L) {
    while (L) {
        printf("%d    ", (L)->data);
        L = (L)->next;
    }
}