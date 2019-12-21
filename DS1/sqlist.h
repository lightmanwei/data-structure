#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

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
char FILE_NAME[100] = "/Users/gikosei/Desktop/DS+dad/output";

typedef int status;
typedef int ElemType; //数据元素类型定义
typedef struct {  //顺序表（顺序结构）的定义
    ElemType *elem;
    int length;
    int listsize;
} SqList;

//测试用函数
status createList(SqList &L, int n);

status InitList(SqList &L);

status DestroyList(SqList &L);

status ClearList(SqList &L);

status ListEmpty(SqList L);

int ListLength(SqList L);

status GetElem(SqList L, int i, ElemType &e);

int LocateElem(SqList L, ElemType e) ;

status
PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) ;

status
NextElem(SqList L, ElemType cur_e, ElemType &next_e) ;

status ListInsert(SqList &L, int i, ElemType e) ;

status ListDelete(SqList &L, int i, ElemType &e) ;

status ListTraverse(SqList L) ;

/*---------------选做-----------------*/

status f_write(SqList l, char *file_name) ;

status f_read(SqList &L, char *file_name) ;