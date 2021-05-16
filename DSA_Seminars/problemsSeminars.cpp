#include <iostream>
#include <stack>

using Tower = std::stack<int>;

void reverseStack(Tower original, Tower& copy)
{
    while (!original.empty())
    {
        copy.push(original.top());
        original.pop();
    }
}

int findMaxHeight(Tower one, Tower two, Tower three)
{
    Tower oneCopy, twoCopy, threeCopy;

    reverseStack(one, oneCopy);
    reverseStack(two, twoCopy);
    reverseStack(three, threeCopy);

    int oneHeight = 0, twoHeight = 0, threeHeight = 0;
    int maxHeight = 0;

    while (!oneCopy.empty() || !twoCopy.empty() || !threeCopy.empty())
    {
        if (oneHeight <= twoHeight && oneHeight <= threeHeight)
        {
            if (!oneCopy.empty())
            {
                break;
            }
            
            oneHeight += oneCopy.top();
            oneCopy.pop();
        }
        else if (twoHeight <= threeHeight)
        {
            if (twoCopy.empty())
            {
                break;
            }
            
            twoHeight += twoCopy.top();
            twoCopy.pop();
        }
        else
        {
            if (threeCopy.empty())
            {
                break;
            }
            
            threeHeight += threeCopy.top();
            threeCopy.pop();
        }

        if (oneHeight == twoHeight && twoHeight == threeHeight)
        {
            maxHeight = oneHeight;
        }   
    }
    
    return maxHeight;
}

int main()
{
    return 0;
}