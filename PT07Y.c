#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct graph{
    int v;
    node **arr;
}graph;

graph* createGraph(int v){
    graph* g = (graph*)malloc(sizeof(graph));
    g->v = v;
    g->arr = (node**)malloc((v+1)*sizeof(node*));
    return g;
}

void addEdge(graph* g, int src, int dest){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = dest;
    if(g->arr[src]==NULL)
        g->arr[src] = new_node;
    else{
        new_node->next = g->arr[src];
        g->arr[src] = new_node;
    }
    
    node* new_node2 = (node*)malloc(sizeof(node));
    new_node2->data = src;
    if(g->arr[dest]==NULL)
        g->arr[dest] = new_node2;
    else{
        new_node2->next = g->arr[dest];
        g->arr[dest] = new_node2;
    }
}

void dfsT(graph* g, int src, int visited[]){
    visited[src] = 1;
    node* temp = g->arr[src];
    while(temp!=NULL){
        if(!visited[temp->data]){
            dfsT(g, temp->data, visited);
        }
        temp = temp->next;
    }
}

void dfs(graph *g){
    int comp = 0;
    int count = g->v;
    int visited[count+1];
    int i;
    for(i = 0;i < count+1; i++){
        visited[i] = 0;
    }
    
    for(i = 1;i <= count; i++){
        if(!visited[i]){
            dfsT(g, i, visited);
            comp++;
        }
        if(comp > 1){
            printf("NO\n");
            break;
        }
    }
    if(i > count){
        printf("YES\n");
    }
}


int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	if(edges!=(nodes-1)){
	    printf("NO");
	}else{
	    graph* g = createGraph(nodes);
	    int i;
	    for(i =1 ;i <= edges; i++){
	        int a, b;
	        scanf("%d%d", &a, &b);
	        addEdge(g, a, b);
	    }
	    dfs(g);
	}
	return 0;
}

