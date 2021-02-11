// A C# program for Dijkstra's single source shortest path algorithm. 
using System;

namespace Dijkstra
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] graph = new int[,] 
            {
                { 0, 7, 0, 3, 0 }, 
                { 7, 0, 9, 2, 6 }, 
                { 0, 9, 0, 4, 1 }, 
                { 3, 2, 4, 0, 7 }, 
                { 0, 6, 1, 7, 0 } 
            }; 

            DijkstraTools ToolKit = new DijkstraTools(); 
            Console.Write("\n\nWelcome to the world of Dijkstra: The source vertex is 'a'\n\n"); 

            ToolKit.Dijkstra(graph, 0); 
        }
    }

    class DijkstraTools
    { 
        static int VERTICES_COUNT = 5;

        // A utility function to find the vertex with minimum distance 
        // value, from the set of vertices not yet included in shortest 
        // path tree 
        int MinDistance(in int[] distance,in bool[] shortest_path_tree) 
        { 
            // Initialize min values 
            int min = int.MaxValue;
            int min_index = -1; 
    
            for (int v = 0; v < VERTICES_COUNT; v++)
            {
                if (shortest_path_tree[v] == false && distance[v] <= min) 
                { 
                    min = distance[v]; 
                    min_index = v; 
                } 
            } 
            return min_index; 
        } 
    
        // A utility function to print the constructed distance array 
        void PrintSolution(int[] distance, int[] parent) 
        { 
            Console.Write("Vertex\tDistance \\ Path from Source\n"); 
            
            for (int v = 0; v < VERTICES_COUNT; v++)
            {
                Console.Write(Convert.ToChar(v+97) + "\t" + distance[v] + "\t"); 
                PrintPath(parent, v); 
                Console.WriteLine();
            } 
        } 

        void PrintPath(int[] parent, int i) 
         { 
            // Base Case : If i is source 
            if (parent[i] == - 1) 
            {
                Console.Write("   " + Convert.ToChar(i+97) + " "); 
                return; 
            }
            
            PrintPath(parent, parent[i]); 
            
            Console.Write(Convert.ToChar(i+97)+ " "); 
        } 
    
        // Funtion that implements Dijkstra's single source shortest path algorithm 
        // for a graph represented using adjacency matrix representation 
        public void Dijkstra(int[,] graph, int source) 
        { 
            // The output array. distance[v] will hold the shortest distance from src to source 
            int[] distance = new int[VERTICES_COUNT];   

            // Parent array to store shortest path tree 
            int[] parent = new int[VERTICES_COUNT]; 

            // shortest_path_tree[v] will true if vertex v is included in shortest path 
            // tree or shortest distance from source to v is finalized 
            bool[] shortest_path_tree = new bool[VERTICES_COUNT]; 
    
            // Initialize all distances as INFINITE and shortest_path_tree[] as false 
            for (int v = 0; v < VERTICES_COUNT; v++) 
            { 
                distance[v] = int.MaxValue; 
                shortest_path_tree[v] = false; 
                parent[0] = -1; 
            } 
    
            // Distance of source vertex from itself is always 0 
            distance[source] = 0; 
    
            // Find shortest path for all vertices 
            for (int count = 0; count < VERTICES_COUNT - 1; count++) 
            { 
                // Pick the minimum distance vertex from the set of vertices not yet 
                // processed. u is always equal to source in first iteration. 
                int u = MinDistance(distance, shortest_path_tree); 
    
                // Mark the picked vertex as processed 
                shortest_path_tree[u] = true; 
    
                // Update distance value of the adjacent vertices of the picked vertex. 
                for (int v = 0; v < VERTICES_COUNT; v++)
                {
                    // Update distance[v] only if is not in shortest_path_tree, there is 
                    // an edge from u to v, and total weight of path from source to v through u is 
                    // smaller than current value of distance[v]                     
                    if (!shortest_path_tree[v] && 
                        graph[u, v] != 0 && 
                        distance[u] + graph[u, v] < distance[v]) 
                        {
                            parent[v] = u; 
                            distance[v] = distance[u] + graph[u, v]; 
                        }
                }
            } 
            // print the constructed distance array 
            PrintSolution(distance, parent); 
        } 
    }
}