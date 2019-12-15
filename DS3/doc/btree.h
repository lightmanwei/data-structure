/*
 * 本节的树均为带头结点的树，数据为EMTPY，id为-1
 * ，大部分函数是对带头结点的树进行操作，少部分是对内容树进行操作，会在注释中标注*/
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
/***初始化定义***/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
//数据为0表示空节点
#define EMPTY 0
#define QUEUESIZE 200
#define LLIST_SIZE 10
typedef int status;
typedef int ElemType; //数据元素类型定义
//文件绝对路径
char FILE_NAME[100] =
        "/Users/akunda/Downloads/DS+/DS3/output.txt";
//前序遍历带空子树的数组，用来初始化树
ElemType init_btree_array[] = {1, 2, 4, 0, 5, 0, 0, 0, 3, 6,
                               0, 7, 0, 0, 8, 0, 0};

//元素结构
typedef struct elem {
    int id;
    ElemType data;
} Elem;
//树结构
typedef struct BTreeNode {
    Elem elem;
    struct BTreeNode *lchild;
    struct BTreeNode *rchild;
} BTreeNode, *BTree;

/***辅助函数***/

//根据带空树的前序遍历数组 创建二叉树，ID为前序遍历的顺序
void PreOrderCreateBiTree(BTree &root, ElemType array[],
                          int &index_array,
                          int &index_tree);

//求两个int的最大值
int Max(int a, int b);

//递归求btree深度
int SearchDepth(BTree T);

//树的节点数
int TreeSize(BTree T);

//寻找父节点
BTree LocateFatherNode(BTree T, int index);

//递归把树写入文件
void FilePreOrderWrite(BTree T, FILE *file);

//int PrintNodeData(BTree T) {
//    if (T)
//        printf("%d\t", T->elem.data);
//    else
//        printf("-1\t");
//    return 0;
//}

//次幂运算x的y次方
int power(int x, int y);

/**********目标函数***********/
/***未特殊说明，传入的btree均为带头结点的btree***/
//根据前序遍历带空子树的数组创建二叉树
status CreateBiTree(BTree &root, ElemType array[]);

//销毁树
status DestroyBiTree(BTree &T);

//清空树（不销毁头结点）
status ClearBiTree(BTree T);

//判断二叉树是否为空
status BiTreeEmpty(BTree T);

//判断btree是否存在，再递归求深度，返回深度
int BiTreeDepth(BTree T);

//参数不带头结点，用id定位并返回节点
BTree LocateNode(BTree T, int index);

//通过id给节点赋值
status Assign(BTree &T, int index, ElemType value);

//返回兄弟节点
BTree GetSibling(BTree T, int index);

//参数不带头结点
//作为关键字为e的结点的左或右孩子结点，结点e的原有左子树或右子树则为结点c的右子树
status InsertNode(BTree T, int index, bool LR, BTree
insert);

//参数不带头结点
// 如果关键字为e的结点度为0，删除即可；如关键字为e的结点度为1，
// 用关键字为e的结点孩子代替被删除的e位置；如关键字为e的结点度为2，
// 用e的左孩子代替被删除的e位置，e的右子树作为e的左子树中最右结点的右子树。
status DeleteNode(BTree T, int index);

//参数不带头结点
void PreOrderTraverse(BTree T);

//参数不带头结点
//非递归中序遍历
void InOrderTraverse(BTree root);

//参数不带头结点
void PostOrderTraverse(BTree T);

//参数不带头结点
void LevelOrderTraverse(BTree root);


//参数不带头结点
void Display(BTree root, int ident);

void Displayid(BTree root, int ident);

//参数不带头结点，写入文件
status f_write(BTree T, char *file_name);

//读取文件
status f_read(BTree &T, char *file_name);


