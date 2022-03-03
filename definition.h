#ifndef DEFINITION_H
#define DEFINITION_H
vector<string>operations;
vector<string>registers;
void defineOperations(vector<string>tempOperations){
    for(int i=0;i<tempOperations.size();i++){
        operations.push_back(tempOperations[i]);
    }
}
vector<string>getOperations(){
    return operations;
}
void defineRegisters(vector<string>tempRegister){
    for(int i=0;i<tempRegister.size();i++){
        operations.push_back(tempRegister[i]);
    }
}
vector<string>getRegisters(){
    return registers;
}
#endif