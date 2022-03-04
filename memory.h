#ifndef MEMORY_H
#define MEMORY_H
#include"debugger.h"
#include"format.h"
void getDataLabel(vector<string>trimmedInstruction[],int numberOfInstruction,int dataStart, int textStart){
    int dataEnd=0;
    string instructionLine="";
    map<string,bool>hasOccurred;
    if(dataStart>textStart)dataEnd=numberOfInstruction;
    else{
        if(dataStart+1==textStart)return;
        else dataEnd=textStart;
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
            reportAndExit("Unknown operation in data section",instructionLine);
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
        else if(isValidLabel(tempLabel)){
                hasOccurred[tempLabel]=true;
        }
        else{
            reportAndExit("Wrong format of label",instructionLine);
        }  
    }
}
void getTextLabel(vector<string>trimmedInstruction[],int numberOfInstruction,int dataStart, int textStart){
    // int textEnd=0;
    // int start=0,end=0;
    // bool operationFound=false;
    // string instructionLine="";
    // map<string,bool>hasOccurred;
    // if(dataStart<textStart)textEnd=numberOfInstruction;
    // else{
    //     if(dataStart==textStart+1)return;
    //     else textEnd=dataStart;
    // }
    // for(int i=start;i<end;i++){
    //     instructionLine=to_string(i);
    //     if(trimmedInstruction[i][0]=="")continue;
    //     else{
    //         int labelFound=-1,j;
    //         int size=trimmedInstruction[i].size();
    //         bool labelFlag=false;
    //         for(j=0;j<size;j++){
    //             int tokenLength=trimmedInstruction[i][j].length();
    //             labelFound=trimmedInstruction[i][j].find(':');
    //             if(labelFound>-1&&labelFound<tokenLength){
    //                 labelFlag=true;
    //                 break;
    //             }
    //         }
    //         if(labelFlag){
    //             if(j==0){
    //                 string tempLabel=trimmedInstruction[i][0].substr(0,labelFound);
    //                 if(labelFound==0)reportAndExit("Label name expected before ':'",instructionLine);
    //                 else if(hasOccurred[tempLabel])reportAndExit("Label "+tempLabel+" was defined before",instructionLine);
    //                 else{
    //                     if(isValidLabel(tempLabel)){
    //                         hasOccurred[tempLabel]=true;
    //                     }
    //                     else reportAndExit("Wrong format of label",instructionLine);
    //                 }
    //             }
    //             else if(j==1){
    //                 string tempLabel=trimmedInstruction[i][0];
    //                 if(labelFound!=0)reportAndExit("Wrong format of label",instructionLine);
    //                 else if(hasOccurred[tempLabel])reportAndExit("Label "+tempLabel+" was defined before",instructionLine);
    //                 else{
    //                     if(isValidLabel(tempLabel)){
    //                         hasOccurred[tempLabel]=true;
    //                     }
    //                     else reportAndExit("Wrong format of label",instructionLine);
    //                 }
    //             }
    //             else reportAndExit("Wrong format of label",instructionLine);
    //         }
    //         else operationFound=true;
    //     }
    // }
}
void getLabel(vector<string>trimmedInstruction[],int numberOfInstruction,int dataStart, int textStart){
    getDataLabel(trimmedInstruction,numberOfInstruction,dataStart,textStart);
    getTextLabel(trimmedInstruction,numberOfInstruction,dataStart,textStart);
}
#endif