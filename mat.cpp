#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

namespace ariel
{
    /*
        this function converts a vector to a string and returns the string
    */
    string convertToString(vector<char> a, int size)
    {
        string s;
        for (int i = 0; i < size; i++) {
            s += a[i];
        }
        return s;
    }

    /*
        this function creates a single EVEN row string.
        the string is created by the following rules:
        - determine how many times we need to change chars by observing rowIndex
        - since the row is even, we can only modify the even indexes.
          therefore, we scan the vector and modify the 2*i and (columns-1)-(2*i) indexes
          for each i < times

    */
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

    /*
        this function creates a single ODD row string.
        the string is created by the following rules:
        - determine how many times we need to change chars by observing rowIndex
        - since the row is odd, we can only modify the odd indexes.
          therefore, we scan the vector and modify the (2*i)+1 and ((columns-1)-1)-(2*i) indexes
          for each i < times

    */
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
    
    /*
        this function prints the mat
    */
    string mat(int columns, int rows, char a, char b)
    {
        const int f1 = 33;
        const int f2 = 127;
       // check for invalid input
        if(rows%2==0 || columns%2==0 || rows<1 || columns<1 || a<f1 || b<f1 || !(a<f2) || !(b<f2))
        {
            throw invalid_argument("Invalid argument");
        }

        cout<<"rows: "<<rows<<" columns: "<<columns<<" char1: "<<a<<" char2: "<<b<<endl;

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
        // reverse a copy of the top half
        string rev = matt;
        reverse(rev.begin(), rev.end());

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
            matt += rev;
            matt +='\n';
            return matt;
        }
}