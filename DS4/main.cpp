#include "graph.h"

int main(void) {

    ALGraph_p GList[GLIST_SIZE] = {NULL};
    int list_num;
    ElemType buffer, result;
    int location_id, location_id2, result_int;
    int op = 1;
    while (op) {
        system("clear");
        printf("\n\n");
        printf("选择一个图(输入序号，默认1-10)\n");
        scanf("%d", &list_num);
        printf("      Menu for Graph On Sequence Structure "
               "\n");
        printf("-------------------------------------------------\n");
        printf("    	  1. CreateGraph      8. DeleteVex\n");
        printf("    	  2. DestroyGraph    9. InsertArc \n");
        printf("    	  3. LocateVex      10. DeleteArc\n");
        printf("    	  4. PutVex      11. DFSTraverse\n");
        printf("    	  5. FirstAdjVex     12. BFSTraverse\n");
        printf("    	  6. NextAdjVex        13. FileWrite\n");
        printf("    	  7. InsertVex     14. FileRead\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~14]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                //printf("\n----IntiList功能待实现！\n");
                if (CreateGraph(GList[list_num - 1], V_init,
                                VR_init) ==
                    OK)
                    printf
                            ("图创建成功！\n");
                else {
                    printf
                            ("图创建失败！\n");
                }
                getchar();
                getchar();
                break;
            case 2:
                //printf("\n----DestroyList功能待实现！\n");
                if (DestroyGraph(GList[list_num - 1]) ==
                    OK)
                    printf("图销毁成功！\n");
                else printf("图销毁失败！\n");
                getchar();
                getchar();
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                printf("获取顶点的id是：\n");
                scanf("%d", &location_id);
                if ((result_int = LocateVex(GList[list_num -
                                                  1],
                                            location_id)) !=
                    INFEASTIBLE)
                    printf("该顶点在顶点数组中的位序是%d\n", result_int);
                else printf("获取位序失败！\n");
                getchar();
                getchar();
                break;
            case 4:
                //printf("\n----ListEmpty功能待实现！\n");
                printf("要更改的顶点的id是：\n");
                scanf("%d", &location_id);
                printf("顶点的值应改为：\n");
                scanf("%s", buffer);
                if (PutVex(GList[list_num - 1],
                           location_id, buffer) ==
                    TRUE)
                    printf("更改成功！\n");
                else printf("更改失败！\n");
                getchar();
                getchar();
                break;
            case 5:
                //printf("\n----ListLength功能待实现！\n");
                printf("要获得第一邻接点的顶点的位序是：\n");
                scanf("%d", &location_id);
                if ((result_int = FirstAdjVex(
                        GList[list_num - 1],
                        location_id)) != -1)
                    printf("该顶点的获得第一邻接点的位序是%d\n",
                           result_int);
                else printf("获取失败！\n");
                getchar();
                getchar();
                break;
            case 6:
                //printf("\n----GetElem功能待实现！\n");
                printf("要获取获得下一邻接点的顶点的位序依次是：（空格分隔）\n");
                scanf("%d %d", &location_id, &location_id2);
                if ((result_int = NextAdjVex(GList[list_num
                                                   - 1],
                                             location_id,
                                             location_id2)) !=
                    -1)
                    printf("%d相对于%d的下一邻接点的位序是%d\n",
                           location_id,
                           location_id2, result_int);
                else printf("获取失败！\n");
                getchar();
                getchar();
                break;
            case 7:
                if (InsertVex(GList[list_num - 1],
                              *InitNode()))
                    printf("插入顶点成功\n");
                else printf("插入顶点失败\n");
                getchar();
                getchar();
                break;
            case 8:
                //printf("\n----PriorElem功能待实现！\n");
                printf("要删除的顶点id是：\n");
                scanf("%d", &location_id);
                if (DeleteVex(GList[list_num - 1],
                              location_id) == OK)
                    printf("删除顶点成功\n");
                else printf("删除顶点失败\n");
                getchar();
                getchar();
                break;
            case 9:
                //printf("\n----NextElem功能待实现！\n");
                printf("要连接的两个顶点是（空格分隔）：\n");
                scanf("%d %d", &location_id, &location_id2);
                if (InsertArc(GList[list_num - 1],
                              location_id, location_id2) ==
                    OK)
                    printf("插入弧成功\n");
                else printf("插入弧失败\n");
                getchar();
                getchar();
                break;
            case 10:
                //printf("\n----NextElem功能待实现！\n");
                printf("要删除连接的两个顶点是（空格分隔）：\n");
                scanf("%d %d", &location_id, &location_id2);
                if (DeleteArc(GList[list_num - 1],
                              location_id, location_id2) ==
                    OK)
                    printf("删除弧成功\n");
                else printf("删除弧失败\n");
                getchar();
                getchar();
                break;
            case 11:
                //printf("\n----ListDelete功能待实现！\n");
                DFSTraverse(GList[list_num - 1]);
                getchar();
                getchar();
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                BFSTraverse(GList[list_num - 1]);
                getchar();
                getchar();
                break;
            case 13:
                //f_write
                if (f_write(GList[list_num - 1],
                            FILE_NAME) == OK)
                    printf("写入文件成功\n");
                else printf("写入文件失败\n");
                getchar();
                getchar();
                break;
            case 14:
                //f_read
                if (f_read(GList[list_num - 1],
                           FILE_NAME) == OK)
                    printf("读取图成功\n");
                else printf("读取图失败\n");
                getchar();
                getchar();
                break;
            case 0:
                break;
        }//end of switch
        Show(GList[list_num - 1]);
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}


/***辅助函数***/
//寻找顶点的最后一个弧节点
ArcNode_p GetLastArc(ArcNode_p &arc_p) {
    if ((!arc_p) || (!arc_p->next_arc))return arc_p;
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
        v_new->first_arc->adjvex = adjnode[0];
        v_new->first_arc->next_arc = NULL;
    } else {
        return v_new;
    }
    ArcNode_p new_arc = v_new->first_arc;
    for (int i = 1; i < adjnode.size(); i++) {
        new_arc->next_arc = (ArcNode_p) malloc(
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

//递归深度遍历子函数
void DFS(ALGraph_p G, int v, int visit[]) {
    //图的顶点的搜索指针
    ArcNode_p p;
    //置已访问标记
    int index = LocateVex(G, v);
    if (visit[index] == 0) {
        visit[index] = 1;
        //输出被访问顶点的编号
        printf("%s  ", G->vertices[v].elem.data);
    }
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

//递归广度遍历子函数
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
    /***顶点初始化***/
    //求顶点数量
    //初始化节点列表，data来自V，id是V下标，first_arc初始化为null
    for (; strcmp(V[vex_num], "END"); vex_num++) {
        ChangeElem(G->vertices[vex_num].elem.data,
                   V[vex_num]);
        G->vertices[vex_num].elem.id = vex_num;
        G->vertices[vex_num].first_arc = NULL;
    }
    G->vexnum = vex_num;

    /***弧初始化***/
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

//输入寻找的顶点id，返回顶点在数组中的下标，找不到就返回-1
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

//u为顶点id
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

//u为顶点位序
int FirstAdjVex(ALGraph_p G, int u) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    if (u >= G->vexnum)
        return -1;
    if (!G->vertices[u].first_arc)
        return -1;
    else return G->vertices[u].first_arc->adjvex;
}

//v，w为位序
int NextAdjVex(ALGraph_p G, int v, int w) {
    if (!G) {
        printf("graph not exist!\n");
        return -1;
    }
    //v,w超出顶点数组界限，返回-1
    if (v >= G->vexnum || w >= G->vexnum) {
        printf("w or v not found\n");
        return -1;
    }
    ArcNode_p traverse_v = G->vertices[v].first_arc;

    while (traverse_v) {
        if (traverse_v->adjvex == G->vertices[w].elem.id)
            //如果w是最后一个邻接顶点
            if (!traverse_v->next_arc) {
                return -1;
            } else {
                return
                        traverse_v->next_arc->adjvex;
            }
        traverse_v = traverse_v->next_arc;
    }
    //如果w不是v的邻接顶点就返回错误
    return -1;
}

//v为顶点id
status InsertVex(ALGraph_p G, VNode v) {
    if (!G) {
        printf("graph not exist!\n");
        return ERROR;
    }
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
        if (!new_arc) {
            G->vertices[adj_nodes[i]]
                    .first_arc = (ArcNode_p) malloc(sizeof
                                                            (ArcNode));
            G->vertices[adj_nodes[i]]
                    .first_arc->adjvex = v.elem.id;
            G->vertices[adj_nodes[i]]
                    .first_arc->next_arc = NULL;
        } else {
            new_arc->next_arc = (ArcNode_p) malloc(sizeof
                                                           (ArcNode));
            new_arc->next_arc->adjvex = v.elem.id;
            new_arc->next_arc->next_arc = NULL;
        }

    }
    return OK;
}

//v为id
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
    if (a) {
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

//v，w为id
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
    if (traverse_v->adjvex == w)
        //如果v，w之间已经存在弧，返回error
    {
        printf("arc already exists between v and w\n");
        return ERROR;
    }
    traverse_v->next_arc = (ArcNode_p) malloc(
            sizeof(ArcNode));
    traverse_v->next_arc->adjvex = w;
    traverse_v->next_arc->next_arc = NULL;
    //w添加新的弧节点

    ArcNode_p traverse_w = GetLastArc(G->vertices[index_w]
                                              .first_arc);

    if (!traverse_w) {
        G->vertices[index_w]
                .first_arc = (ArcNode_p) malloc(sizeof
                                                        (ArcNode));
        G->vertices[index_w]
                .first_arc->adjvex = v;
        G->vertices[index_w]
                .first_arc->next_arc = NULL;
    } else {
        traverse_w->next_arc = (ArcNode_p) malloc(sizeof
                                                          (ArcNode));
        traverse_w->next_arc->adjvex = v;
        traverse_w->next_arc->next_arc = NULL;
    }

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
    //检查是否有不连通的顶点
    for (int i = 0; i < G->vexnum; i++)
        if (!visit[i])
            DFS(G, i, visit);
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