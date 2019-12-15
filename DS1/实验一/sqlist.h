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
char FILE_NAME[100] = "/Users/gikosei/Desktop/DS+/output";

typedef int status;
typedef int ElemType; //数据元素类型定义
typedef struct {  //顺序表（顺序结构）的定义
    ElemType *elem;
    int length;
    int listsize;
} SqList;

status createList(SqList &L, int n) {
    if (L.listsize < n) {
        L.elem = (ElemType *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        L.listsize += LISTINCREMENT;
    }
    for (int i = 0; i < n; i++) {
        L.elem[i] = i;
    }
    L.length = n;
}//测试用

status InitList(SqList &L) {
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList &L) {
    if (L.elem) {
        free(L.elem);
    }
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

status ClearList(SqList &L) {
    if (!L.elem)
        return ERROR;
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L) {
    if (L.length == 0 || !L.elem)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L) {
    if (!L.elem)
        return 0;
    return L.length;
}

status GetElem(SqList L, int i, ElemType &e) {
    if (!L.elem) return ERROR;
    if (i >= 1 && i <= L.length) {
        e = L.elem[i - 1];
        return OK;
    } else return ERROR;
}

int LocateElem(SqList L, ElemType e) //??compare
{
    if (!L.elem) return ERROR;
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
    int location = LocateElem(L, cur_e);
    if (location == ERROR || location == 1) {
        return ERROR;
    } else {
        pre_e = L.elem[location - 1 - 1];
        return OK;
    }
}

status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
    int location = LocateElem(L, cur_e);
    if (location == ERROR || location == L.length) {
        return ERROR;
    } else {
        next_e = L.elem[location - 1 + 1];
        return OK;
    }
}

status ListInsert(SqList &L, int i, ElemType e) {
    if (!L.elem) return ERROR;
    if (L.length + 1 > L.listsize) {
        L.elem = (ElemType *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        L.listsize += LISTINCREMENT;
    }
    if (i < 1 || i > L.length + 1 || !L.elem)
        return ERROR;
    ElemType insert = e;
    ElemType reserve;
    for (int j = i - 1; j < L.length + 1; j++) {
        reserve = L.elem[j];
        L.elem[j] = insert;
        insert = reserve;
    }
    L.length++;
    return OK;
}

status ListDelete(SqList &L, int i, ElemType &e) {
    if (!L.elem) return ERROR;
    if (i < 1 || i > L.length)
        return ERROR;
    ElemType insert;
    e = L.elem[i - 1];
    for (int j = i - 1; j < L.length - 1; j++) {
        insert = L.elem[j + 1];
        L.elem[j] = insert;
    }
    L.length--;
    return OK;
}

status ListTraverse(SqList L) {
    if (!L.elem) {
        printf("线性表未定义\n");
        return ERROR;
    }
    int i;
    printf("\n-----------all elements -----------------------\n");
    for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L.length;
}

/*---------------选做-----------------*/

status f_write(SqList l, char *file_name) {
    if (!l.elem) return ERROR;
    FILE *file;
    if ((file = fopen(file_name, "wb")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    fwrite(l.elem, sizeof(ElemType), l.length, file);
    fclose(file);
    return OK;
}

status f_read(SqList &L, char *file_name) {
    if (!L.elem) return ERROR;
    L.length = 0;
    FILE *file;
    if ((file = fopen(file_name, "rb")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    while (fread(&L.elem[L.length], sizeof(ElemType), 1, file))
        L.length++;
//这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读取的数据元素恢复内存中的物理结构。
    fclose(file);
    return OK;
}
