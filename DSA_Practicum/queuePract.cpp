#include <iostream>
#include <queue>
#include <stack>

void printQueue(std::queue<int>& q)
{
    for (int i = 0; i < q.size(); i++)
    {
        int curr = q.front();
        std::cout << curr << " ";
        q.push(curr);
        q.pop();
    }
}

int findMin(std::queue<int>& q)
{
    int min = q.front();

    for (int i = 0; i < q.size(); i++)
    {
        int curr = q.front();

        if (min > q.front())
        {
            min = q.front();
        }
        
        q.push(curr);
        q.pop();
    }

    return min;
}

void removeOddElements(std::queue<int>& q)
{
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        int curr = q.front();

        if (curr % 2 == 0)
        {
            q.push(curr);
        }
        
        q.pop();
    }
}

void addTwoQueues(std::queue<int>& q, std::queue<int>& q1, std::queue<int>& q2)
{
    int size = q1.size() + q2.size();
    int size1 = q1.size();

    for (int i = 0; i < size; i++)
    {
        if (i < size1)
        {
            q.push(q1.front());
            q1.pop();
        }
        else
        {
            q.push(q2.front());
            q2.pop();
        }
    }
}

void reverse(std::queue<int>& q)
{
    std::stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop(); 
    }
}

int sequence(int k, int n)
{   
    std::queue<int> q;
    q.push(k);

    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            q.push(k + 1);
        }
        else
        {
            q.push(k * 2);
            k++;
        }
    }
    
    return q.back();
}

std::string toBinary(int n)
{
    std::string s = " ";

    while (n > 0)
    {
        s = ((n % 2) == 0 ? "0" : "1") + s;
        n /= 2;
    }

    return s;
}

void printNumbersInBinary(int n)
{
    std::queue<std::string> q;
    q.push("0");

    for (int i = 1; i < n; i++)
    {
        q.push(toBinary(i));
    }

    for (int i = 0; i < q.size(); i++)
    {
        std::string curr = q.front();
        std::cout << curr << " ";
        q.push(curr);
        q.pop();
    }
}

int main()
{

    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    //printQueue(q);

    std::queue<int> q0;
    std::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    std::queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(6);

    addTwoQueues(q0, q1, q2);
    printQueue(q0);

    std::cout << sequence(42, 4);

    printNumbersInBinary(5);

    return 0;
}