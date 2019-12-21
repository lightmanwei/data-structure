#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;
#ifndef DS4_GRAPH_H
#define DS4_GRAPH_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTIBLE -1
#define OVERFLOW -2
#define GLIST_SIZE 10
#define MAX_VERTEX_NUM 50
#define STRING_LENGTH 50
#endif //DS4_GRAPH_H

//文件绝对路径
char FILE_NAME[100] =
        "/Users/akunda/Downloads/DS+/DS4/output.txt";
typedef enum {
    DG, DN, UDG, UDN
} GraphKind;
typedef int status;
typedef char ElemType[STRING_LENGTH]; //数据元素类型定义
//元素结构
typedef struct elem {
    int id;
    ElemType data;
} Elem;
//弧结构
typedef struct ArcNode {
    //相邻顶点编号
    int adjvex;
    //下一个弧
    struct ArcNode *next_arc;
    ElemType data;//其他信息
} ArcNode, *ArcNode_p;
//顶点结构
typedef struct VNode {
    Elem elem;
    //相邻第一个弧
    ArcNode *first_arc;
} VNode, *VNode_p, AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList vertices;//头结点数组
    //定点数，弧数
    int vexnum, arcnum;
    GraphKind kind;//本实验使用UDG无向图
} ALGraph, *ALGraph_p;

//顶点初始化数组，以END结尾
ElemType V_init[] = {"zero", "one", "two", "three",
                     "four", "five", "END"};
//弧初始化数组，两两成对，表示有关联的两个顶点，以-1结尾，
int VR_init[] = {1, 2, 1, 3, 1, 0, 2, 4, 3, 4, -1};


/**** 函数 ****/
ArcNode_p GetLastArc(ArcNode_p &arc_p);

void ChangeElem(ElemType &origin_elem, ElemType new_elem);

void Show(ALGraph_p G);

VNode_p InitNode();

status DeleteArcInVNode(VNode_p vnode, int target_vex);

void DFS(ALGraph_p G, int v, int visit[]);

void BFS(ALGraph_p G, queue<int> q, int visit[]);

status
CreateGraph(ALGraph_p &G, ElemType V[], int VR[]);

status DestroyGraph(ALGraph_p &G);

int LocateVex(ALGraph_p G, int u);

status PutVex(ALGraph_p G, int u, ElemType value);

int FirstAdjVex(ALGraph_p G, int u);

int NextAdjVex(ALGraph_p G, int v, int w);

status InsertVex(ALGraph_p G, VNode v);

status DeleteVex(ALGraph_p G, int v);

status InsertArc(ALGraph_p G, int v, int w);

status DeleteArc(ALGraph_p G, int v, int w);

status DFSTraverse(ALGraph_p G);

status BFSTraverse(ALGraph_p G);

status f_write(ALGraph_p G, char *file_name);

status f_read(ALGraph_p &G, char *file_name);


