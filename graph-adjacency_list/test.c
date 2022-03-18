#include "graph.h"

extern void graph_print(struct Graph *graph);

int main()
{
    struct Graph graph = graph_construct(sizeof (int));
    int x = 1110;
    int y = 551;
    graph_vertex_insert(&graph, &x);
    graph_vertex_insert(&graph, &y);
    graph_print(&graph);
}