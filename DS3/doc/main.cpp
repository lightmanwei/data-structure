#include "btree.h"

int main(void) {

    BTree LList[LLIST_SIZE] = {NULL};
    int list_num;
    CreateBiTree(LList[0], init_btree_array);

    BTree result;
    int location;
    ElemType e;
    bool lr;
    int op = 1;
    while (op) {
        system("clear");
        printf("\n\n");
        printf("选择一个线性表(输入序号，默认1-10)\n");
        scanf("%d", &list_num);
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. CreateBiTree       8. "
               "GetSibling\n");
        printf("    	  2. DestroyBiTree    9. InsertNode \n");
        printf("    	  3. ClearBiTree      10. DeleteNode\n");
        printf("    	  4. BiTreeEmpty      11. PreOrderTraverse\n");
        printf("    	  5. BiTreeDepth     12. InOrderTraverse\n");
        printf("    	  6. LocateNode        13. PostOrderTraverse\n");
        printf("    	  7. Assign     14. LevelOrderTraverse\n");
        printf("    	  15. GraphBTree     16. "
               "FileWrite\n");
        printf("    	  17. FileRead       0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~17]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                //printf("\n----IntiList功能待实现！\n");
                if (CreateBiTree(LList[list_num - 1],
                                 init_btree_array) ==
                    OK)
                    printf("二叉树创建成功！\n");
                else printf("二叉树创建失败！\n");
                getchar();
                getchar();
                break;
            case 2:
                //printf("\n----DestroyList功能待实现！\n");
                if (DestroyBiTree(LList[list_num - 1]) ==
                    OK)
                    printf("二叉树销毁成功！\n");
                else printf("二叉树销毁失败！\n");
                getchar();
                getchar();
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                if (ClearBiTree(LList[list_num - 1]) == OK)
                    printf("二叉树清空成功！\n");
                else printf("二叉树清空失败！\n");
                getchar();
                getchar();
                break;
            case 4:
                //printf("\n----ListEmpty功能待实现！\n");
                if (BiTreeEmpty(LList[list_num - 1]) ==
                    TRUE)
                    printf("二叉树为空！\n");
                else printf("二叉树不为空！\n");
                getchar();
                getchar();
                break;
            case 5:
                //printf("\n----ListLength功能待实现！\n");
                printf("二叉树的深度为：%d",
                       BiTreeDepth(LList[list_num - 1]));
                getchar();
                getchar();
                break;
            case 6:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                printf("获取元素的位置是：\n");
                scanf("%d", &location);
                result = LocateNode(
                        LList[list_num - 1]->lchild,
                        location);
                if (result)
                    printf("二叉树第%d个元素的data是%d\n",
                           location,
                           result->elem.data);
                else printf("没有目标元素\n");
                getchar();
                getchar();
                break;
            case 7:
                printf("更改的元素的id是：\n");
                scanf("%d", &location);
                printf("赋予的值为：\n");
                scanf("%d", &e);
                if (Assign(LList[list_num - 1], location, e)
                        )
                    printf
                            ("更改成功\n");
                else printf("没有%d元素\n", location);
                getchar();
                getchar();
                break;
            case 8:
                printf("要获取兄弟节点的节点的id是：\n");
                scanf("%d", &location);
                result = GetSibling(LList[list_num - 1],
                                    location);
                if (result)
                    printf("目标节点的兄弟节点的id是%d\n",
                           result->elem.id);
                else printf("目标节点无兄弟节点\n");
                getchar();
                getchar();
                break;
            case 9:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                printf("要插入的位置是\n");
                scanf("%d", &location);
                printf("要插入的是左0还是右1\n");
                scanf("%d", &lr);
                printf("节点的data为\n");
                scanf("%d", &e);
                result = (BTree) malloc(sizeof(BTreeNode));
                result->elem.data = e;
                if (InsertNode(LList[list_num - 1]->lchild,
                               location,
                               lr, result) == OK)
                    printf("插入成功\n");
                else printf("插入失败\n");
                getchar();
                getchar();
                break;
            case 10:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                printf("删除节点的id是：\n");
                scanf("%d", &location);
                if (DeleteNode(LList[list_num - 1],
                               location) == OK)
                    printf("删除成功\n");
                else printf("删除失败\n");
                getchar();
                getchar();
                break;
            case 11:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                PreOrderTraverse(
                        LList[list_num - 1]->lchild);
                printf("\n");
                getchar();
                getchar();
                break;
            case 12:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                InOrderTraverse(
                        LList[list_num - 1]->lchild);
                printf("\n");
                getchar();
                getchar();
                break;
            case 13:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                PostOrderTraverse(
                        LList[list_num - 1]->lchild);
                printf("\n");
                getchar();
                getchar();
                break;
            case 14:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                LevelOrderTraverse(
                        LList[list_num - 1]->lchild);
                printf("\n");
                getchar();
                getchar();
                break;
            case 15:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                Display(LList[list_num - 1]->lchild, 0);
                printf("\n");
                getchar();
                getchar();
                break;
            case 16:
                if (!LList[list_num - 1]) {
                    printf("二叉树为空\n");
                    break;
                }
                if (f_write(LList[list_num - 1]->lchild,
                            FILE_NAME) == OK)
                    printf("写入文件成功\n");
                else printf("写入文件失败\n");
                getchar();
                getchar();
                break;
            case 17:
                //f_read
                if (f_read(LList[list_num - 1],
                           FILE_NAME) == OK)
                    printf("读取线性表成功\n");
                else printf("读取线性表失败\n");
                getchar();
                getchar();
                break;

            case 0:
                break;
        }
        //end of switch
        if (!LList[list_num - 1]) {
            printf("二叉树为空\n");
        } else
            Display(LList[list_num - 1]->lchild,
                    0);
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}


