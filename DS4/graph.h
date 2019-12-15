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

//文件相对路径
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

//顶点初始化数组
ElemType V_init[] = {"zero", "one", "two", "three",
                     "four", "END"};
//弧初始化数组
int VR_init[] = {1, 2, 1, 3, 1, 0, 2, 4, 3, 4, -1};

/***辅助函数***/
//寻找顶点的最后一个弧节点
ArcNode_p GetLastArc(ArcNode_p arc_p);

//更改元素（现在是更改字符串）
void ChangeElem(ElemType &origin_elem, ElemType new_elem);

//展示图
void Show(ALGraph_p G);

//初始化一个节点
VNode_p InitNode();

//删除指定顶点里的指定弧，参数为指定顶点的指针，指定弧的相邻顶点
status DeleteArcInVNode(VNode_p vnode, int target_vex);

//深度优先搜索递归
void DFS(ALGraph_p G, int v, int visit[]);

//广度优先搜索子函数
void BFS(ALGraph_p G, queue<int> q, int visit[]);


/***目标函数***/



//创建图
status
CreateGraph(ALGraph_p &G, ElemType V[], int VR[]);

//销毁图
status DestroyGraph(ALGraph_p &G);

//输入寻找的顶点下标，返回顶点在数组中的下标，找不到就返回-1
int LocateVex(ALGraph_p G, int u);

status PutVex(ALGraph_p G, int u, ElemType value);

int FirstAdjVex(ALGraph_p G, int u);

int NextAdjVex(ALGraph_p G, int v, int w);

status InsertVex(ALGraph_p G, VNode v);

status DeleteVex(ALGraph_p G, int v);

status InsertArc(ALGraph_p G, int v, int w);

status DeleteArc(ALGraph_p G, int v, int w);

//用邻接表方式实现深度优先搜索(递归方式）
//v 传入的是第一个需要访问的顶点
status DFSTraverse(ALGraph_p G);

status BFSTraverse(ALGraph_p G);

//参数不带头结点，写入文件
status f_write(ALGraph_p G, char *file_name);

//读取文件
status f_read(ALGraph_p &G, char *file_name);



/***辅助函数***/
//寻找顶点的最后一个弧节点
ArcNode_p GetLastArc(ArcNode_p arc_p) {
    if (!arc_p) {
        printf("last is null\n");
        return NULL;
    }
    if (!arc_p->next_arc)return arc_p;
    else return GetLastArc(arc_p->next_arc);
}

//更改元素（现在是更改字符串）
void ChangeElem(ElemType &origin_elem, ElemType new_elem) {
    //string
    strcpy(origin_elem, new_elem);
}

//展示图
void Show(ALGraph_p G) {
    if (!G) {
        printf("emtpy\n");
        return;
    }
    printf("vexnum: %d\n", G->vexnum);
    printf("arcnum: %d\n", G->arcnum);
    printf("graph kind: %d\n", G->kind);
    for (int i = 0; i < G->vexnum; i++) {
        printf("node id %d, data %s\t", G->vertices[i].elem
                .id, G->vertices[i].elem.data);
        ArcNode_p tmp = G->vertices[i].first_arc;
        while (tmp) {
            printf("%d->", tmp->adjvex);
            tmp = tmp->next_arc;
        }
        printf("null\n");
    }
    printf("over\n");
}

//初始化一个节点
VNode_p InitNode() {
    //插入节点样例
    VNode_p v_new = (VNode_p) malloc(sizeof(VNode));
    vector<int> adjnode;

    int buffer;
    printf("添加顶点的数据（data）是：\n");
    scanf("%s", &v_new->elem.data);
    printf("和顶点相关联的顶点有（空格分隔，-1结尾）：\n");
    scanf("%d", &buffer);
    while (buffer != -1) {
        adjnode.push_back(buffer);
        scanf("%d", &buffer);
    }
    v_new->first_arc = NULL;
    if (!adjnode.empty()) {
        v_new->first_arc = (ArcNode_p) malloc(
                sizeof(ArcNode));
        v_new->first_arc->adjvex=adjnode[0];
        v_new->first_arc->next_arc=NULL;
    } else {
        return v_new;
    }
    ArcNode_p new_arc = v_new->first_arc;
    for (int i = 1; i < adjnode.size(); i++) {
        new_arc->next_arc=(ArcNode_p) malloc(
                sizeof(ArcNode));
        new_arc->next_arc->adjvex = adjnode[i];
        new_arc = new_arc->next_arc;
    }
    new_arc = NULL;
    return v_new;
}

