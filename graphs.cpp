#include "graphs.h"

void Vertex::setName(int name) { this->name = name; };
void Vertex::setMultiplicity(int multiplicity) { this->multiplicity = multiplicity; };
void Vertex::pushBackConnection(int value) { this->connection.push_back(value); };
void Vertex::setConnection(vector <int> arr) { this->connection = arr; };

Vertex::Vertex()
{
    this->connection.clear();
}
Vertex::~Vertex()
{
    this->connection.clear();
}

Graph::Graph()
{
    this->vertex = {};
}

Graph::~Graph()
{
    this->vertex.clear();
}

void Vertex::clearConnection()
{
    this->connection.clear();
}

void Graph::setElementVertex(int index, Vertex el) 
{
    this->vertex[index].clearConnection();
    this->vertex[index] = el;
}

void Graph::pushBackVertex(Vertex v) { this->vertex.push_back(v); }

void Graph::clearVertexes() 
{ 
    for (int i = 0; i < this->vertex.size(); i++) this->vertex[i].clearConnection();
    this->vertex.clear();
}

bool Graph::checkVertexNameInConnection(int index1, int index2)
{
    int size = this->vertex[index2].getConnection().size();
    for (int i = 0; i < size; i++)
    {
        if(this->vertex[index1].getName() == this->getVertex()[index2].getConnection()[i]) return true;
    }
    return false;
}

void Graph::printAllVertexes()
{
    system("cls");
    int size = this->getVertex().size();
    for (int i = 0; i < size; i++)
    {
        cout << ">>" << i << "<<"
        << endl << ">> Name: " << this->getVertex()[i].getName()
        << endl << ">> Multiplicity: " << this->getVertex()[i].getMultiplicity()
        << endl << ">> Connection: (";
        int conSize = this->getVertex()[i].getConnection().size();
        for (int j = 0; j < conSize; j++)
        {
            if (j == conSize - 1)
                cout << this->getVertex()[i].getConnection()[j];
            else cout << this->getVertex()[i].getConnection()[j] << ", ";
        }
        cout << ")" << endl << endl;
    }
    system("pause");
}

int Graph::addVertexMenu()
{
    bool isGood = true;
    int name;
    int multiplicity;
    int size = this->getVertex().size();
    system("cls");
    while (1)
    {
        cout << "Cancel(-1)" 
        << endl << "Unavailable numbers: ";
        for (int i = 0; i < size; i++)
        {
            if (i == size - 1)
                cout << this->getVertex()[i].getName();
            else cout << this->getVertex()[i].getName() << ", ";
        }
        cout << endl << "Enter the number(>=0) of Vertex: ";
        cin >> name;
        if (name == -1) return 0;
        if (name < -1) 
        {
            system("cls");
            continue;
        }
        for (int i = 0; i < size; i++)
        {
            if (name == this->getVertex()[i].getName())
            {
                isGood = false;
                system("cls");
                cout << "This name is taken! =(" << endl;
                system("pause");
                system("cls");
                break;
            }
            else { isGood = true; }
        }
        cout << isGood;
        if (isGood == false) 
        {
            system("cls");
            continue;
        }
        break;
    }
    system("cls");
    while (1)
    {
        cout << "Cancel(-1)" << endl << endl << "Enter the multiplicity of Vertex (1 or 2): ";
        cin >> multiplicity;
        if (multiplicity == -1) return 0;
        if ((multiplicity < -1) || (multiplicity > 2) || (multiplicity == 0))
        {
            system("cls");
            cout << "Enter correct value! =(" << endl;
            system("pause");
            system("cls");
            continue;
        }
        break;
    }
    Vertex* temp = new Vertex();
    temp->setName(name);
    temp->setMultiplicity(multiplicity);
    this->vertex.push_back(*temp);
    return 0;
}

int Graph::deleteVertexMenu()
{
    int size = this->getVertex().size();
    int number;
    system ("cls");
    if (this->getVertex().size() == 0) { cout << "Count of Vertex = 0" << endl; system("pause"); return 0; }
    while(1)
    {
        number = -2;
        cout  << "Cancel(-1)" << endl << endl << "Number:Name(Multiplicity) >> ";
        if (size == 0)
        { 
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                    cout << i << ":" << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << ") ";
                else cout << i << ":" << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << ") , ";           
            }
        }
        
        cout << endl << endl << "Select the vertex number to delete: ";
        cin >> number;
        if (number == -1) return 0;
        if ((number < -1) || (number > size - 1)) { system("cls"); continue; }
        for (int ver = 0; ver < size; ver++)
        {
            if (this->getVertex()[ver].getMultiplicity() != this->getVertex()[number].getMultiplicity())
            {
                for (int con = 0; con < this->getVertex()[ver].getConnection().size(); con++)
                {
                    if (this->getVertex()[ver].getConnection()[con] == this->getVertex()[number].getName()) this->getVertex()[ver].getConnection().erase(this->getVertex()[ver].getConnection().begin() + con);
                }
            }
        }
        this->getVertex().erase(this->getVertex().begin() + number);
        //delete &this->getVertex()[number];
        break;
    }
    return 0;
}