/***辅助函数***/

//根据带空树的前序遍历数组 创建二叉树，ID为前序遍历的顺序
void PreOrderCreateBiTree(BTree &root, ElemType array[],
                          int &index_array,
                          int &index_tree) {
    //index_array是数组的序号，index_tree是节点的id序号

    //base line
    if (array[index_array] == EMPTY) {
        //如果是空树，index_tree不应该增加
        index_tree--;
        return;
    } else {
        root = (BTree) malloc(sizeof(BTreeNode));
        //数据
        root->elem.data = array[index_array];
        //唯一id
        root->elem.id = index_tree;
        root->lchild = NULL;
        root->rchild = NULL;
        //左子树
        index_tree++;
        index_array++;
        PreOrderCreateBiTree(root->lchild, array,
                             index_array, index_tree);
        //右子树
        index_tree++;
        index_array++;
        PreOrderCreateBiTree(root->rchild, array,
                             index_array, index_tree);
    }
}

//求两个int的最大值
int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

//递归求btree深度
int SearchDepth(BTree T) {
    if (!T)
        return 0;
    //取左右子树的最大深度
    return Max(SearchDepth(T->lchild), SearchDepth
            (T->rchild)) + 1;
}

//树的节点数
int TreeSize(BTree T) {
    if (!T)
        return 0;
    return TreeSize(T->lchild) + TreeSize(T->rchild) + 1;
}

//寻找父节点
BTree LocateFatherNode(BTree T, int index) {
    //空树
    //base line
    if (!T || (!T->rchild && !T->lchild))
        return NULL;
    else if (T->lchild && T->lchild->elem.id == index)
        return T;
    else if (T->rchild && T->rchild->elem.id == index)
        return T;

    //递归左右子树
    BTree TL = LocateFatherNode(T->lchild, index);
    BTree TR = LocateFatherNode(T->rchild, index);
    return (TR) ? TR : TL;

}

//递归把树写入文件
void FilePreOrderWrite(BTree T, FILE *file) {
    if (T == NULL) {
        fprintf(file, "0\t");
        return;
    }
    fprintf(file, "%d\t", T->elem.data);
    FilePreOrderWrite(T->lchild, file);
    FilePreOrderWrite(T->rchild, file);
    return;
}

//int PrintNodeData(BTree T) {
//    if (T)
//        printf("%d\t", T->elem.data);
//    else
//        printf("-1\t");
//    return 0;
//}

