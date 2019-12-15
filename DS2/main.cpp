#include "chain.h"

int main(void) {

    LinkList LList[LLIST_SIZE] = {NULL};
    int list_num;
    CreateList(LList[0], 15);
    ElemType e, result;
    int location;
    int op = 1;
    while (op) {
        system("clear");
        printf("\n\n");
        printf("选择一个线性表(输入序号，默认1-10)\n");
        scanf("%d", &list_num);
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       8. PriorElem\n");
        printf("    	  2. DestroyList    9. NextElem \n");
        printf("    	  3. ClearList      10. ListInsert\n");
        printf("    	  4. ListEmpty      11. ListDelete\n");
        printf("    	  5. ListLength     12. ListTrabverse\n");
        printf("    	  6. GetElem        13. FileWrite\n");
        printf("    	  7. LocateElem     14. FileRead\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~14]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                //printf("\n----IntiList功能待实现！\n");
                if (InitList(LList[list_num - 1]) == OK) printf("线性表创建成功！\n");
                getchar();
                getchar();
                break;
            case 2:
                //printf("\n----DestroyList功能待实现！\n");
                if (DestroyList(LList[list_num - 1]) == OK) printf("线性表销毁成功！\n");
                else printf("线性表销毁失败！\n");
                getchar();
                getchar();
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                if (ClearList(LList[list_num - 1]) == OK) printf("线性表清空成功！\n");
                else printf("线性表清空失败！\n");
                getchar();
                getchar();
                break;
            case 4:
                //printf("\n----ListEmpty功能待实现！\n");
                if (ListEmpty(LList[list_num - 1]) == TRUE) printf("线性表为空！\n");
                else printf("线性表不为空！\n");
                getchar();
                getchar();
                break;
            case 5:
                //printf("\n----ListLength功能待实现！\n");
                printf("线性表的长度为：%d", ListLength(LList[list_num - 1]));
                getchar();
                getchar();
                break;
            case 6:
                //printf("\n----GetElem功能待实现！\n");
                printf("获取元素的位置是：\n");
                scanf("%d", &location);
                if (GetElem(LList[list_num - 1], location, e) == OK) printf("线性表第%d个元素是%d\n", location, e);
                getchar();
                getchar();
                break;
            case 7:
                //printf("\n----LocateElem功能待实现！\n");
                printf("获取位置的元素是：\n");
                scanf("%d", &e);
                if (location = LocateElem(LList[list_num - 1], e)) printf("线性表元素%d的位置是%d\n", e, location);
                else printf("没有%d元素\n", e);
                getchar();
                getchar();
                break;
            case 8:
                //printf("\n----PriorElem功能待实现！\n");
                printf("要获取前继元素是：\n");
                scanf("%d", &e);
                if (PriorElem(LList[list_num - 1], e, result) == OK) printf("线性表%d的前继是%d\n", e, result);
                else printf("%d元素没有前继\n", e);
                getchar();
                getchar();
                break;
            case 9:
                //printf("\n----NextElem功能待实现！\n");
                printf("要获取后继元素是：\n");
                scanf("%d", &e);
                if (NextElem(LList[list_num - 1], e, result) == OK) printf("线性表%d的后继是%d\n", e, result);
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
                if (ListInsert(LList[list_num - 1], location, e) == OK) printf("插入成功\n");
                else printf("插入失败\n");
                getchar();
                getchar();
                break;
            case 11:
                //printf("\n----ListDelete功能待实现！\n");
                printf("要删除的位置是：\n");
                scanf("%d", &location);
                if (ListDelete(LList[list_num - 1], location, e) == OK) printf("删除成功，删除的元素是%d\n", e);
                else printf("删除失败\n");
                getchar();
                getchar();
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                if (!ListTraverse(LList[list_num - 1])) printf("线性表是空表！\n");
                getchar();
                getchar();
                break;
            case 13:
                //f_write
                if (f_write(LList[list_num - 1], FILE_NAME) == OK) printf("写入文件成功\n");
                else printf("写入文件失败\n");
                getchar();
                getchar();
                break;
            case 14:
                //f_read
                if (f_read(LList[list_num - 1], FILE_NAME) == OK) printf("读取线性表成功\n");
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

status InitList(LinkList &L) {
    //list already exist
    if (L) {
        printf("List already exist!\n");
        return ERROR;
    }
        //list not exist
    else {
        //malloc head node
        LinkList L = (LinkList) malloc(sizeof(LNode));
        if (!L) {
            printf("malloc failed\n");
            return ERROR;
        }
        L->next = NULL;
        return OK;
    }
}

status DestroyList(LinkList &L) {
    //list not exist
    if (!L)
        return OK;
    else {
        //pointer to free
        LinkList free_p = L;
        //save next node
        LinkList next_p = free_p->next;
        //list traverse
        while (next_p) {
            free(free_p);
            free_p = next_p;
            next_p = next_p->next;
        }
        //free last node
        free(free_p);
        L = NULL;
        return OK;
    }
}

status ClearList(LinkList &L) {
    //list not exist
    if (!L) {
        printf("list not exit!\n");
        return ERROR;
    }
        //list is empty
    else if (!L->next)
        return OK;
        //not empty
    else {
        L->data = 0;
        //pointer to free, begin from node with data(not head node)
        LinkList free_p = L->next;
        //save next node
        LinkList next_p = free_p->next;
        while (next_p) {
            free(free_p);
            free_p = next_p;
            next_p = next_p->next;
        }
        free(free_p);   // free last pointer
        L->next = NULL;
        return OK;
    }
}

status ListEmpty(LinkList L) {
    if (!L->next)
        return TRUE;
    else
        return FALSE;
}

int ListLength(LinkList L) {
    //list not exist or empty
    if (!L || !L->next) {
        return 0;
    }
    //head node
    L = L->next;
    int i = 0;
    //traverse
    for (; L; L = L->next)
        i++;
    return i;
}

status GetElem(LinkList L, int i, ElemType &e) {
    //out of range
    if (i <= 0) {
        printf("i out of range\n");
        return ERROR;
    }
        //list not exist
    else if (!L) {
        printf("list not exist\n");
        return ERROR;
    }
    //traverse list
    int i_traverse = 1;
    L = L->next;
    while (L) {
        if (i_traverse == i) {
            e = L->data;
            return OK;
        }
        L = L->next;
        i_traverse++;
    }
    //traverse end and no result means bad location
    printf("i out of range\n");
    return ERROR;
}

int LocateElem(LinkList L, ElemType e) {
    //list not exist
    if (!L) {
        printf("list not exist\n");
        return ERROR;
    }
    //list traverse
    int i_traverse = 1;
    L = L->next;
    while (L) {
        if (L->data == e) {
            return i_traverse;
        }
        L = L->next;
        i_traverse++;
    }
    //traverse end and no result means no such elem
    printf("no such elem\n");
    return 0;
}

status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    //list not exist
    if (!L) {
        printf("list not exist\n");
        return ERROR;
    }
    //use LocateElem()
    int location = LocateElem(L, cur_e);
    //first elem no prior
    if (location == 1) {
        printf("first elem no prior\n");
        return ERROR;
    } else if (location == 0) {
        printf("no such elem\n");
        return ERROR;
    }
    //to save the prior node
    LinkList prior_p = L;
    L = L->next;
    while (L) {
        //find cur_e
        if (L->data == cur_e) {
            pre_e = prior_p->data;
            return OK;
        }
        prior_p = L;
        L = L->next;
    }
    printf("don't know why went wrong\n");
    return ERROR;
}

status NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    //list not exist
    if (!L) {
        printf("list not exist\n");
        return ERROR;
    }
    //head node
    L = L->next;
    //list traverse
    while (L->next) {
        //find cur_e
        if (L->data == cur_e) {
            next_e = L->next->data;
            return OK;
        }
        L = L->next;
    }
    //traverse end and no result means no such elem
    printf("no next elem\n");
    return ERROR;
}

status ListInsert(LinkList &L, int i, ElemType e) {
    //list not exist
    if (!L) {
        printf("list not exist\n");
        return ERROR;
    }
        //i out of range
    else if (!(i >= 1 && i <= ListLength(L) + 1)) {
        printf("i out of range\n");
        return ERROR;
    }
    int i_traverse = 1;
    //save prior node
    LinkList pri_p = L;
    LinkList L_tmp = pri_p->next;
    //list traverse
    while (L_tmp) {
        //find location i
        if (i_traverse == i) {
            LinkList insert_node = (LinkList) malloc(sizeof(LNode));
            //malloc failed
            if (!insert_node) {
                printf("malloc failed\n");
                return ERROR;
            }
            insert_node->data = e;
            pri_p->next = insert_node;
            insert_node->next = L_tmp;
            return OK;
        }
        pri_p = L_tmp;
        L_tmp = L_tmp->next;
        i_traverse++;
    }
    //insert the last elem
    LinkList insert_node = (LinkList) malloc(sizeof(LNode));
    //malloc failed
    if (!insert_node) {
        printf("malloc failed\n");
        return ERROR;
    }
    insert_node->data = e;
    pri_p->next = insert_node;
    insert_node->next = NULL;
    return OK;
}

status ListDelete(LinkList &L, int i, ElemType &e) {
    //list not exist
    if (!L) {
        printf("list not exist\n");
        return ERROR;
    }
    //i out of range
    if (!(i >= 1 && i <= ListLength(L))) {
        printf("i out of range\n");
        return ERROR;
    }
    int i_traverse = 1;
    //save prior node
    LinkList pri_p = L;
    LinkList L_tmp = pri_p->next;
    while (L_tmp) {
        //find location i
        if (i_traverse == i) {
            //save node data to e
            e = L_tmp->data;
            pri_p->next = L_tmp->next;
            free(L_tmp);
            return OK;
        }
        pri_p = L_tmp;
        L_tmp = L_tmp->next;
        i_traverse++;
    }
    printf("don't know why went wrong\n");
    return ERROR;
}

status ListTraverse(LinkList L) {
    //list not exist
    if (!L) {
        printf("list not exists!\n");
        return ERROR;
    }
    //head node
    L = L->next;
    printf("\n-----------all elements -----------------------\n");
    //list traverse
    while (L) {
        printf("%d\t", L->data);
        L = L->next;
    }
    printf("\n------------------ end ------------------------\n");
    return OK;
}

status f_write(LinkList L, char *file_name) {
    //list not exist or list empty
    if (!L || !L->next) return ERROR;
    FILE *file;
    //file open error
    if ((file = fopen(file_name, "w")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    //file open success
    L = L->next;
    //traverse and write
    while (L) {
        fprintf(file, "%d\t", L->data);
        L = L->next;
    }
    //close file
    fclose(file);
    return OK;
}

status f_read(LinkList &L, char *file_name) {
    //list already exist
    if (L) {
        printf("list already exists\n");
        return ERROR;
    }
    FILE *file;
    //file open error
    if ((file = fopen(file_name, "r")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    //file open success
    LinkList new_malloc, before_p;
    //buffer to save data in file
    ElemType read_buffer;
    //head node
    L = (LinkList) malloc(sizeof(LNode));
    L->data = NULL;
    before_p = L;
    //fscanf ends with EOF
    while (fscanf(file, "%d\t", &read_buffer) != EOF) {
        new_malloc = (LinkList) malloc(sizeof(LNode));
        new_malloc->data = read_buffer;
        before_p->next = new_malloc;
        before_p = new_malloc;
    }
    new_malloc->next = NULL;
    //file close
    fclose(file);
    return OK;
}

//build a example list
void CreateList(LinkList &L, int number) {
    LinkList new_malloc, before_p;
    L = (LinkList) malloc(sizeof(LNode));
    L->data = NULL;
    before_p = L;
    for (int i = 0; i < number; i++) {
        new_malloc = (LinkList) malloc(sizeof(LNode));
        new_malloc->data = i;
        before_p->next = new_malloc;
        before_p = new_malloc;
    }
    new_malloc->next = NULL;
}