int Vertex::addConnection(int index)
{
    this->connection.push_back(index);
    return 0;
}

int Graph::addConnectionGraph(int index, int value)
{
    this->vertex[index].addConnection(value);
    return 0;
}

int Graph::addConnectionMenu()
{
    int size = this->getVertex().size();
    int number;
    int conNumber;
    int isChecked = 0;
    int colVertex = 0;
    vector <int> arr;
    system("cls");
    while(1)
    {
        number = -2;
        cout  << "Cancel(-1)" << endl << endl << "Number:Name(Multiplicity) >> ";
        if (size == 0)
        { 
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                    cout << i << ":" << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << ") ";
                else cout << i << ":" << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << ") , ";           
            }
        }
        
        cout << endl << endl << "Select the vertex number to configure the connection: ";
        cin >> number;
        if (number == -1) return 0;
        if ((number < -1) || (number > size - 1)) { system("cls"); continue; }
        break;
    }
    colVertex = 0;
    for (int i = 0; i < size; i++)
    {
        if ((this->getVertex()[number].getMultiplicity() != this->getVertex()[i].getMultiplicity())
        && (this->checkVertexNameInConnection(number, i) == false)) colVertex++;
    }
    system("cls");
    while(1)
    {
        conNumber = -2;
        cout << "Cancel(-1)"
        << endl << "Selected Vertex: " << this->getVertex()[number].getName() << "(" << this->getVertex()[number].getMultiplicity() << ")"
        << endl << "Number:Name(Multiplicity): ";
        if (colVertex == 0)
        {
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if ((this->getVertex()[number].getMultiplicity() != this->getVertex()[i].getMultiplicity()) 
                && (this->checkVertexNameInConnection(number, i) == false))
                {
                    arr.push_back(i);
                    if (i == size - 1)
                        cout << i << ":" << this->vertex[i].getName() << "(" << this->vertex[i].getMultiplicity() << ")";
                    else cout << i << ":" << this->vertex[i].getName() << "(" << this->vertex[i].getMultiplicity() << ") , ";
                }
            }
        }
        cout << endl << endl << "Select the vertex number to configure the connection: ";
        cin >> conNumber;
        if (conNumber == -1) return 0;
        isChecked = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (conNumber == arr[i])
            {
                isChecked = 1;
            }
        }
        if (isChecked == 0)
        {
            system("cls");
            continue;
        }
        /*Vertex* temp = new Vertex();
        *temp = this->getVertex()[number];
        temp->setConnection(this->getVertex()[number].getConnection());
        temp->pushBackConnection(this->getVertex()[conNumber].getName());
        this->setElementVertex(number, *temp);

        *temp = this->getVertex()[conNumber];
        temp->setConnection(this->getVertex()[conNumber].getConnection());
        temp->pushBackConnection(this->getVertex()[number].getName());
        this->setElementVertex(conNumber, *temp);*/
        this->vertex[number].addConnection(this->vertex[conNumber].getName());
        this->vertex[conNumber].addConnection(this->vertex[number].getName());
        break;
    }

    return 0;
}

int Graph::deleteConnectionMenu()
{
    int size = this->getVertex().size();
    int number;
    int conNumber;
    int isChecked = 0;
    int colVertex = 0;
    vector <int> arr;
    system("cls");
    while(1)
    {
        number = -2;
        cout  << "Cancel(-1)" << endl << endl << "Number:Name(Multiplicity) >> ";
        if (size == 0)
        { 
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                    cout << i << ":" << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << ") ";
                else cout << i << ":" << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << ") , ";           
            }
        }
        
        cout << endl << endl << "Select the vertex number to delete the connection: ";
        cin >> number;
        if (number == -1) return 0;
        if ((number < -1) || (number > size - 1)) { system("cls"); continue; }
        break;
    }
    colVertex = 0;
    for (int i = 0; i < size; i++)
    {
        if ((this->getVertex()[number].getMultiplicity() != this->getVertex()[i].getMultiplicity())
        && (this->checkVertexNameInConnection(number, i) == false)) colVertex++;
    }
    system("cls");
    while(1)
    {
        conNumber = -2;
        cout << "Cancel(-1)"
        << endl << "Selected Vertex: " << this->getVertex()[number].getName() << "(" << this->getVertex()[number].getMultiplicity() << ")"
        << endl << "Number: Multiplicity:  ";
        if (arr.size() == 0)
        {
            cout << "empty";
        }
        else
        {
            int k = 0;
            for (int i = 0; i < this->getVertex()[number].getConnection().size(); i++)
            {
                if (i != this->getVertex()[number].getConnection().size() - 1)
                    cout << i << ":" << this->getVertex()[number].getConnection()[i] << " , ";
                else cout << i << ":" << this->getVertex()[number].getConnection()[i];
            }
        }
        cout << endl << endl << "Select the connection number to delete: ";
        cin >> conNumber;
        if (conNumber == -1) return 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (conNumber == arr[i])
            {
                isChecked = 1;
            }
        }
        if (isChecked == 0)
        {
            system("cls");
            continue;
        }
        
        system("pause");
        int nameCon = this->vertex[number].getConnection()[conNumber];
        int verSize = this->vertex.size();
        for (int i = 0; i < verSize; i++)
        {
            if (this->vertex[i].getName() == nameCon)
            {
                int conSize = this->vertex[i].getConnection().size();
                for (int con = 0; con < conSize; con++)
                {
                    if (this->vertex[number].getName() == this->vertex[i].getConnection()[con])
                    {
                        this->vertex[i].deleteSelectedConnection(con);
                        break;
                    }
                }
                break;
            }
        }
        this->vertex[number].deleteSelectedConnection(conNumber);
        break;
    }
    return 0;
}