//次幂运算x的y次方
int power(int x, int y) {
    int result = x;
    if (y == 0)
        return 1;
    for (int i = 1; i < y; i++)
        result *= x;
    return result;
}
/**********目标函数***********/
/***未特殊说明，传入的btree均为带头结点的btree***/
//根据前序遍历带空子树的数组创建二叉树
status CreateBiTree(BTree &root, ElemType array[]) {
    //二叉树已经存在
    if (root)
        return ERROR;
    //头结点
    root = (BTree) malloc(sizeof(BTreeNode));
    root->elem.data = EMPTY;
    root->elem.id = -1;
    //头结点的左子树是内容，右子树是null
    root->rchild = NULL;
    int index_array = 0;
    int index_tree = 0;
    PreOrderCreateBiTree(root->lchild, array, index_array,
                         index_tree);
    return OK;
}

//销毁树
status DestroyBiTree(BTree &T) {
    //base line
    if (!T)
        return FALSE;
        //销毁左右子树
    else {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
    }
    //销毁当前节点
    free(T);
    T = NULL;
    return OK;
}

//清空树（不销毁头结点）
status ClearBiTree(BTree T) {
    //销毁除根节点以外的节点
    DestroyBiTree(T->lchild);
    DestroyBiTree(T->rchild);
    return OK;
}

//判断二叉树是否为空
status BiTreeEmpty(BTree T) {
    //数不存在，认为也是空树
    if (!T) {
        printf("T not exist\n");
        return TRUE;
    }
        //头结点的左子树为空说明二叉树为空
    else if (!T->lchild)
        return TRUE;
        //二叉树不为空
    else {
        printf("T is not empty\n");
        return FALSE;
    }
}

//判断btree是否存在，再递归求深度，返回深度
int BiTreeDepth(BTree T) {
    //树不存在
    if (!T) {
        printf("Tree not exist\n");
        return 0;
    }
    return SearchDepth(T->lchild);
}

//参数不带头结点，用id定位并返回节点
BTree LocateNode(BTree T, int index) {
    //空树
    if (!T)
        return NULL;
        //base line
    else if (T->elem.id == index)
        return T;
        //递归左右子树
    else {
        BTree TL = LocateNode(T->lchild, index);
        BTree TR = LocateNode(T->rchild, index);
        return (TR) ? TR : TL;
    }
}

//通过id给节点赋值
status Assign(BTree &T, int index, ElemType value) {
    BTree target = LocateNode(T->lchild, index);
    if (!target)
        return FALSE;
    else {
        target->elem.data = value;
        return OK;
    }
}

//返回兄弟节点
BTree GetSibling(BTree T, int index) {
    //定位父节点
    BTree father = LocateFatherNode(T->lchild, index);
    if (!father)
        return NULL;
    else if (father->lchild && father->lchild->elem.id ==
                               index)
        return father->rchild;
    else return father->lchild;
}

//参数不带头结点
//作为关键字为e的结点的左或右孩子结点，结点e的原有左子树或右子树则为结点c的右子树
status InsertNode(BTree T, int index, bool LR, BTree
insert) {
    //新节点id等于原来树的大小（size）
    insert->elem.id = TreeSize(T);
    BTree location = LocateNode(T, index);
    //找不到插入节点
    if (!location)
        return FALSE;
    BTree tmp = NULL;
    //LR=0 左子树
    if (!LR) {
        tmp = location->lchild;
        location->lchild = insert;
        insert->rchild = tmp;
    } else {
        tmp = location->rchild;
        location->rchild = insert;
        insert->rchild = tmp;
    }
    return OK;
}