//删除指定顶点里的指定弧，参数为指定顶点的指针，指定弧的相邻顶点
status DeleteArcInVNode(VNode_p vnode, int target_vex) {
    if (!vnode->first_arc) {
        //printf("DeleteArcInVNode node has no arc\n");
        return ERROR;
    }
    ArcNode_p arc_before = vnode->first_arc;
    if (arc_before->adjvex == target_vex) {
        vnode->first_arc = arc_before->next_arc;
        free(arc_before);
        return OK;
    }
    //判断余下弧节点
    ArcNode_p arc_tmp = arc_before->next_arc;
    while (arc_tmp) {
        if (arc_tmp->adjvex == target_vex) {
            arc_before->next_arc = arc_tmp->next_arc;
            free(arc_tmp);
            return OK;
        }
        arc_before = arc_tmp;
        arc_tmp = arc_tmp->next_arc;
    }
    //printf("no such arc\n");
    return ERROR;
}

void DFS(ALGraph_p G, int v, int visit[]) {
    //图的顶点的搜索指针
    ArcNode_p p;
    //置已访问标记
    int index = LocateVex(G, v);
    visit[index] = 1;
    //输出被访问顶点的编号
    printf("%s  ", G->vertices[v].elem.data);
    //p指向顶点v的第一条弧的弧头结点
    p = G->vertices[index].first_arc;
    while (p) {
        //若p->adjvex顶点未访问,递归访问它
        if (visit[p->adjvex] == 0) {
            DFS(G, p->adjvex, visit);
        }
        //p指向顶点v的下一条弧的弧头结点
        p = p->next_arc;
    }
}


void BFS(ALGraph_p G, queue<int> q, int visit[]) {
    while (!q.empty()) {
        int u = q.front();
        if (!visit[LocateVex(G, u)]) {
            printf("%s    ", G->vertices[LocateVex(G, u)]
                    .elem
                    .data);
            visit[u] = 1;
        }
        q.pop();
        for (int w = FirstAdjVex(G, u); w >= 0;
             w = NextAdjVex(G, u, w)) {
            if (!visit[LocateVex(G, w)]) {
                q.push(w);
            }
        }
    }
}
/***目标函数***/



