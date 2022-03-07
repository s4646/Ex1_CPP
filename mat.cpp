#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    string convertToString(vector<char> a, int size)
    {
        string s;
        for (int i = 0; i < size; i++) {
            s += a[i];
        }
        return s;
    }

    string evenRow(int rowIndex, int columns, char a, char b)
    {
        vector<char> arr;
        for(int i = 0; i < columns; i++)
        {
            arr.insert(arr.end(), b);
        }

        int times = (rowIndex+1)/2;
        for(int i = 0; i < times && (2*i) < columns; i++)
        {
            arr.at(2*i) = a;
            arr.at(columns-1-(2*i)) = a;
        }
        string ret = convertToString(arr,columns);
        return ret;
    }

    string oddRow(int rowIndex, int columns, char a, char b)
    {
        vector<char> arr;
        for(int i = 0; i < columns; i++)
        {
            arr.insert(arr.end(),a);
        }
        int times = (rowIndex+1)/2;
        // one column mat case
        if(columns==1)
        {
            string ret = convertToString(arr,columns);
            return ret;
        }
        for(int i = 0; i < times && (2*i) < columns; i++)
        {
            arr.at(2*i + 1) = b;
            arr.at(columns-2-(2*i)) = b;
        }
        string ret = convertToString(arr,columns);
        return ret;
    }
    
    
    string mat(int columns, int rows, char a, char b)
    {
       // check for invalid input
       try
        {
            if(rows%2==0 || columns%2==0 || rows<1 || columns<1)
            {
                throw invalid_argument("Invalid argument");
            }
        }
        catch(string e)
        {
            // cerr << e << endl;
            return e;
        }

        string matt;
        
        int median = (rows/2);

        // print top half of the mat
        string temp;
        for(int i = 0; i < median; i++)
        {
            if((i+1)%2==0)
            {
                temp = evenRow(i, columns, a, b);
                matt += temp;
            }
            else
            {
                temp = oddRow(i, columns, a, b);
                matt += temp;
            }
            matt += '\n';
        }

        // print median row
        if((median+1)%2==0)
        {
            temp = evenRow(median, columns, a, b);
        }
        else
        {
            temp = oddRow(median, columns, a, b);
        }
        matt += temp;
        matt += '\n';
        
        // print bottom half of the mat
        for(int i = median-1; i > -1; i--)
        {
            if((i+1)%2==0)
            {
                temp = evenRow(i, columns, a, b);
                matt += temp;
            }
            else
            {
                temp = oddRow(i, columns, a, b);
                matt += temp;
            }
            matt +='\n';
        }

        return matt;
    }
}