#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

string TransName(string str)
{
	unsigned long long h=0;
	for(auto i:str)
	{
		h=h*10000007+i;
	}
	return "cfntextemp_"+to_string(h);
}

string filetype(string str)
{
	int p=-1;
	for(int i=str.length()-1;i>=0;i--)
	{
		if(str[i]=='.')
		{
			p=i;
			break;
		}
	}
	if(p==-1)return "";
	return str.substr(p+1);
}

int system(const string &str)
{
	//cout<<str<<endl;
	//return 0;
	return system(str.c_str());
}

//LaTeX可能用到的所有文件
vector<string> relevantfiles={".tex",".log",".pdf",".out",
".toc",".aux",".synctex.gz",".lof",".lot",".bbl",".blg",
".idx",".ind",".ilg",".ps",".dvi"};

int main(int argc,char **argv0)
{
	vector<string> argv;
	if(argc<2)
	{
		cout<<"please input filename";
		return -1;
	}
	for(int i=0;i<argc;i++)
	{
		argv.push_back(argv0[i]);
	}
	string filename=argv[argv.size()-1];
	//删除拓展名
	if(filetype(filename)=="tex")
	{
		filename=filename.substr(0,filename.size()-4);
	}
	string newname=TransName(filename);
	
	for(auto i:relevantfiles)
	{
		
		system("del "+newname+i);
		system("copy "+filename+i+" "+newname+i);
	}
	string arg="xelatex ";
	for(int i=1;i<argv.size()-1;i++)
	{
		arg+=argv[i];
		arg+=" ";
	}
	//0：正常
	//1：报错
	int returnval=system(arg+newname+".tex");
	for(auto i:relevantfiles)
	{
		if(i!=".tex")
		{	system("del "+filename+i);
			system("ren "+newname+i+" "+filename+i);
		}
		else
		{
			system("del "+newname+i);
		}
	}
	return returnval;
}