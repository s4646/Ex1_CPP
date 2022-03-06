#ifndef MAT_INCLUDED
#define MAT_INCLUDED

#include <string>
using namespace std;

namespace ariel
{ 
    string convertToString(char* a, int size);  
    string evenRow(int rowIndex, int columns, char a, char b);
    string oddRow(int rowIndex, int columns, char a, char b);
    string mat(int columns, int rows, char a, char b);
}

#endif // MAT_INCLUDED