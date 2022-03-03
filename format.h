#ifndef FORMAT_H
#define FORMAT_H
#include"debugger.h"
#include"definition.h"
int getDataSection(vector<string>trimmedInstruction[],int numberOfInstruction){
    int i=0;
    int dataFlag=0;
    int dataLine=-1;
    string isData=".data";
    for(i=0;i<numberOfInstruction;i++){
        if(trimmedInstruction[i][0]!=""){
            if(dataFlag==1&&trimmedInstruction[i][0].c_str()==isData){
                reportAndExit("More than one .data have been found!");
            }
            if(trimmedInstruction[i][0].c_str()==isData){
                dataFlag=1;
                dataLine=i;
            }
        }
    }
    if(dataFlag==0)
        reportAndExit(".data section not found!");
    return dataLine;
}
int getTextSection(vector<string>trimmedInstruction[],int numberOfInstruction){
    int i=0;
    int textFlag=0;
    int textLine=-1;
    string isText=".text";
    for(i=0;i<numberOfInstruction;i++){
        if(textFlag==1&&trimmedInstruction[i][0].c_str()==isText){
            reportAndExit("More than one .text have been found!");
        }
        if(trimmedInstruction[i][0].c_str()==isText){
            textFlag=1;
            textLine=i;
        }
    }
    if(textFlag==0)
        reportAndExit(".text section not found!");
    return textLine;
}
void getSections(vector<string>trimmedInstruction[],int numberOfInstruction,int &dataLine,int &textLine){
    dataLine=getDataSection(trimmedInstruction,numberOfInstruction);
    textLine=getTextSection(trimmedInstruction,numberOfInstruction);
}
bool isValidOperation(string token){
    vector<string>tempOperations=getOperations();
    for(int i=0;i<tempOperations.size();i++){
        if(tempOperations[i]==token)return true;
    }
    return false;
}
bool isValidLabel(string token){
    if(isValidOperation(token))return false;
    for(int i=0;i<token.length();i++){
        if(i==0){
            if(token[0]<65||(token[0]>90&&token[0]<97)||token[0]>121)return false;
        }
        else{
            if(token[i]<65||(token[i]>90&&token[i]<97&&token[i]!='_')||token[i]>121)return false;
        }
    }
    return true;
}
#endif