int Vertex::deleteSelectedConnection(int index)
{
    this->connection.erase(this->connection.begin() + index);
    return 0;
}

int menu()
{   
    Graph* graph = new Graph();
    while(1)
    {
        system("cls");
        cout << "1.Add Vertex" << endl
        << "2.Delete Vertex" << endl
        << "3.Add Connection" << endl
        << "4.Delete Connection" << endl
        << "5.View All Vertexes" << endl
        << "0.Exit" << endl << endl;
        char symbol;
        symbol = getch();
        switch(symbol)
        {
            case '1':
            {
                graph->addVertexMenu();
                break;
            }
            case '2':
            {
                graph->deleteVertexMenu();
                break;
            }
            case '3':
            {
                graph->addConnectionMenu();
                break;
            }
            case '4':
            {
                graph->deleteConnectionMenu();
                break;
            }
            case '5':
            {
                graph->printAllVertexes();
                break;
            }
            case '0':
            {
                exit(0);
            }
            default:
            {
                continue;
            }
        }
        continue;
    }
    return 0;
}

int Graph::addVertex(int name, int multiplicity)
{
    Vertex temp;
    temp.setName(name);
    temp.setMultiplicity(multiplicity);
    temp.clearConnection();
    this->pushBackVertex(temp);
    return 0;
}

int Graph::deleteVertex(int index)
{
    int size = this->vertex.size();
    for (int ver = 0; ver < size; ver++)
        {
            if (this->vertex[ver].getMultiplicity() != this->vertex[index].getMultiplicity())
            {
                for (int con = 0; con < this->vertex[ver].getConnection().size(); con++)
                {
                    if (this->vertex[ver].getConnection()[con] == this->vertex[index].getName()) this->vertex[ver].deleteSelectedConnection(con);
                }
            }
        }
        this->vertex.erase(this->vertex.begin() + index);
    return 0;
}

int Graph::fillGraphToComplete()
{
    int sizeVer = this->vertex.size();
    for (int ver = 0; ver < sizeVer; ver++)
    {
        for(int i = 0; i < sizeVer; i++)
        {
            if (ver != i) 
            {
                if (this->vertex[ver].getMultiplicity() != this->vertex[i].getMultiplicity())
                {
                    this->vertex[ver].addConnection(this->vertex[i].getName());
                }
            }
        }
    }
    return 0;
}

int Graph::generateOrderedGraph(int size)
{
    Vertex temp;
    int multiplicity = 1;
    for(int ver = 0; ver < size; ver++)
    {
        temp.setName(ver);
        temp.setMultiplicity(multiplicity);
        if(multiplicity == 1) multiplicity = 2;
            else multiplicity = 1;
        this->vertex.push_back(temp);
    }
    return 0;
}

int timeTest()
{
    vector<int64_t> data[10];
    system_clock::time_point start;
    system_clock::time_point end;
    int64_t time;
    string funcName[14] = { "Fill" };

    Graph graph;
    
    int name = 0;
    int multiplicity = 1;
    int min = 1000;
    int max = 10000;
    int step = 1000;
    int loading = 0;

    for (int size = min; size <= max; size += step)
    {
        graph.generateOrderedGraph(size);       //Генерация упорядоченного графа без связей

        start = system_clock::now();
        graph.fillGraphToComplete();            //Заполнение графа всеми связями
        system("cls");
        loading = (int)(((double)size/(double)max)*100);
        cout << "loading...(" << loading << "%)";
        end = system_clock::now();
        time = duration_cast<microseconds>(end - start).count();
        //cout << time << endl;
        data[0].push_back(time);
        
        graph.clearVertexes();
    }
    
    int size = 0;
    for (int i = 0; i < 1; i++)
    {
        size = min;
        outFile << "----------" << funcName[i] << "----------" << endl;
        for (int j = 0; j < data[i].size(); j++)
        { outFile << "Size: " << size << "  " << "Time : " << data[i][j] << endl; size += step; }
    }
    outFile << "------------------------------" << endl;
    outFile.close();
    return 0;
}

int main()
{
    char choise;
    while (1)
    {
        system("cls");
        cout << "1 - Menu" << endl
        << "2 - Test" << endl
        << "0 - Exit" << endl; 
        choise = getch();
        switch (choise)
        {
            case '1': 
                menu();
                break;
            case '2': 
                timeTest();
                break;
            case '0': 
                exit(0);
            default:
                continue;
        };
        return 0;
    }
    return 0;
}