//创建图
status
CreateGraph(ALGraph_p &G, ElemType V[], int VR[]) {
    //图已存在
    if (G)
        return ERROR;
    G = (ALGraph_p) malloc(sizeof(ALGraph));
    G->kind = UDG;
    //节点数和弧数
    int vex_num = 0, arc_num = 0;
    //求顶点数量
    for (; strcmp(V[vex_num], "END"); vex_num++) {}
    G->vexnum = vex_num;
    //初始化节点列表，data来自V，id是V下标，first_arc初始化为null
    for (int vex = 0; vex < vex_num; vex++) {
        ChangeElem(G->vertices[vex].elem.data, V[vex]);
        G->vertices[vex].elem.id = vex;
        G->vertices[vex].first_arc = NULL;
    }
    //求弧数量
    for (; VR[arc_num] != -1; arc_num++) {}
    arc_num = arc_num;//这里arc_num是弧数的两倍
    G->arcnum = arc_num / 2;
    //临时变量用来存储顶点的末尾弧节点
    ArcNode_p last_arc = NULL;
    //遍历关系数组
    for (int arc = 0; arc < arc_num;
         arc += 2) {
//查找弧对应的顶点，因为无向图两个顶点都要加上弧节点，所以要遍历两次（第一遍）
        for (int i = 0; i < G->vexnum; i++) {
            //找到对应顶点
            if (VR[arc] == G->vertices[i].elem.id) {
                //没有first弧，分配first弧
                if (!G->vertices[i].first_arc) {
                    G->vertices[i].first_arc =
                            (ArcNode_p) malloc(
                                    sizeof(ArcNode));
                    last_arc = G->vertices[i].first_arc;
                }
                    //用GetLastArc找到最后一个弧结点
                else {
                    last_arc = GetLastArc(
                            G->vertices[i].first_arc);
                    last_arc->next_arc = (ArcNode_p) malloc(
                            sizeof(ArcNode));
                    last_arc = last_arc->next_arc;
                }
                last_arc->next_arc = NULL;
                last_arc->adjvex = VR[arc + 1];
                break;
            }
        }
//第二遍
        for (int i = 0; i < G->vexnum; i++) {
            if (VR[arc + 1] == G->vertices[i].elem.id) {
                if (!G->vertices[i].first_arc) {
                    G->vertices[i].first_arc =
                            (ArcNode_p) malloc(
                                    sizeof(ArcNode));
                    last_arc = G->vertices[i].first_arc;
                } else {
                    last_arc = GetLastArc(
                            G->vertices[i].first_arc);
                    last_arc->next_arc = (ArcNode_p) malloc(
                            sizeof(ArcNode));
                    last_arc = last_arc->next_arc;
                }
                last_arc->next_arc = NULL;
                last_arc->adjvex = VR[arc];
                break;
            }
        }
    }
    return OK;
}

//销毁图
status DestroyGraph(ALGraph_p &G) {
    if (!G)
        return OK;
    //临时储存下一个弧节点和当前弧节点，方便删除
    ArcNode_p next_arc = NULL, cur_arc = NULL;
    //销毁每一个顶点
    for (int i = 0; i < G->vexnum; i++) {
        cur_arc = G->vertices[i].first_arc;
        //销毁顶点的每一个弧
        while (cur_arc) {
            next_arc = cur_arc->next_arc;
            free(cur_arc);
            cur_arc = next_arc;
        }
    }
    //释放图本身
    free(G);
    G = NULL;
    return OK;
}

//输入寻找的顶点下标，返回顶点在数组中的下标，找不到就返回-1
int LocateVex(ALGraph_p G, int u) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    int index = 0;
    for (; index < G->vexnum; index++) {
        if (G->vertices[index].elem.id == u)
            return index;
    }
    return INFEASTIBLE;
}

status PutVex(ALGraph_p G, int u, ElemType value) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    int index = LocateVex(G, u);
    if (index == -1)
        return ERROR;
    ChangeElem(G->vertices[index].elem.data, value);
    return OK;
}

int FirstAdjVex(ALGraph_p G, int u) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    if (u >= G->vexnum)
        return -1;
    return G->vertices[u].first_arc->adjvex;
}

int NextAdjVex(ALGraph_p G, int v, int w) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //寻找v，w的位序
//    int index_v = LocateVex(G, v);
//    int index_w = LocateVex(G, w);
    //找不到就返回错误
    if (v >= G->vexnum || w >= G->vexnum) {
        printf("w or v not found\n");
        return -1;
    }
    ArcNode_p traverse_v = G->vertices[v].first_arc;

    while (traverse_v) {
        if (traverse_v->adjvex == G->vertices[w].elem.id)
            //如果w是最后一个邻接顶点
            if (!traverse_v->next_arc) {
                //  printf("w is the last arc\n");
                return -1;
            } else {
                return
                        traverse_v->next_arc->adjvex;
            }
        traverse_v = traverse_v->next_arc;
    }
    //如果w不是v的邻接顶点就返回错误
    printf("w is not adj to v\n");
    return -1;
}

