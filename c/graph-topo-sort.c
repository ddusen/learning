#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1
#define OVERFLOW 0
#define INFINITY 65535
#define VERTEX_MAX_NUM 20

typedef int Status;
typedef char VertexType;
typedef int ArcType;

typedef struct ArcNode{
    int adjvex;
    ArcType data;
    struct ArcNode *next;
}ArcNode, *ArcList;
typedef struct VNode{
    VertexType name;
    ArcList arc;
}VNode, AdjList[VERTEX_MAX_NUM];
typedef struct{
    AdjList adj;
    int vernum,arcnum;
}LGraph;

//create digraph
Status createDGraph(LGraph *lg){
    lg->vernum = 5;
    lg->arcnum = 5;

    lg->adj[0].name = 'A';
    lg->adj[1].name = 'B';
    lg->adj[2].name = 'C';
    lg->adj[3].name = 'D';
    lg->adj[4].name = 'E';

    ArcNode *node00 = (ArcNode *)malloc(sizeof(ArcNode));
    node00->adjvex = 1;
    ArcNode *node01 = (ArcNode *)malloc(sizeof(ArcNode));
    node01->adjvex = 2;
    node01->next = NULL;
    node00->next = node01;
    lg->adj[0].arc = node00;
    
    lg->adj[1].arc = NULL;

    ArcNode *node20 = (ArcNode *)malloc(sizeof(ArcNode));
    node20->adjvex = 1;
    node20->next = NULL;
    lg->adj[2].arc = node20;

    ArcNode *node30 = (ArcNode *)malloc(sizeof(ArcNode));
    node30->adjvex = 2;
    ArcNode *node31 = (ArcNode *)malloc(sizeof(ArcNode));
    node31->adjvex = 4;
    node31->next = NULL;
    node30->next = node31;
    lg->adj[3].arc = node30;
 
    lg->adj[4].arc = NULL;

    return OK;
}

void printDGraph(LGraph lg){
    printf("========== Digraph: ==========\n");
    printf("vernum: %d\n", lg.vernum);
    printf("arcnum: %d\n", lg.arcnum);
    printf("vertex: ");
    for(int i=0; i<lg.vernum; i++){
        printf("%c ", lg.adj[i].name);
    }
    printf("\n");
    printf("adj list:\n");
    for(int i=0; i<lg.vernum; i++){
        printf("\t%c [ ", lg.adj[i].name);
        ArcNode *target = lg.adj[i].arc;
        while(target){
            printf("%c, ", lg.adj[target->adjvex].name);
            target = target->next;
        }
        printf("]\n");
    }
}

int main(){
    LGraph lg;
    createDGraph(&lg);
    printDGraph(lg);

    return 0;
}
