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
status createList(SqList &L, int n) {
    if (L.listsize < n) {
        L.elem = (ElemType *) realloc(L.elem, (L.listsize +
                                               LISTINCREMENT) *
                                              sizeof(ElemType));
        L.listsize += LISTINCREMENT;
    }
    for (int i = 0; i < n; i++) {
        L.elem[i] = i;
    }
    L.length = n;
}

status InitList(SqList &L) {
    L.elem = (ElemType *) malloc(
            LIST_INIT_SIZE * sizeof(ElemType));
    //分配内存失败
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList &L) {
    if (L.elem) {
        free(L.elem);
    }
    //避免出现野指针
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

status ClearList(SqList &L) {
    //列表不存在
    if (!L.elem)
        return ERROR;
    //length记为0，原有内容不必修改
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
    //表不存在
    if (!L.elem) return ERROR;
    //i 在范围内
    if (i >= 1 && i <= L.length) {
        e = L.elem[i - 1];
        return OK;
    }
        //i 不在范围内
    else return ERROR;
}

int LocateElem(SqList L, ElemType e) {
    //表不存在
    if (!L.elem) return ERROR;
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    //找不到元素
    return 0;
}

status
PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
    //调用LocateElem函数
    int location = LocateElem(L, cur_e);
    //无法定位或者是首元素
    if (location == ERROR || location == 1) {
        return ERROR;
    } else {
        pre_e = L.elem[location - 1 - 1];
        return OK;
    }
}

status
NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
    //调用LocateElem函数
    int location = LocateElem(L, cur_e);
    //无法定位或者是尾元素
    if (location == ERROR || location == L.length) {
        return ERROR;
    } else {
        next_e = L.elem[location - 1 + 1];
        return OK;
    }
}

status ListInsert(SqList &L, int i, ElemType e) {
    //表不存在
    if (!L.elem) return ERROR;
    //表容量不足，分配新存储空间
    if (L.length + 1 > L.listsize) {
        L.elem = (ElemType *) realloc(L.elem, (L.listsize +
                                               LISTINCREMENT) *
                                              sizeof(ElemType));
        L.listsize += LISTINCREMENT;
    }
    //位置超出范围
    if (i < 1 || i > L.length + 1 || !L.elem)
        return ERROR;
    ElemType insert = e;
    //暂存元素
    ElemType reserve;
    //移位
    for (int j = i - 1; j < L.length + 1; j++) {
        reserve = L.elem[j];
        L.elem[j] = insert;
        insert = reserve;
    }
    //加了一个元素，所以length++
    L.length++;
    return OK;
}

status ListDelete(SqList &L, int i, ElemType &e) {
    //表不存在
    if (!L.elem) return ERROR;
    //i超出范围
    if (i < 1 || i > L.length)
        return ERROR;
    ElemType insert;
    e = L.elem[i - 1];
    //移位
    for (int j = i - 1; j < L.length - 1; j++) {
        insert = L.elem[j + 1];
        L.elem[j] = insert;
    }
    //删除一个元素，length--
    L.length--;
    return OK;
}

status ListTraverse(SqList L) {
    //表不存在
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
    //表不存在无法写入文件
    if (!l.elem) return ERROR;
    FILE *file;
    //文件未正常打开
    if ((file = fopen(file_name, "wb")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    fwrite(l.elem, sizeof(ElemType), l.length, file);
    //关闭文件
    fclose(file);
    return OK;
}

status f_read(SqList &L, char *file_name) {
    //表不存在无法读取文件
    if (!L.elem) return ERROR;
    L.length = 0;
    FILE *file;
    //文件未正常打开
    if ((file = fopen(file_name, "rb")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    while (fread(&L.elem[L.length], sizeof(ElemType), 1,
                 file))
        L.length++;
    //关闭文件
    fclose(file);
    return OK;
}
