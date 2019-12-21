#include "sqlist.h"

int main(void) {
    
    SqList LList[LLIST_SIZE]={NULL};
    int list_num;
    InitList(LList[0]);
    createList(LList[0], 15);
    ElemType e, result;
    int location;
    int op = 1;
    while (op) {
        system("clear");
        printf("\n\n");
        printf("选择一个线性表(输入序号，默认1-10)\n");
        scanf("%d",&list_num);
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       7. LocateElem\n");
        printf("    	  2. DestroyList    8. PriorElem\n");
        printf("    	  3. ClearList      9. NextElem \n");
        printf("    	  4. ListEmpty      10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem        12. ListTrabverse\n");
        printf("    	  13. FileWrite     14. FileRead\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                //printf("\n----IntiList功能待实现！\n");
                if (InitList(LList[list_num-1]) == OK) printf("线性表创建成功！\n");
                else printf("线性表创建失败！\n");
                getchar();
                getchar();
                break;
            case 2:
                //printf("\n----DestroyList功能待实现！\n");
                if (DestroyList(LList[list_num-1]) == OK) printf("线性表销毁成功！\n");
                else printf("线性表销毁失败！\n");
                getchar();
                getchar();
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                if (ClearList(LList[list_num-1]) == OK) printf("线性表清空成功！\n");
                else printf("线性表清空失败！\n");
                getchar();
                getchar();
                break;
            case 4:
                //printf("\n----ListEmpty功能待实现！\n");
                if (ListEmpty(LList[list_num-1]) == TRUE) printf("线性表为空！\n");
                else printf("线性表不为空！\n");
                getchar();
                getchar();
                break;
            case 5:
                //printf("\n----ListLength功能待实现！\n");
                printf("线性表的长度为：%d", ListLength(LList[list_num-1]));
                getchar();
                getchar();
                break;
            case 6:
                //printf("\n----GetElem功能待实现！\n");
                printf("获取元素的位置是：\n");
                scanf("%d", &location);
                if (GetElem(LList[list_num-1], location, e) == OK) printf("线性表第%d个元素是%d\n", location, e);
                else printf("位置有误！\n");
                getchar();
                getchar();
                break;
            case 7:
                //printf("\n----LocateElem功能待实现！\n");
                printf("获取位置的元素是：\n");
                scanf("%d", &e);
                if (location = LocateElem(LList[list_num-1], e)) printf("线性表%d的位置是%d\n", e, location);
                else printf("没有%d元素\n", e);
                getchar();
                getchar();
                break;
            case 8:
                //printf("\n----PriorElem功能待实现！\n");
                printf("要获取前继元素是：\n");
                scanf("%d", &e);
                if (PriorElem(LList[list_num-1], e, result) == OK) printf("线性表%d的前继是%d\n", e, result);
                else printf("%d元素没有前继\n", e);
                getchar();
                getchar();
                break;
            case 9:
                //printf("\n----NextElem功能待实现！\n");
                printf("要获取后继元素是：\n");
                scanf("%d", &e);
                if (NextElem(LList[list_num-1], e, result) == OK) printf("线性表%d的后继是%d\n", e, result);
                else printf("%d元素没有后继\n", e);
                getchar();
                getchar();
                break;
            case 10:
                //printf("\n----ListInsert功能待实现！\n");
                printf("要插入的元素是：\n");
                scanf("%d", &e);
                printf("插入的位置是：\n");
                scanf("%d", &location);
                if (ListInsert(LList[list_num-1], location, e) == OK) printf("插入成功\n");
                else printf("插入失败\n");
                getchar();
                getchar();
                break;
            case 11:
                //printf("\n----ListDelete功能待实现！\n");
                printf("要删除的位置是：\n");
                scanf("%d", &location);
                if (ListDelete(LList[list_num-1], location, e) == OK) printf("删除成功，删除的元素是%d\n", e);
                else printf("删除失败\n");
                getchar();
                getchar();
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                if (!ListTraverse(LList[list_num-1])) printf("线性表是空表！\n");
                getchar();
                getchar();
                break;
            case 13:
                //f_write
                if (f_write(LList[list_num-1],FILE_NAME)==OK) printf("写入文件成功\n");
                else printf("写入文件失败\n");
                getchar();
                getchar();
                break;
            case 14:
                //f_read
                if (f_read(LList[list_num-1],FILE_NAME)==OK) printf("读取线性表成功\n");
                else printf("读取线性表失败\n");
                getchar();
                getchar();
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}

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
