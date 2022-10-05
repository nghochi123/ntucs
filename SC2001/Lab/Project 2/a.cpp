#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <string>
using namespace std;
using namespace std::chrono;

int operations;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        operations++;
        if (sptSet[v] == false && dist[v] <= min)
        {
            operations++;
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int V)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            continue;
        else
            cout << i << " \t\t" << dist[i] << endl;
}

// Driver program to test above functions
int main()
{
    for (int i = 5; i < 25; i++)
    {

        // create the graph given in above figure
        std::fstream myfile("./datasets/10x" + to_string(i), std::ios_base::in);

        int V, src, dest, weight, endOfGraph = -1, endOfData = -2, graphNo = 0, source = 0;

        std::ofstream outfile("output(A)(10x" + to_string(i) + ").csv");
        outfile << "time_taken(ms)" << ',' << "numOfEdges" << ',' << "numOfNodes"
                << ","
                << "operations" << std::endl;

        myfile >> V;
        while (V != -2)
        {
            operations = 0;
            int graph[V][V];
            for (int i = 0; i < V; ++i)
            { // for each row
                for (int j = 0; j < V; ++j)
                { // for each column

                    graph[i][j] = 0;
                }
            }

            while (myfile >> src)
            {

                if (src != endOfGraph)
                {
                    myfile >> dest >> weight;
                    graph[src][dest] = weight;
                    graph[dest][src] = weight;
                }
                else
                    break;
            }
            auto start = high_resolution_clock::now();

            ios_base::sync_with_stdio(false);

            // Start of code that implements Dijkstra's single source shortest path algorithm
            // for a graph represented using adjacency matrix representation

            int dist[V]; // The output array. dist[i] will hold the shortest
                         // distance from src to i

            bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
                            // path tree or shortest distance from src to i is finalized

            // Initialize all distances as INFINITE and stpSet[] as false
            for (int i = 0; i < V; i++)
                dist[i] = INT_MAX, sptSet[i] = false;

            // Distance of source vertex from itself is always 0
            dist[source] = 0;

            // Find shortest path for all vertices
            for (int count = 0; count < V - 1; count++)
            {
                // Pick the minimum distance vertex from the set of vertices not
                // yet processed. u is always equal to src in the first iteration.
                int u = minDistance(dist, sptSet, V);

                // Mark the picked vertex as processed
                sptSet[u] = true;

                // Update dist value of the adjacent vertices of the picked vertex.
                for (int v = 0; v < V; v++)
                {
                    // Update dist[v] only if is not in sptSet, there is an edge from
                    // u to v, and total weight of path from src to v through u is
                    // smaller than current value of dist[v]
                    operations++;
                    if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    {
                        operations++;
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }

            auto stop = high_resolution_clock::now();
            // print the constructed distance array
            printSolution(dist, V);

            // Calculating total time taken by the program.
            auto duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by function: "
                 << duration.count() << " microseconds" << endl;

            cout << "Operations: " << operations << endl;

            // Collect time taken data for each graph
            outfile << duration.count() << ',' << (++graphNo) * 40 << ',' << V << "," << operations << std::endl;

            myfile >> V;
        }
        outfile.close();
    }

    return 0;
}
