#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>
#include"spliter.h"
#include"memory.h"
#include"format.h"
#include"definition.h"
//#include"debugger.h"
using namespace std;
vector<string>trimmedInstruction[1000];
int numberOfInstruction=0;
int dataLine=0,textLine=0;
string pathName;
vector<string>instruction;
void getInstruction();
int main()
{
	vector<string>tempOperations{"li","la","add","addi","mul","div","j","jal","bne","beq","move","syscall",".data",".text",".word"};
	vector<string>tempRegister{"$zero","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"};
	cout<<"Enter path name of the MIPS assembly file: "<<endl;
	cin>>pathName;
	getInstruction();
	defineOperations(tempOperations);
	defineRegisters(tempRegister);
	trim(instruction,numberOfInstruction,trimmedInstruction);
	getSections(trimmedInstruction,numberOfInstruction,dataLine,textLine);
	getLabel(trimmedInstruction,numberOfInstruction,dataLine,textLine);
	cout<<"successfulEnding"<<endl;
	return 0;
}
void getInstruction(){
	ifstream file;
	file.open(pathName,ios::in);
	if(!file){
		cout<<"Error: Cannot open the given file!"<<endl;
		exit(0);
	}
	string tempStr;
	for(;;){
		if(!getline(file,tempStr))
			break;
		instruction.push_back(tempStr);
		numberOfInstruction++;
	}
	file.close();
}