#include "graph.h"

extern void graph_print(struct Graph *graph);

int main()
{
    struct Graph graph = graph_construct(sizeof (long));
    long x = 10, y = 20;
    graph.vertex_insert(&graph, &x);
    graph.vertex_insert(&graph, &y);
    graph_print(&graph);

}