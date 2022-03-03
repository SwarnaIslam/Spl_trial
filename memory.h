#ifndef MEMORY_H
#define MEMORY_H
#include"debugger.h"
#include"format.h"
void getSectionLabel(int start, int end,bool &operationFound,map<string,bool>hasOccurred,vector<string>trimmedInstruction[]){
    string instructionLine="";
    for(int i=start;i<end;i++){
        instructionLine=to_string(i);
        if(trimmedInstruction[i][0]=="")continue;
        else{
            int labelFound=-1,j;
            int size=trimmedInstruction[i].size();
            bool labelFlag=false;
            for(j=0;j<size;j++){
                int tokenLength=trimmedInstruction[i][j].length();
                labelFound=trimmedInstruction[i][j].find(':');
                if(labelFound>-1&&labelFound<tokenLength){
                    labelFlag=true;
                    break;
                }
            }
            if(labelFlag){
                if(j==0){
                    string tempLabel=trimmedInstruction[i][0].substr(0,labelFound);
                    if(labelFound==0)reportAndExit("Label name expected before ':'",instructionLine);
                    else if(hasOccurred[tempLabel])reportAndExit("Label "+tempLabel+" was defined before",instructionLine);
                    else{
                        if(isValidLabel(tempLabel)){
                            hasOccurred[tempLabel]=true;
                        }
                        else reportAndExit("Wrong format of label",instructionLine);
                    }
                }
                else if(j==1){
                    string tempLabel=trimmedInstruction[i][0];
                    if(labelFound!=0)reportAndExit("Wrong format of label",instructionLine);
                    else if(hasOccurred[tempLabel])reportAndExit("Label "+tempLabel+" was defined before",instructionLine);
                    else{
                        if(isValidLabel(tempLabel)){
                            hasOccurred[tempLabel]=true;
                        }
                        else reportAndExit("Wrong format of label",instructionLine);
                    }
                }
                else reportAndExit("Wrong format of label",instructionLine);
            }
            else operationFound=true;
        }
    }
}
void getDataLabel(vector<string>trimmedInstruction[],int numberOfInstruction,int dataStart, int textStart){
    int dataEnd=0;
    bool operationFound=false;
    map<string,bool>hasOccurred;
    if(dataStart>textStart)dataEnd=numberOfInstruction;
    else{
        if(dataStart+1==textStart)return;
        else dataEnd=textStart;
    }
    getSectionLabel(dataStart+1,dataEnd,operationFound,hasOccurred,trimmedInstruction);
    if(operationFound)reportAndExit("Unknown operation");
}
void getTextLabel(vector<string>trimmedInstruction[],int numberOfInstruction,int dataStart, int textStart){
    int textEnd=0;
    bool operationFound=false;
    map<string,bool>hasOccurred;
    if(dataStart<textStart)textEnd=numberOfInstruction;
    else{
        if(dataStart==textStart+1)return;
        else textEnd=dataStart;
    }
    getSectionLabel(textStart+1,textEnd,operationFound,hasOccurred,trimmedInstruction);
}
void getLabel(vector<string>trimmedInstruction[],int numberOfInstruction,int dataStart, int textStart){
    getDataLabel(trimmedInstruction,numberOfInstruction,dataStart,textStart);
    getTextLabel(trimmedInstruction,numberOfInstruction,dataStart,textStart);
}
#endif