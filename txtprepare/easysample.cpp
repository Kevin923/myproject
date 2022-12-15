#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main() //1
{
    ifstream ifile("E:\\C++project\\txtprepare\\33.txt");
    string temp;

    while(getline(ifile,temp))
    {
        cout<<temp;    
    }

    // cout<<10+('9'-'0')<<endl; //19
    getchar();
    return 0; 
}