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
        printf("      Menu for Linear Table On Sequence Structure \n");
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
                    printf("线性表销毁成功！\n");
                else printf("线性表销毁失败！\n");
                getchar();
                getchar();
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                printf("获取顶点的id是：\n");
                scanf("%d", &location_id);
                if ((result_int = LocateVex(GList[list_num -
                                                  1],
                                            location_id)) ==
                    OK)
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
                        location_id)) ==
                    OK)
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
                                             location_id2) )!=-1)
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
                DFSTraverse(GList[list_num-1]);
                getchar();
                getchar();
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                BFSTraverse(GList[list_num-1]);
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
        Show(GList[list_num-1]);
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}

