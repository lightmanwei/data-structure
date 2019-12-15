#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define LLIST_SIZE 10
//文件绝对路径
char FILE_NAME[100] = "/Users/gikdadasosei/Desktop/DS+/DS2/outputs.txt";

typedef int status;
typedef int ElemType; //数据元素类型定义
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

status InitList(LinkList &L);

status DestroyList(LinkList &L) ;

status ClearList(LinkList &L) ;

status ListEmpty(LinkList L) ;

int ListLength(LinkList L);

status GetElem(LinkList L, int i, ElemType &e);

int LocateElem(LinkList L, ElemType e);

status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);

status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);

status ListInsert(LinkList &L, int i, ElemType e);

status ListDelete(LinkList &L, int i, ElemType &e);

void CreateList(LinkList &L, int number);

status ListTraverse(LinkList L);

status f_write(LinkList L, char *file_name);

status f_read(LinkList &L, char *file_name);