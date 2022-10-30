#include <stdio.h>
#define size 6

int adj_mat[size][size];
int vis[size];

struct queue{
    int arr[size];
    int front,rear;
}q;

void enqueue(int z){
    if(q.front== -1){
        q.front++;
        q.rear++;
        q.arr[q.front]=z;
    }
    q.rear++;
    q.arr[q.rear]=z;
}

int dequeue(){
    int t;
    t = q.arr[q.front];
    q.front++;
    return t;
}

void bfs(int s){
    int p;
    enqueue(s);
    vis[s] = 1;
    p = dequeue();
    if (p != 0){
        printf("\t%d", p);
    }
    while (p != 0){
        for (int i = 1; i <= size; i++){
            if (adj_mat[p][i] == 1 && vis[i] == 0){
                enqueue(i);
                vis[i] = 1;
            }
        }
        p = dequeue();
        if (p != 0){
            printf("\t%d", p);
        }
    }
}


void main(){
    int node, edges, sp, ep, sv;
    printf("Queue\n");
    q.front = -1;
    q.rear = -1;

    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= size; j++){
            adj_mat[i][j] = 0;
        }
    }

    printf("Number of nodes: ");
    scanf("%d", &node);
    printf("Number of edges: ");
    scanf("%d", &edges);

    for (int i = 1; i <= edges; i++){
        printf("Enter the start point: ");
        scanf("%d", &sp);
        printf("Enter the end point: ");
        scanf("%d", &ep);

        adj_mat[sp][ep] = 1;
        adj_mat[ep][sp] = 1;
    }

    printf("\nAdjacency Matrix\n");
    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= size; j++){
            printf("%d\t", adj_mat[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter source vertex: ");
    scanf("%d", &sv);
    bfs(sv);
}
