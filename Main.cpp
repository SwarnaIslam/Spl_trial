#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include"spliter.h"
#include"definition.h"
#include"memory.h"
#include"execution.h"
#include"operator.h"
using namespace std;
string pathName;
int main()
{
	cout<<"Enter path name of the MIPS assembly file: "<<endl;
	cin>>pathName;
	startExecution(pathName);
	cout<<"successfulEnding"<<endl;
	return 0;
}