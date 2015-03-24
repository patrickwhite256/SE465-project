#include "function.h"
using namespace std;

unordered_map<string, Function> Function::functions;

Function::Function(string name){
    this->name = name;
}

void Function::addSupport(string other){
    support[other] += 1;
}

void Function::addCalls(string other){
    //TODO: shit
}

int Function::getSupport(string other){
    return support[other];
}

Function *Function::getFunction(string functionName){
    bool exists = functions.count(functionName) == 1;
    if(!exists){
        Function newFunction(functionName);
        functions[functionName] = newFunction;
    }
    return &functions[functionName];
}
