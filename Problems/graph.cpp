#include <iostream>
#include <vector>
#include <queue>

template <typename T>
struct GraphNode
{
    T data;
    std::vector<GraphNode<T>*> related;
    
    GraphNode(T data) : data(data) {}

    int isRelated(GraphNode<T>* vertex)
    {
        for (size_t i = 0; i < related.size(); i++)
        {
            if (related[i] == vertex)
            {
                return i;
            }
        }

        return -1;
    }

    void addEdgeTo(GraphNode<T>* vertex)
    {
        if (isRelated(vertex) == -1) related.push_back(vertex);
    }

    void print()
    {
        for (size_t i = 0; i < related.size(); i++)
        {
            std::cout << related[i]->data << " ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
struct Graph
{
    std::vector<GraphNode<T>*> vertexes;

    Graph() {}
    ~Graph()
    {
        for (size_t i = 0; i < vertexes.size(); i++)
        {
            delete vertexes[i];
        }
    }

    int hasVertex(T data)
    {
        for (size_t i = 0; i < vertexes.size(); i++)
        {
            if (vertexes[i]->data == data)
            {
                return i;
            }
        }
        
        return -1;
    }

    int addVertex(T data)
    {
        int p = hasVertex(data);

        if (p == -1)
        {
            vertexes.push_back(new GraphNode<T>(data));
            return vertexes.size() - 1;
        }
        
        return p;
    }

    void addEdge(T v, T u)
    {
        int p1 = addVertex(v);
        int p2 = addVertex(u);

        GraphNode<T>* node1 = vertexes[p1];
        GraphNode<T>* node2 = vertexes[p2];
        node1->addEdgeTo(node2);
        //node2->addEdgeTo(node1);
    }

    void print()
    {
        for (size_t i = 0; i < vertexes.size(); i++)
        {
            vertexes[i]->print();
        }
    }
};

Graph<int>* readGraph()
{
    int m;
    std::cin >> m;

    Graph<int>* g = new Graph<int>();
    
    for (size_t i = 0; i < m; i++)
    {
        int v, u;
        std::cin >> v >> u;
        g->addEdge(v, u);
    }

    return g;
} 

void dfsPrint(int start)
{
    used[start] = true;
    std::cout << start << std::endl;

    for (size_t i = 0; i < graph[start].size(); i++)
    {
        if (used[i])
        {
            dfsPrint(graph[start][i]);
        }
    }
}

void bfsPrint(int start)
{
    std::queue<int> q;
    q.push(start);
    used[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        std::cout << curr << " ";
        
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (!used[graph[curr][i]])
            {
                q.push(graph[curr][i]);
                used[graph[curr][i]] = true;
            }
        }
    }
}

int main()
{
    Graph<int>* g = readGraph();
    g->print();
}