#include <iostream>
#include <vector>
#include <cstdio>
#include <conio.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

ofstream outFile("out.txt");

class Vertex
{
    private:
    int name;
    int multiplicity;
    vector <int> connection;
    public:
    Vertex();
    ~Vertex();
    vector <int> getConnection() { return this->connection; };
    void setConnection(vector <int> arr);
    void pushBackConnection(int value);
    int getName() { return this->name; };
    void setName(int name);
    int getMultiplicity() { return this->multiplicity; };
    void setMultiplicity(int multiplicity);
    void clearConnection();
    int deleteSelectedConnection(int index);
    int addConnection(int index);
};

class Graph
{
    private:
    vector <Vertex> vertex;
    public:
    Graph();
    ~Graph();
    vector <Vertex> getVertex() { return this->vertex; };
    void setElementVertex(int index, Vertex el);
    void pushBackVertex(Vertex v);
    int addVertex(int name, int multiplicity);
    int deleteVertex(int index);
    int addVertexMenu();
    int deleteVertexMenu();
    void printAllVertexes();
    void clearVertexes();
    bool checkVertexNameInConnection(int index1, int index2);
    int addConnectionMenu();
    int addConnectionGraph(int index, int value);
    int deleteConnectionMenu();
    int fillGraphToComplete();
    int generateOrderedGraph(int size);
};