#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream> 
 
using namespace std; 
 
int main()  //aaa
{ 
    ifstream myfile("E:\\C++project\\txtprepare\\33.txt"); 
    ofstream outfile("E:\\C++project\\txtprepare\\44.txt", ios::app); 
    string temp; 
    if (!myfile.is_open()) 
    { 
        cout << "未成功打开文件" << endl; 
    } 
    while(getline(myfile,temp)) 
    { 
        outfile << temp; 
        outfile << endl;
    } 
    myfile.close(); 
    outfile.close();
    return 0; 
} 
