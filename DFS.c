#include <stdio.h>
#define size 6

int adj_mat[size][size];
int vis[size];

struct stacks{
    int arr[size];
    int top;
}s;

void push(int z){
    s.top++;
    s.arr[s.top]=z;
}

int pop(){
    int t;
    t=s.arr[s.top];
    s.top--;
    return t ; 
}

void dfs(int s){
    int p;
    push(s);
    vis[s]=1;
    p=pop();
    if(p!=0){
        printf("%d\t",p);
    }
    while(p!=0){
        for(int i=0;i<=size;i++){
            if(adj_mat[p][i]==1 && vis[i]==0){
                push(i);
                vis[i]=1;
            }
        }
        p=pop();
        if(p!=0){
        printf("%d\t",p);
    }    
    }
}

void main(){
    int nodes,edges,sp,ep,sv;
    int top = -1;
    printf("stacks\n");
    
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            adj_mat[i][j] = 0;
        }
    }
    
    printf("enter the no of nodes\n");
    scanf("%d",&nodes);
    printf("enter the no of edges\n");
    scanf("%d",&edges);
    
    for(int i=0;i<=edges;i++){
        printf("enter the start point\n");
        scanf("%d",&sp);
        printf("enter the end point\n");
        scanf("%d",&ep);
        
        adj_mat[sp][ep]=1;
        adj_mat[ep][sp]=1;
    }
    
    printf("adj_mat is:\n");
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            printf("%d\t",adj_mat[i][j]);
        }
        printf("\n");
    }
    
    printf("enter the source vertex\n");
    scanf("%d",&sv);
    dfs(sv);
}
