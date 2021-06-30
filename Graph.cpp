#include <iostream>
#include<string>
#include <cstdlib>
using namespace std;

struct AdjListNode
{
    int des;
    struct AdjListNode* next;
};


struct AdjList
{
    struct AdjListNode* head;
};


class Graph
{
private:

    int V;
    struct AdjList* array;

public:

    Graph(int V)
    {
        this->V = V;
        array = new AdjList[V];
        for (int i = 0; i < V; ++i)
        {
            array[i].head = NULL;
        }
    }


    AdjListNode* newAdjListNode(int destination)
    {
        AdjListNode* newNode = new AdjListNode;
        newNode->des = destination;
        newNode->next = NULL;
        return newNode;
    }


    void addEdge(int source, int destination)
    {
        AdjListNode* newNode = newAdjListNode(destination);
        newNode->next = array[source].head;
        array[source].head = newNode;
        newNode = newAdjListNode(source);
        newNode->next = array[destination].head;
        array[destination].head = newNode;
    }


    void printGraph()
    {

        int v;
        for (v = 0; v < V; ++v)
        {

            AdjListNode* zemo = array[v].head;

            cout << "\n Vertex " << "[" << v << "]";

            while (zemo)
            {
                cout << " ---> " << zemo->des;
                zemo = zemo->next;
            }

            cout << endl;

        }

    }

};


int main()
{

    Graph obj(5);

    obj.addEdge(0, 2);
    obj.addEdge(0, 4);
    obj.addEdge(1, 4);
    obj.addEdge(1, 3);
    obj.addEdge(1, 5);
    obj.addEdge(2, 3);
    obj.addEdge(3, 4);
    obj.printGraph();

    return 0;
}