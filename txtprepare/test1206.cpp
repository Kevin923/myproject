#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;
 
vector<float> segmentation(string s)
{
	//多余了 前面有空格也无所谓
	// int start=0;
	// int end=-1;
	// if(s[0]==' ')
	// {
	// 	while(s[start]==' ')
	// 	{
	// 		end=start;
	// 		start++;
	// 	}
	// 	s.erase(0,end);	
	// }

	vector<float> pdata;
	bool temp=false;
	int ndata=0;   //整数部分
	double fdata=0; //小数部分 
	int n=0;//小数部分的位数
	int m=0;

	for(int i=0;i<s.size(); )
	{	
		int j=i;
		if(s[j]=='*')
		{
			int left,right=0;
			int u=0;
			j--;
			while(s[j]!=' '&&j!=-1)
			{
				left+=(s[j]-'0')*pow(10,u);
				j--;
				u++;
			}
			i++;
			while (s[i]!=' ')
			{
				right*=10;
				right+=(s[i]-'0');
				i++;
			}
			for(int k=0;k<left;k++)
				pdata.push_back(right);
		}
		
		while((s[i]>='0')&&(s[i]<='9')||(s[i]=='.'))
		{
			temp=true;
			if(s[i]=='.')//遇到了小数点
			{
				//不停的读取后面的小数
				i++;//小数后的下一位
				while((s[i]>='0')&&(s[i]<='9'))
				{
					n--;
					fdata += (pow(10, n)*(s[i]-'0'));
					i++;
				}
			}
			//没有遇到小数点
			else
			{
				if(s[++i]=='*') //进不去 识别不了*号
				{
					temp=false;
					ndata=0;
					i--;
					break;
				}
				else
				{
					i--;
					ndata*=10;
					ndata+=(s[i]-'0');
					i++;
				}
			}		
		}

		//刚读取了数据
		if(temp)
		{
			pdata.push_back(ndata+fdata);
			m++;
			ndata=0;
			fdata=0;
			n=0;
			temp=false;
		}
		//if(s[i]==' ')
		i++;
	}
	return pdata;
}

int main()
{
	//文件中有字符 也有数字 光创建string也好使 光输出字符串型的temp可也将全部内容都输出
	//C++11  有字符串转int型函数 stoi() 或itos()
	string temp;

	ifstream infile("E:\\C++project\\txtprepare\\11.txt");//打开文件
	ofstream outfile("E:\\C++project\\txtprepare\\22.txt",ios::trunc); //输出到22.txt文件中  trunc:每次都清空 app：接着上回的文件继续输入
	
	if (!infile.is_open())
	{
		std::cout << "无法打开文件！" << endl;
	}

	while (getline(infile,temp))
	{
		if(temp[0]>='a'&&temp[0]<='z' ||temp[0]>='A'&&temp[0]<='Z' ||temp[0]=='-')
		{
			outfile<<temp<<endl;
		}
		else if(temp[0]>='0'&&temp[0]<='9'||temp[0]==' ')
		{
			vector<float> pp=segmentation(temp);
			for(int i=0;i<pp.size();i++)
			{
				outfile<<pp[i]<<' ';
			}
			
			// for(int i=0;i<pp.size();i++)
			// 	std::cout << pp[i] << " ";
			// std::cout<<endl;
		}

		// cout<<temp;
		// cout<<endl; 
		// outfile<<temp;
		// outfile<<endl;    //插入器(<<)向文件输入 析取器(>>)从文件输出    
	}


	// for(int i=0;i<temp.size();i++) //temp存的只是最后一个字符流 即11/
	// {
	// 	cout<<temp[i]<<' '; // 1 1 /
	// }


	infile.close();//关闭文件
	outfile.close();

	getchar(); 
    return 0;

}