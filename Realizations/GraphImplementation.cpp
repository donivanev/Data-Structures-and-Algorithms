#include <iostream>
#include <vector>

template <class T>
class Graph
{
    struct Node
    {
        T data;
        vector<Node*> vertex;
    };

    private:

    void copy(const Graph<T>& other);
    void clear();

    public:

    Graph();
    Graph(const Graph<T>& other);
    Graph& operator=(const Graph<T>& other);
    ~Graph();
};

template <typename T>
Graph<T>::Graph()
{

}

template <typename T>
void Graph<T>::copy(const Graph<T>& other)
{

}

template <typename T>
void Graph<T>::clear()
{

}

template <typename T>
Graph<T>::Graph(const Graph<T>& other)
{
    copy(other)
}

template <typename T>
Graph<T>& Graph<T>::operator=(const Graph<T>& other)
{
    if (this != &other)
    {
        copy(other);
        clear();
    }
    
    return *this;
}

template <typename T>
Graph<T>::~Graph()
{
    clear();
}