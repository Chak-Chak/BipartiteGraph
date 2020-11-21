#include <iostream>
#include <vector>
#include <cstdio>
#include <conio.h>

using namespace std;

class Vertex
{
    private:
    int name;
    int multiplicity;
    vector <int> connection;
    public:
    vector <int> getConnection() { return this->connection; };
    void pushBackConnection(int index);
    int getName() { return this->name; };
    void setName(int name);
    int getMultiplicity() { return this->multiplicity; };
    void setMultiplicity(int multiplicity);
};

class Graph
{
    private:
    vector <Vertex> vertex;
    public:
    Graph();
    ~Graph();
    vector <Vertex> getVertex() { return this->vertex; };
    void pushBackVertex(Vertex &v);
    //void setPushBackVertex(Vertex &temp);
    int addVertex();
    int addConnection();
    void printAllVertexes();
    void printConnection();
    void clearVertexes();
};