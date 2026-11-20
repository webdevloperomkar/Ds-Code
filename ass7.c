#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList array[MAX_NODES];
} Graph;

AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (!newNode) {
        perror("Failed to allocate memory for adjacency list node");
        exit(EXIT_FAILURE);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    if (V < 0 || V > MAX_NODES) {
        fprintf(stderr, "Invalid number of vertices: %d (must be 0 to %d)\n", V, MAX_NODES);
        exit(EXIT_FAILURE);
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }

    graph->V = V;
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addConnection(Graph* graph, int src, int dest) {
    if (!graph || src < 0 || src >= graph->V || dest < 0 || dest >= graph->V) {
        fprintf(stderr, "Invalid edge (%d, %d) for graph with %d vertices\n", src, dest, graph ? graph->V : 0);
        return;
    }

    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void bfs(Graph* graph, int startVertex) {
    if (!graph || startVertex < 0 || startVertex >= graph->V) {
        fprintf(stderr, "Invalid start vertex %d for BFS\n", startVertex);
        return;
    }

    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS Traversal starting from user %d: ", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    AdjListNode* temp = graph->array[vertex].head;
    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            dfsUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph* graph, int startVertex) {
    if (!graph || startVertex < 0 || startVertex >= graph->V) {
        fprintf(stderr, "Invalid start vertex %d for DFS\n", startVertex);
        return;
    }

    bool visited[MAX_NODES] = {false};
    printf("DFS Traversal starting from user %d: ", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

void printGraph(Graph* graph) {
    if (!graph) return;

    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\nUser %d connected to: ", v);
        while (pCrawl) {
            printf("%d -> ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Graph* graph) {
    if (!graph) return;

    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* current = graph->array[v].head;
        while (current) {
            AdjListNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph);
}

int main() {
    int numUsers = 5;
    Graph* graph = createGraph(numUsers);

    addConnection(graph, 0, 1);
    addConnection(graph, 0, 2);
    addConnection(graph, 1, 3);
    addConnection(graph, 1, 4);

    printGraph(graph);

    printf("\n--- Graph Traversals ---\n");
    bfs(graph, 0);
    dfs(graph, 0);

    freeGraph(graph);
    return 0;
}