status InsertVex(ALGraph_p G, VNode v) {
    if (G->vexnum >= MAX_VERTEX_NUM) {
        printf("vex array is full\n");
        return ERROR;
    }
    G->vertices[G->vexnum] = v;
    G->vertices[G->vexnum].elem.id = G->vexnum;
    v.elem.id = G->vexnum;
    G->vexnum++;
    ArcNode_p traverse_new_node = v.first_arc;
    int arc_num = 0;
    int adj_nodes[MAX_VERTEX_NUM] = {0};
    while (traverse_new_node) {
        adj_nodes[arc_num] = traverse_new_node->adjvex;
        arc_num++;
        traverse_new_node = traverse_new_node->next_arc;
    }
    G->arcnum += arc_num;

    //给原来的顶点增加新弧
    ArcNode_p new_arc = NULL;
    for (int i = 0; i < arc_num; i++) {
        new_arc = GetLastArc(G->vertices[adj_nodes[i]]
                                     .first_arc);
        new_arc->next_arc = (ArcNode_p) malloc(sizeof
                                                       (ArcNode));
        new_arc->next_arc->adjvex = v.elem.id;
        new_arc->next_arc->next_arc = NULL;
    }
    return OK;
}

status DeleteVex(ALGraph_p G, int v) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //寻找v的位序
    int index_v = LocateVex(G, v);
    //找不到就返回错误
    if (index_v == -1) {
        printf("v not found\n");
        return ERROR;
    }
    //开始删除
    //删除顶点（顶点数组依次向前补齐）
    //  删除节点里的弧节点
    int arc_num = 0;//计数有多少条边要被删掉
    ArcNode_p a = G->vertices[index_v].first_arc, b = NULL;
    if (!a) {}
    else {
        while (a->next_arc) {
            b = a;
            a = b->next_arc;
            free(b);
            arc_num++;
        }
        free(a);
        arc_num++;
    }
    //更改图弧数
    G->arcnum -= arc_num;
    for (; index_v < G->vexnum; index_v++) {
        G->vertices[index_v] = G->vertices[index_v + 1];
       // G->vertices[index_v].elem.id--;
    }
    //更改图顶点数
    G->vexnum--;

    //删除 和被删除节点有关的 边
    //遍历顶点
    for (int i = 0; i < G->vexnum; i++) {
        DeleteArcInVNode(&G->vertices[i], v);
    }
    return OK;
}

status InsertArc(ALGraph_p G, int v, int w) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //寻找v，w的位序
    int index_v = LocateVex(G, v);
    int index_w = LocateVex(G, w);
    //找不到就返回错误
    if (index_v == -1 || index_w == -1) {
        printf("w or v not found\n");
        return -1;
    }
    ArcNode_p traverse_v = G->vertices[index_v].first_arc;
    //寻找v，w之间是否已经有弧
    while (traverse_v->next_arc) {
        if (traverse_v->adjvex == w)
            //如果v，w之间已经存在弧，返回error
        {
            printf("arc already exists between v and w\n");
            return ERROR;
        }
        traverse_v = traverse_v->next_arc;
    }
    //v添加新的弧节点
    traverse_v->next_arc = (ArcNode_p) malloc(
            sizeof(ArcNode));
    traverse_v->next_arc->adjvex = w;
    traverse_v->next_arc->next_arc = NULL;
    //w添加新的弧节点
    ArcNode_p traverse_w = GetLastArc(G->vertices[index_w]
                                              .first_arc);
    traverse_w->next_arc = (ArcNode_p) malloc(
            sizeof(ArcNode));
    traverse_w->next_arc->adjvex = v;
    traverse_w->next_arc->next_arc = NULL;
    //图的弧数加一
    G->arcnum++;
    return OK;
}

status DeleteArc(ALGraph_p G, int v, int w) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //寻找v，w的位序
    int index_v = LocateVex(G, v);
    int index_w = LocateVex(G, w);
    //找不到就返回错误
    if (index_v == -1 || index_w == -1) {
        printf("w or v not found\n");
        return -1;
    }
    if (!DeleteArcInVNode(&G->vertices[index_v], w)) {
        printf("delete in node v failed\n");
        return ERROR;
    }
    if (!DeleteArcInVNode(&G->vertices[index_w], v)) {
        printf("delete in node w failed\n");
        return ERROR;
    }
    G->arcnum--;
    return OK;
}

