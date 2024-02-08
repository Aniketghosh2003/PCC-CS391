#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numvertices;
    struct node **adj;
};

struct node *createnode(int v)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct Graph *creategraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numvertices = vertices;
    graph->adj = malloc(vertices * sizeof(struct node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
    }

    return graph;
}

void addedge(struct Graph *graph, int s, int d)
{

    struct node *newnode = createnode(d);
    newnode->next = graph->adj[s];
    graph->adj[s] = newnode;

    newnode = createnode(s);
    newnode->next = graph->adj[d];
    graph->adj[d] = newnode;
}

void printgraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numvertices; i++)
    {
        struct node *temp = graph->adj[i];
        printf("\n vertex %d :-", i);
        while (temp)
        {
            printf("%d->", temp->vertex);
            temp = temp->next;
        }
    }
}

int main()
{
    struct Graph *graph = creategraph(4);
    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 1, 3);
    addedge(graph, 2, 3);

    printgraph(graph);
    return 0;
}