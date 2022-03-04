#ifndef FORMAT_H
#define FORMAT_H
bool isValidOperation(string token){
    vector<string>tempOperations=getOperations();
    for(int i=0;i<tempOperations.size();i++){
        if(tempOperations[i]==token){
            return true;
        }
    }
    return false;
}
bool isValidLabel(string token){
    if(isValidOperation(token))return false;
    for(int i=0;i<token.length();i++){
        if(i==0){
            if(token[0]<65||(token[0]>90&&token[0]<97)||token[0]>121){
                return false;
            }
        }
        else{
            if(token[i]<65||(token[i]>90&&token[i]<97&&token[i]!='_')||token[i]>121){
                return false;
            }
        }
    }
    return true;
}
#endif