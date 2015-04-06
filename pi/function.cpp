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
    calls.insert(other);
}

int Function::getSupport(string other){
    return support[other];
}

bool Function::doesCall(string func){
    return calls.find(func) != calls.end();
}

unordered_map<string, int> *Function::getSupportMap(){
    return &support;
}

unordered_map<std::string, Function> *Function::getFunctions(){
    return &functions;
}

void Function::findBugs(int t_support, float t_confidence){
    Function *func, *inner_func;
    string funcName, inner_funcName;
    for(auto it = functions.begin(); it != functions.end(); ++it ){
        func = &(it->second);
        funcName = it->first;
        int selfSupport = func->getSupport(funcName);
        for(auto inner_it = func->support.begin(); inner_it != func->support.end(); ++inner_it){
            inner_funcName = inner_it->first;
            if(funcName == inner_funcName) continue;
            int pairSupport = inner_it->second;
            if(pairSupport < t_support) continue;

            float confidence = (float)pairSupport / selfSupport;
            if(confidence >= t_confidence) {
                func->friendships.push_back(Friendship(inner_funcName, pairSupport, confidence));
            }
        }
    }

    for(auto it = functions.begin(); it != functions.end(); ++it){
        func = &(it->second);
        for(auto inner_it = func->calls.begin(); inner_it != func->calls.end(); ++inner_it){
            inner_func = getFunction(*inner_it);
            //for each called function, check if its friends are called
            for(auto friend_it = inner_func->friendships.begin(); friend_it != inner_func->friendships.end(); ++friend_it){
                string friendName = friend_it->friendName;
                if(!func->doesCall(friendName)){
                    string firstName = *inner_it;
                    string secondName = friendName;

                    if(*inner_it > friendName){
                        firstName = friendName;
                        secondName = *inner_it;
                    }

                    cout << boost::format("bug: %s in %s, pair: (%s, %s), support: %d, confidence: %.2f%%")
                        % inner_func->getName() % func->getName() % firstName % secondName
                        % friend_it->support % friend_it->confidence << endl;
                }
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
