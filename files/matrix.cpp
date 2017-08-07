#include <iostream>
#include "matrix.h"

using namespace std;



Graph:: Graph(int vertexCount)
{
            this->vertexCount = vertexCount;
            adjacencyMatrix = new float*[vertexCount];
            for (int i = 0; i < vertexCount; i++) {
            adjacencyMatrix[i] = new float[vertexCount];
            for (int j = 0; j < vertexCount; j++)
            adjacencyMatrix[i][j] = 0;
            }
}


void Graph :: addEdge(float dis,int i, int j)
{
            if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
            if(dis==0){
            if(i==j){
            adjacencyMatrix[i][j] =  0;}
            else
                return;
            return;
            }
            else{
            adjacencyMatrix[i][j]=dis;
            adjacencyMatrix[j][i]=dis;
            return;
            }

            }
}



void Graph :: print()
{
  return printMatrix(vertexCount);
}



void Graph :: printMatrix(int vertexCount)
{
    cout<<endl<<"\tAdjacency Matrix of Distance Between Files\t"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

    for(int i=0;i<vertexCount;i++){
       cout<<"\t";
    for(int j=0;j<vertexCount;j++){
            cout<<adjacencyMatrix[i][j]<<"            ";}
    cout<<""<<endl;
    }
    return;
}
