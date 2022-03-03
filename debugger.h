#ifndef DEBUGGER_H
#define DEBUGGER_H
void reportAndExit(string errorMessage,string instructionLine){
    cout<<"Error: "<<errorMessage<<" at line "<<instructionLine<<endl;
    exit(1);
}
void reportAndExit(string errorMessage){
    cout<<"Error: "<<errorMessage<<endl;
    exit(1);
}
#endif