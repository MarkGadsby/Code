/********************************************************************
Step 1  Create a set shortPath to store vertices that come in the way 
        of the shortest path tree.
Step 2  Initialize all distance values as INFINITE and assign distance 
        values as 0 for source vertex so that it is picked first.
Step 3  Loop until all vertices of the graph are in the shortPath.
   Step 3.1 Take a new vertex that is not visited and is nearest.
   Step 3.2 Add this vertex to shortPath.
   Step 3.3 For all adjacent vertices of this vertex update distances. 
            Now check every adjacent vertex of V, if sum of distance of
            u and weight of edge is elss the update it.
*********************************************************************/
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define VERTICES_COUNT 5

int MinimumDistance(int distance[], bool shortest_path_tree_set[]) 
{
   int min = INT_MAX;
   int min_index = 0;

   for (int v = 0; v < VERTICES_COUNT; v++)
   {
        if (shortest_path_tree_set[v] == false && distance[v] <= min)
        {
            min = distance[v];
            min_index = v;
        }
   }
   return min_index;
}

int Print(int distance[]) 
{
    printf("Vertex Distance from Source\n");
    
    for (int i = 0; i < VERTICES_COUNT; i++)
        printf("%c \t %d\n", i + 65, distance[i]);
}

void Dijkstra(int graph[VERTICES_COUNT][VERTICES_COUNT], int source)
{
    // create vertex set Q
    int Q[VERTICES_COUNT];
	bool shortest_path_tree_set[VERTICES_COUNT];

	for (int i = 0; i < VERTICES_COUNT; ++i)
	{
		Q[i] = INT_MAX;
		shortest_path_tree_set[i] = false;
	}

    Q[source] = 0;

    for (int count = 0; count < VERTICES_COUNT; ++count)
	{
		int u = MinimumDistance(Q, shortest_path_tree_set);
		shortest_path_tree_set[u] = true;

		for (int v = 0; v < VERTICES_COUNT; ++v)
        {
			if (!shortest_path_tree_set[v] && 
                graph[u][v] && 
                Q[u] != INT_MAX && 
                Q[u] + graph[u][v] < Q[v])
                {
    				Q[v] = Q[u] + graph[u][v];
                }
        }
	}

	Print(Q);
}

int main() 
{
   int graph[VERTICES_COUNT][VERTICES_COUNT] = 
   { 
      { 0, 7, 0, 3, 0 },
      { 7, 0, 3, 2, 6 },
      { 0, 3, 0, 4, 1 },
      { 3, 2, 4, 0, 7 },
      { 0, 6, 1, 7, 0 },
   };
   
   Dijkstra(graph, 0);
   return 0;
}