//参数不带头结点
// 如果关键字为e的结点度为0，删除即可；如关键字为e的结点度为1，
// 用关键字为e的结点孩子代替被删除的e位置；如关键字为e的结点度为2，
// 用e的左孩子代替被删除的e位置，e的右子树作为e的左子树中最右结点的右子树。
status DeleteNode(BTree T, int index) {

    BTree father = LocateFatherNode(T, index);
    //father的左节点0还是右节点1
    int tag_lr = 1;
    //找不到父节点
    if (father == NULL)
        return ERROR;
    //要删除的节点
    BTree delete_node = NULL;
    //有父节点
    if (father->lchild &&
        father->lchild->elem.id == index) {
        delete_node = father->lchild;
        tag_lr = 0;
    } else delete_node = father->rchild;
    //度为0
    if (!delete_node->lchild && !delete_node->rchild) {
        free(delete_node);
        //delete是右节点
        if (tag_lr)
            father->rchild = NULL;
            //delete是左节点
        else father->lchild = NULL;
    }
        //度为1
        //左空
    else if (!delete_node->lchild) {
        //delete是右节点
        if (tag_lr)
            father->rchild = delete_node->rchild;
            //delete是左节点
        else father->lchild = delete_node->rchild;
        free(delete_node);
    }
        //右空
    else if (!delete_node->rchild) {
        //delete是右节点
        if (tag_lr)
            father->rchild = delete_node->lchild;
            //delete是左节点
        else father->lchild = delete_node->lchild;
        free(delete_node);
    }
        //度为2
    else {
        //delete是右节点
        if (tag_lr)
            father->rchild = delete_node->lchild;
            //delete是左节点
        else father->lchild = delete_node->lchild;
        //存储delete右子树
        BTree right_node = delete_node->rchild;
        //delete左子树
        BTree left_node = delete_node->lchild;
        free(delete_node);
        while (left_node->rchild)
            left_node = left_node->rchild;
        left_node->rchild = right_node;
    }
    return OK;


}

//参数不带头结点
void PreOrderTraverse(BTree T) {
    if (T == NULL)
        return;
    printf("%d\t", T->elem.data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return;
}

//参数不带头结点
//非递归中序遍历
void InOrderTraverse(BTree root) {
    //栈
    stack <BTree> s;
    BTree p = root;
    while (p != NULL || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->lchild;
        }
        //检查完了左子树，下面访问节点（中序）
        if (!s.empty()) {
            p = s.top();
            printf("%d\t", p->elem.data);
            s.pop();
            //检查右子树
            p = p->rchild;
        }
    }
}

//参数不带头结点
void PostOrderTraverse(BTree T) {
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d\t", T->elem.data);
    return;
}

//参数不带头结点
void LevelOrderTraverse(BTree root) {
    //队列
    queue <BTree> q;
    BTree front;
    if (root == NULL)return;
    q.push(root);
    while (!q.empty()) {
        front = q.front();
        q.pop();
        if (front->lchild)
            q.push(front->lchild);
        if (front->rchild)
            q.push(front->rchild);
        printf("%d\t", front->elem.data);
    }
    printf("\n");
}


//参数不带头结点
void Display(BTree root, int ident) {
    static int vec_left[QUEUESIZE] = {0};
    if (ident > 0) {
        for (int i = 0; i < ident - 1; ++i) {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident - 1] ? "├── " : "└── ");
    }
    if (!root) {
        printf("(null)\n");
        return;
    }
    printf("%d\n", root->elem.data);
    if (!root->lchild && !root->rchild) {
        return;
    }
    vec_left[ident] = 1;
    Display(root->lchild, ident + 1);
    vec_left[ident] = 0;
    Display(root->rchild, ident + 1);
}

void Displayid(BTree root, int ident) {
    static int vec_left[QUEUESIZE] = {0};
    if (ident > 0) {
        for (int i = 0; i < ident - 1; ++i) {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident - 1] ? "├── " : "└── ");
    }

    if (!root) {
        printf("(null)\n");
        return;
    }

    printf("%d\n", root->elem.id);
    if (!root->lchild && !root->rchild) {
        return;
    }
    vec_left[ident] = 1;
    Displayid(root->lchild, ident + 1);
    vec_left[ident] = 0;
    Displayid(root->rchild, ident + 1);
}

//参数不带头结点，写入文件
status f_write(BTree T, char *file_name) {
    //list not exist or list empty
    if (!T) return ERROR;
    FILE *file;
    //file open error
    if ((file = fopen(file_name, "w")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    //file open success
    //traverse and write
    FilePreOrderWrite(T, file);
    //close file
    fclose(file);
    return OK;
}

//读取文件
status f_read(BTree &T, char *file_name) {
    //list already exist
    if (T) {
        printf("tree already exists\n");
        return ERROR;
    }
    FILE *file;
    //file open error
    if ((file = fopen(file_name, "r")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    //file open success
    //buffer to save data in file
    ElemType read_buffer[QUEUESIZE] = {0};
    //fscanf ends with EOF
    int i = 0;
    while (fscanf(file, "%d\t", &read_buffer[i]) != EOF) {
        i++;
    }
    CreateBiTree(T, read_buffer);
    //file close
    fclose(file);
    return OK;
}

