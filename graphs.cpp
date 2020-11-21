#include "graphs.h"

void Vertex::setName(int name) { this->name = name; };
void Vertex::setMultiplicity(int multiplicity) { this->multiplicity = multiplicity; };
void Vertex::pushBackConnection(int index) { this->connection.push_back(index); };

Graph::Graph()
{
    
}

Graph::~Graph()
{
    this->vertex.clear();
}

void Graph::pushBackVertex(Vertex &v) { this->vertex.push_back(v); }

void Graph::clearVertexes() { this->getVertex().clear(); }

//void Graph::setPushBackVertex(Vertex &temp) { this->vertex.push_back(temp); }

void Graph::printAllVertexes()
{
    system("cls");
    int size = this->getVertex().size();
    for (int i = 0; i < size; i++)
    {
        cout << ">>" << i << "<<"
        << endl << ">> Number: " << this->getVertex()[i].getName()
        << endl << ">> Multiplicity: " << this->getVertex()[i].getMultiplicity() << endl << endl;
    }
    system("pause");
}

void Graph::printConnection()
{
    system("cls");
    int size = this->getVertex().size();
    for (int i = 0; i < size; i++)
    {
        cout << ">>" << i << "<<"
        << endl << ">> Number: " << this->getVertex()[i].getName()
        << endl << ">> Multiplicity: " << this->getVertex()[i].getMultiplicity()
        << endl << ">> Conection: (";
        for (int j = 0; j < this->getVertex()[i].getConnection().size(); j++)
        {
            if (j != this->getVertex()[i].getConnection().size() - 1)
                cout << this->getVertex()[i].getConnection()[j] << ", ";
            else cout << this->getVertex()[i].getConnection()[j];
        }
        cout << ")" << endl << endl;
    }
    system("pause");
}

int Graph::addVertex()
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
            cout << this->getVertex()[i].getName() << ", ";
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
    //cout << endl << "Name: " << name << endl << "Multiplicity: " << multiplicity;
    Vertex temp;
    temp.setName(name);
    temp.setMultiplicity(multiplicity);
    //cout << endl << "Temp Name: " << temp.getName() << endl << "Temp Multiplicity: " << temp.getMultiplicity() << endl;
    //system("pause");
    //this->setPushBackVertex(temp);
    this->pushBackVertex(temp);
    return 0;
}

int Graph::addConnection()
{
    int size = this->getVertex().size();
    int number;
    int conNumber;
    int isChecked;
    vector <int> arr;
    while(1)
    {
        number = -2;
        cout  << "Cancel(-1)" << endl << endl << "Number: Name(Multiplicity): ";
        if (size == 0)
        { 
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << i << ": " << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << "), ";
            }
        }
        
        cout << endl << endl << "Select the vertex number to configure the connection: ";
        cin >> number;
        if (number == -1) return 0;
        if ((number < -1) || (number > size - 1)) { system("cls"); continue; }
        break;
    }
    for (int i = 0; i < size; i++)
    {
        if (this->getVertex()[number].getMultiplicity() == this->getVertex()[i].getMultiplicity()) arr.push_back(i);
    }
    system("cls");
    while(1)
    {
        conNumber = -2;
        cout << "Cancel(-1)"
        << endl << "Selected Vertex: " << this->getVertex()[number].getName() << "(" << this->getVertex()[number].getMultiplicity() << ")"
        << endl << "Name(Multiplicity): ";
        if (arr.size() == 0)
        {
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (this->getVertex()[number].getMultiplicity() == this->getVertex()[i].getMultiplicity())
                {
                    cout << i << ": " << this->getVertex()[i].getName() << "(" << this->getVertex()[i].getMultiplicity() << "), ";
                }
            }
        }
        cout << endl << endl << "Select the vertex number to configure the connection: ";
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
        this->getVertex()[number].pushBackConnection(conNumber);
        this->getVertex()[conNumber].pushBackConnection(number);
    }

    return 0;
}

int menu()
{   
    Graph* graph = new Graph();
    while(1)
    {
        system("cls");
        cout << "1.Add Vertex" << endl
        << "2.View All Vertexes" << endl
        << "3.Add Connection" << endl
        << "4.Print Connection" << endl
        << "0.Exit" << endl << endl;
        char symbol;
        symbol = getch();
        switch(symbol)
        {
            case '1':
            {
                graph->addVertex();
                break;
            }
            case '2':
            {
                graph->printAllVertexes();
                break;
            }
            case '3':
            {
                graph->addConnection();
                break;
            }
            case '4':
            {
                graph->printConnection();
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
    }
    return 0;
}

int main()
{
    menu();
    /*vector <int> test = {1, 2, 3, 4};
    cout << "input array: ";
    for (int i=0; i<test.size();i++) cout << test[i] << " ";
    test.push_back(5);
    cout << endl << "Array after push_back(5): ";
    for (int i=0; i<test.size();i++) cout << test[i] << " ";
    auto iter = test.cbegin();
    test.emplace(iter + 1, 9);
    cout << endl << "Array after emplace(iter=1, 9): ";
    for (int i=0; i<test.size();i++) cout << test[i] << " ";
    test.erase(iter + 1);
    cout << endl << "Array after erase(iter=1): ";
    for (int i=0; i<test.size();i++) cout << test[i] << " ";*/
    return 0;
}