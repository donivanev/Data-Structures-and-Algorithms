#include <iostream>
#include <stack>
#include <cstring>

void printStack(std::stack<int> &s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();    
    }
}

void printStringStack(std::stack<char> &s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();    
    }
}

void returnReversedString(const char* str)
{
    std::stack<char> s;

    for (int i = 0; i < strlen(str); i++)
    {
        s.push(str[i]);   
    }

    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
    }
}

template <typename T>
std::stack<T> copyStack(std::stack<T> &s)
{
    std::stack<T> result;
    std::stack<T> helper;

    while (!s.empty())
    {
        helper.push(s.top());
        s.pop();
    }

    while (!helper.empty())
    {
        result.push(helper.top());
        s.push(helper.top());
        result.pop();
    }
    
    return result;
}

bool areBracketsValid(const char* str)
{
    std::stack<char> openingBrackets;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            openingBrackets.push(str[i]);
        }
        else
        {
            if (openingBrackets.empty()) return 0;

            if (str[i] == ')' && openingBrackets.top() != '(' ||
                str[i] == ']' && openingBrackets.top() != '[' ||
                str[i] == '}' && openingBrackets.top() != '{') return 0;

            else openingBrackets.pop();
        }
    }
    
    return openingBrackets.empty();
}

int reversePolishNotation(const char* str)
{
    std::stack<int> stackOfOperands;
    int firstOperand, secondOperand;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '+')
        { 
            firstOperand = stackOfOperands.top();
            stackOfOperands.pop();
            secondOperand = stackOfOperands.top();
            stackOfOperands.pop();
            stackOfOperands.push(firstOperand + secondOperand);
        }
        else if (str[i] == '*')
        {
            firstOperand = stackOfOperands.top();
            stackOfOperands.pop();
            secondOperand = stackOfOperands.top();
            stackOfOperands.pop();
            stackOfOperands.push(firstOperand * secondOperand);
        }
        else
        {
            if (str[i] != ' ')
            {
                stackOfOperands.push(str[i] - '0');
            }   
        } 
    }   

    return stackOfOperands.top();
}

int polishNotation(const char* str)
{
    std::stack<int> stackOfOperands;
    std::stack<char> stackOfOperations;
    int firstOperand, secondOperand;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            (str[i] >= '0' && str[i] <= '9' ) ? stackOfOperands.push(str[i] - '0') : stackOfOperations.push(str[i]);   
        }
    }

    while (!stackOfOperations.empty())
    {
        firstOperand = stackOfOperands.top();
        stackOfOperands.pop();
        secondOperand = stackOfOperands.top();
        stackOfOperands.pop();

        if (stackOfOperations.top() == '+')
        {
            stackOfOperands.push(firstOperand + secondOperand);    
        }
        else if (stackOfOperations.top() == '*')
        {
            stackOfOperands.push(firstOperand * secondOperand);
        }

        stackOfOperations.pop();
    }
    
    return stackOfOperands.top();
}

/*void sortStack(const char* str)
{
    std::stack<char> s;
    std::stack<char> helperStack;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {   
            if (i == 0)
            {
                s.push(str[0]);
            }
            else
            {
                if (str[i] < s.top())
                {
                    while (!s.empty())
                    {
                        if (s.top() < str[i])
                        {
                            break;
                        }

                        helperStack.push(s.top());
                        s.pop();
                    }

                    s.push(str[i]);

                    while (!helperStack.empty())
                    {
                        s.push(helperStack.top());
                        helperStack.pop();
                    }
                }
                else
                {
                    s.push(str[i]);
                }
            }
        }
    }

    printStringStack(s);
}*/

std::stack<int> sortStackSecond(std::stack<int> s)
{
    std::stack<int> helper;

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        while (!helper.empty() && helper.top() > temp)
        {
            s.push(helper.top()); 
            helper.pop();    
        }

        helper.push(temp); 
    }

    return helper;
}

void hanoiProcedure(int n, char a = 'A', char c = 'C', char b = 'B')
{
    if (n == 1)
    {
        std::cout << "From " << a << " to " << c << std::endl;
        return;
    }

    hanoiProcedure(n - 1, a, b, c);
    std::cout << "Moved " << n << " from " << a << " to " << c << std::endl;
    hanoiProcedure(n - 1, b, c, a);
}

int main()
{
    /*std::stack<int> s;

    s.push(1); // 3
    s.push(2); // 2
    s.push(3); // 1

    std::cout << s.top();
    s.pop();
    std::cout << s.top();

    printStack(s);

    const char* str = "symbol";
    returnReversedString(str);

    std::stack<int> temp = copyStack(s);
    printStack(s);

    str = "(([{}])())";
    std::cout << areBracketsValid(str);*/

    //const char* str = "2 2 3 + * 6 *";
    //std::cout << reversePolishNotation(str);

    //str = "+ 1 * 2 + 3 5";
    //17
    //std::cout << polishNotation(str);

    const char* str = "c d a b e";
    //sortStack(str);

    std::stack<int> s1;
    std::stack<int> s2;
    s1.push(1);
    s1.push(1);
    s1.push(1);

    s2.push(2);

    s1.swap(s2);
    //printStack(s1);

    //hanoiProcedure(3);

    str = "(([{}])())";
    std::cout << areBracketsValid(str);

    return 0;
}