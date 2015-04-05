#include "function.h"

#include <unordered_set>
#include <boost/format.hpp>
#include <iostream>

using namespace std;

unordered_map<string, Function> Function::functions;

Function::Function(string name){
    this->name = name;
}

string Function::getName(){
    return name;
}
void Function::addSupport(string other){
    support[other] += 1;
}

void Function::addCalls(string other){
    calls[other] += 1;
}

int Function::getSupport(string other){
    return support[other];
}

int Function::getCalls(string func){
    return calls[func];
}

unordered_map<string, int> *Function::getSupportMap(){
    return &support;
}

unordered_map<std::string, Function> *Function::getFunctions(){
    return &functions;
}

void Function::findBugs(){
    unordered_map<string, string> aboveThreshold;
    Function *func, *inner_func;
    for(auto it = functions.begin(); it != functions.end(); ++it ){
        func = &(it->second);
        for(auto inner_it = it; inner_it != functions.end(); ++inner_it){
            inner_func = &(inner_it->second);
            float threshold = ((float)(inner_func->getSupport(it->first)) / (float)(inner_func->getSupport(inner_it->first)));
            if (inner_it != it && threshold > 0.50 && threshold != 1){
                //cout << threshold << " " << it->first << " " << inner_it->first << endl;
                string fname1 = it->first, fname2 = inner_it->first;
                aboveThreshold[fname1] = fname2;
            }
        }
    }
    for(auto it = functions.begin(); it != functions.end(); ++it){
        func = &(it->second);
        for(auto inner_it = aboveThreshold.begin(); inner_it != aboveThreshold.end(); ++inner_it){
            if((func->getCalls(inner_it->first) && func->getCalls(inner_it->second) < 1 )){
                inner_func = Function::getFunction(inner_it->first);
                float threshold = (float)((float)(inner_func->getSupport(inner_it->second)) / (float)(inner_func->getSupport(inner_it->first))) * 100;
                cout << boost::format("bug: %s in %s, pair: (%s, %s), support: %d, confidence: %.2f%%") % inner_it->first % it->first % inner_it->first % inner_it->second % inner_func->getSupport(inner_it->second) % threshold << endl;
            } else if (func->getCalls(inner_it->first) < 1 && func->getCalls(inner_it->second)){
                inner_func = Function::getFunction(inner_it->second);
                float threshold = (float)((float)(inner_func->getSupport(inner_it->first)) / (float)(inner_func->getSupport(inner_it->second))) * 100;
                cout << boost::format("bug: %s in %s, pair: (%s, %s), support: %d, confidence: %.2f%%") % inner_it->second % it->first % inner_it->second % inner_it->first % inner_func->getSupport(inner_it->second) % threshold << endl;
            }
        }
    }
}

Function *Function::getFunction(string functionName){
    bool exists = functions.count(functionName) == 1;
    if(!exists){
        Function newFunction(functionName);
        functions[functionName] = newFunction;
    }
    return &functions[functionName];
}
