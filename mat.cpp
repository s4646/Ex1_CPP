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
            s += a.at(i);
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
        const int lowLimit = 33;
        const int highLimit = 127;
       // check for invalid input
        if(rows%2==0 || columns%2==0 || rows<1 || columns<1 || a<lowLimit || b<lowLimit || !(a<highLimit) || !(b<highLimit))
        {
            throw invalid_argument("Invalid argument");
        }

        string matrix;
        
        int median = (rows/2);

        // print top half of the mat
        string temp;
        for(int i = 0; i < median; i++)
        {
            if((i+1)%2==0)
            {
                temp = evenRow(i, columns, a, b);
                matrix += temp;
            }
            else
            {
                temp = oddRow(i, columns, a, b);
                matrix += temp;
            }
            matrix += '\n';
        }
        // reverse a copy of the top half
        string rev = matrix;
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
        matrix += temp;
        
        // print bottom half of the mat
            matrix += rev;
            matrix +='\n';
            return matrix;
        }
}

// int main()
// {
//     cout<<"first mat:"<<endl<<ariel::mat(51,31,'@','-')<<endl;
//     cout<<"second mat:"<<endl<<ariel::mat(1,1,'&','!')<<endl;
//     cout<<"third mat:"<<endl<<ariel::mat(1,7,'1','2')<<endl;
//     cout<<"fourth mat:"<<endl<<ariel::mat(7,1,'*','A')<<endl;
//     cout<<"fifth mat:"<<endl<<ariel::mat(3,3,'#','%')<<endl;
//     try
//     {
//         cout<<"sixth mat:"<<endl<<ariel::mat(6,5,'@','-')<<endl;
//     }
//     catch(invalid_argument& e)
//     {
//         cout<<"caught exception: "<<e.what()<<endl;
//     }
//     return 0;
// }