#include <iostream>
#include <cmath>

int main()
{
    int start = 1;
    int end = 4;

    int result;
    result = fak(start, end);

    std::cout << result << std::endl;
}

int fak(int start, int end)
{
    int result = start;
    for (int i = start; i < end; i++)
    {
        result = result * (start + i);
    }
    return result;
}