//用邻接表方式实现深度优先搜索(递归方式）
//v 传入的是第一个需要访问的顶点
//不联通的能访问吗？？？
status DFSTraverse(ALGraph_p G) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //0代表没访问，1代表已访问
    int visit[MAX_VERTEX_NUM] = {0};
    int v = 0;
    printf("输入起始遍历节点的关键字（id）\n");
    scanf("%d", &v);
    if (LocateVex(G, v) == -1) {
        printf("no such vnode\n");
        return ERROR;
    }
    DFS(G, v, visit);
    return OK;
}

status BFSTraverse(ALGraph_p G) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //0代表没访问，1代表已访问
    int visit[MAX_VERTEX_NUM] = {0};
    //存储id
    queue<int> q;
    int visit_id = 0;
    printf("输入起始遍历节点的关键字（id）\n");
    scanf("%d", &visit_id);
    if (LocateVex(G, visit_id) == -1) {
        printf("no such vnode\n");
        return ERROR;
    }
    q.push(LocateVex(G, visit_id));
    BFS(G, q, visit);
    for (int i = 0; i < G->vexnum; i++) {
        if (!visit[i]) {
            q.push(i);
            BFS(G, q, visit);
        }
    }
    return OK;
}

//参数不带头结点，写入文件
status f_write(ALGraph_p G, char *file_name) {
    //list not exist or list empty
    if (!G) return ERROR;
    FILE *file;
    //file open error
    if ((file = fopen(file_name, "w")) == NULL) {
        printf("File open error\n ");
        return ERROR;
    }
    //file open success
    //traverse and write
//    //写入图的基本信息
//    fprintf(file, "%d\t",G->arcnum);
//    fprintf(file, "%d\t",G->vexnum);
//    fprintf(file, "%d\t\n",G->kind);
    //写入节点
    for (int i = 0; i < G->vexnum; i++) {
        fprintf(file, "%s\t", G->vertices[i].elem.data);
    }
    fprintf(file, "END\t");
    //写入边关系
    vector<int> visit;
    for (int i = 0; i < G->vexnum; i++) {
        ArcNode_p p = G->vertices[i].first_arc;
        while (p) {
            visit.push_back(G->vertices[i].elem.id);
            visit.push_back(p->adjvex);
            int visit_tag = 0;
            for (int j = 1; j < visit.size(); j += 2) {
                if (p->adjvex == visit[j - 1] &&
                    G->vertices[i]
                            .elem.id == visit[j]) {
                    visit_tag = 1;
                    break;
                }

            }
            if (!visit_tag)
                fprintf(file, "%d\t%d\t",
                        G->vertices[i].elem
                                .id, p->adjvex);
            p = p->next_arc;
        }
    }
    fprintf(file, "\n");
    //close file
    fclose(file);
    return OK;
}

//读取文件
status f_read(ALGraph_p &G, char *file_name) {
    //list already exist
    if (G) {
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
    ElemType data_list[MAX_VERTEX_NUM];
    vector<int> arc_list;
    //fscanf ends with EOF
    int i = 0;
    ElemType buffer;
    while (fscanf(file, "%s\t", buffer) != EOF) {
        strcpy(data_list[i], buffer);
        if (strcmp("END", buffer) == 0)
            break;

        i++;
    }
    i = 0;
    int buffer2 = 0;
    while (fscanf(file, "%d\t", &buffer2) != EOF) {
        arc_list.push_back(buffer2);
        i++;
    }
    arc_list.push_back(-1);
    for (int j = 0; j < 10; j++)
        CreateGraph(G, &data_list[0], &arc_list[0]);
    //file close
    fclose(file);
    return OK;
}