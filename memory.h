#ifndef MEMORY_H
#define MEMORY_H
#include"debugger.h"
#include"format.h"
int instructionNumber=getNumberOfInstruction();
void getDataLabel(vector<string>trimmedInstruction[],int dataStart, int textStart){
    int dataEnd=0;
    string instructionLine="";
    map<string,bool>hasOccurred;
    if(dataStart>textStart){
        dataEnd=instructionNumber;
    }
    else{
        if(dataStart+1==textStart){
            return;
        }
        else{
            dataEnd=textStart;
        }
    }
    for(int i=dataStart+1;i<dataEnd;i++){
        instructionLine=to_string(i+1);
        int labelFound=-1,j;
        int size=trimmedInstruction[i].size();
        bool labelFlag=false;
        if(trimmedInstruction[i][0]==""){
            continue;
        }
        for(j=0;j<size;j++){
            int tokenLength=trimmedInstruction[i][j].length();
            labelFound=trimmedInstruction[i][j].find(':');
            if(labelFound>-1&&labelFound<tokenLength){
                labelFlag=true;
                break;
            }
        }
        if(labelFlag==false){
            reportAndExit("Unknown operation e",instructionLine);
        }
        string tempLabel="";
        string afterLabel=trimmedInstruction[i][j].substr(labelFound+1);
        if(j==0){
            tempLabel=trimmedInstruction[i][0].substr(0,labelFound);
        }
        else if(j==1){
            tempLabel=trimmedInstruction[i][0];
        }
        else{
            reportAndExit("Wrong format of label",instructionLine);
        }
        if(j==1&&labelFound!=0){
            reportAndExit("Wrong format of label",instructionLine);
        }
        else if(hasOccurred[tempLabel]){
            reportAndExit("Label "+tempLabel+" was defined before",instructionLine);
        }
        else if(afterLabel!=".word"&&afterLabel!=""){
            reportAndExit("Invalid token after ':'",instructionLine);
        }
        else if(!isValidLabel(tempLabel)){
            reportAndExit("Wrong format of label",instructionLine);
        }
        else{
            hasOccurred[tempLabel]=true;
        }  
    }
}
void getTextLabel(vector<string>trimmedInstruction[],int dataStart, int textStart){
    int textEnd=0;
    string instructionLine="";
    map<string,bool>hasOccurred;
    if(dataStart<textStart){
        textEnd=instructionNumber;
    }
    else{
        if(dataStart==textStart+1){
            return;
        }
        else{
            textEnd=dataStart;
        }
    }
    for(int i=textStart+1;i<textEnd;i++){
        instructionLine=to_string(i+1);
        int labelFound=-1,j;
        int size=trimmedInstruction[i].size();
        bool labelFlag=false;
        if(trimmedInstruction[i][0]==""){
            continue;
        }
        for(j=0;j<size;j++){
            int tokenLength=trimmedInstruction[i][j].length();
            labelFound=trimmedInstruction[i][j].find(':');
            if(labelFound>-1&&labelFound<tokenLength){
                labelFlag=true;
                break;
            }
        }
        if(labelFlag==false){
            continue;
        }
        string tempLabel="";
        string afterLabel=trimmedInstruction[i][j].substr(labelFound+1);
        if(j+1<size){
            reportAndExit("No instruction is expected after label name",instructionLine);
        }
        if(j==0){
            tempLabel=trimmedInstruction[i][0].substr(0,labelFound);
        }
        else if(j==1){
            tempLabel=trimmedInstruction[i][0];
        }
        else{
            reportAndExit("Wrong format of label",instructionLine);
        }
        if(j==1&&labelFound!=0){
            reportAndExit("Wrong format of label",instructionLine);
        }
        else if(hasOccurred[tempLabel]){
            reportAndExit("Label "+tempLabel+" was defined before",instructionLine);
        }
        else if(afterLabel!=""){
            reportAndExit("No instruction is expected after label name",instructionLine);
        }
        else if(!isValidLabel(tempLabel)){
            reportAndExit("Wrong format of label",instructionLine);
        }
        else{
            hasOccurred[tempLabel]=true;
        }  
    }
}
void getLabel(vector<string>trimmedInstruction[]){
    int dataStart=getDataIndex();
    int textStart=getTextIndex();
    getDataLabel(trimmedInstruction,dataStart,textStart);
    getTextLabel(trimmedInstruction,dataStart,textStart);
}
#endif