#include <iostream>
#include <vector>
using namespace std;
string vector_string_formatter(vector<string> list)
{
    // vectors of strings are formatted for cout printing
    string temp = "{ ";
    if (list.size() > 1)
    {
        for (auto i = list.begin(); i != list.end(); i++)
        {
            temp = temp.append(*i);
            if (i != list.end() - 1)
            {
                temp.append(", ");
            }
        }
    }
    else
    {
        temp.append(list[0]);
    }
    temp.append(" }");
    return temp;
}
