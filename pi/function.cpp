#include "function.h"
using namespace std;

unordered_map<std::string, Function> functions;

Function::Function(std::string name){
    this->name = name;
}

void Function::addSupport(std::string other){
    unordered_map<std::string, int>::iterator it = support.find(other);
    if(it == support.end()){
        support[other] = 1;
    } else {
        it->second += 1;
    }
    it = support.find(name);
    if(it == support.end()){
        support[other] = 1;
    } else {
        it->second += 1;
    }
}

void Function::addCalls(std::string other){
    //TODO: shit
}

int Function::getSupport(std::string other){
    return support[other];
}

Function getFunction(std::string functionName){
    unordered_map<std::string, Function>::iterator it = functions.find(functionName);
    if(it == functions.end()){
        Function newFunction(functionName);
        functions[functionName] = newFunction;
    }
    return functions[functionName];
}
