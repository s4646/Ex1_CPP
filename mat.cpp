#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

namespace ariel
{
    string convertToString(char a[], int size)
    {
        int i;
        string s = "";
        for (i = 0; i < size; i++) {
            s = s + a[i];
        }
        return s;
    }

    string evenRow(int rowIndex, int columns, char a, char b)
    {
        char arr[columns];
        for(int i = 0; i < columns; i++)
            arr[i] = b;

        int times = (rowIndex+1)/2;
        for(int i = 0; i < times; i++)
        {
            arr[2*i] = a;
            arr[columns-1-(2*i)] = a;
        }
        string ret = convertToString(arr,columns);
        return ret;
    }

    string oddRow(int rowIndex, int columns, char a, char b)
    {
        char arr[columns];
        for(int i = 0; i < columns; i++)
            arr[i] = a;

        int times = (rowIndex+1)/2;
        for(int i = 0; i < times; i++)
        {
            arr[2*i + 1] = b;
            arr[columns-2-(2*i)] = b;
        }
        string ret = convertToString(arr,columns);
        return ret;
    }
    
    
    string mat(int y, int x, char a, char b)
    {
       // check for invalid input
       try
        {
            if(x%2==0 || y%2==0 || x<1 || y<1)
            {
                throw invalid_argument("Invalid argument");
            }
        }
        catch(string e)
        {
            // cerr << e << endl;
            return e;
        }

        string matt = "";
        
        int median = (x/2);

        // print top half of the mat
        string temp;
        for(int i = 0; i < median; i++)
        {
            if((i+1)%2==0)
            {
                temp = evenRow(i, y, a, b);
                matt += temp;
            }
            else
            {
                temp = oddRow(i, y, a, b);
                matt += temp;
            }
            matt += '\n';
        }

        // print median row
        if((median+1)%2==0)
            temp = evenRow(median, y, a, b);
        else
            temp = oddRow(median, y, a, b);
        matt += temp;
        matt += '\n';
        
        // print bottom half of the mat
        for(int i = median-1; i > -1; i--)
        {
            if((i+1)%2==0)
            {
                temp = evenRow(i, y, a, b);
                matt += temp;
            }
            else
            {
                temp = oddRow(i, y, a, b);
                matt += temp;
            }
            matt +='\n';
        }

        return matt;
    }
}

// int main()
// {
//     cout << ariel::mat(7, 9, '(', ')');
//     return 0;
// }