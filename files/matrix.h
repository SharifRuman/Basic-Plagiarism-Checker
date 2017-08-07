#pragma once
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED



using namespace std;


class Graph
{

     private:
		float** adjacencyMatrix;
        int vertexCount;

	 public:
		Graph(int vertexCount);
        void addEdge(float dis,int i, int j);
        void printMatrix(int vertexCount);
        void print();
};


#endif // GRAPH_H_INCLUDED
