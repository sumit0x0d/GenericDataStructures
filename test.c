#include "graph-adjacency_list/graph-adjacency_list.h"

#include "graph-print.h"
int main()
{
    GraphAdjacencyList G = graph_adjacency_list_construct();
    int x = 10;
    int l = 10000;
    graph_adjacency_list_vertex_insert(&G, &x, INT, sizeof x);
    graph_adjacency_list_vertex_insert(&G, &l, INT, sizeof l);
    graph_print(&G);
}