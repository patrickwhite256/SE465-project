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
    for(auto it = functions.begin(); it != functions.end(); ++it ){
        func = &(it->second);
        for(auto inner_it = it; inner_it != functions.end(); ++inner_it){
            if(it == inner_it) continue;
            inner_func = &(inner_it->second);
            int supportPair = inner_func->getSupport(func->getName());
            if(supportPair < t_support) continue;

            float confidence = supportPair / (float)(func->getSupport(func->getName()));
            if(confidence >= t_confidence) {
                func->friendships.push_back(Friendship(inner_func->getName(), supportPair, confidence));
            }

            confidence = supportPair / (float)(inner_func->getSupport(inner_func->getName()));
            if(confidence >= t_confidence) {
                inner_func->friendships.push_back(Friendship(func->getName(), supportPair, confidence));
            }
        }
    }
    for(auto it = functions.begin(); it != functions.end(); ++it){
        func = &(it->second);
        for(auto inner_it = func->calls.begin(); inner_it != func->calls.end(); ++inner_it){
            Function *iFunc = getFunction(*inner_it);
            //for each called function, check if its friends are called
            for(auto friend_it = iFunc->friendships.begin(); friend_it != iFunc->friendships.end(); ++friend_it){
                string friendName = friend_it->friendName;
                if(!func->doesCall(friendName)){
                    string firstName = *inner_it;
                    string secondName = friendName;

                    if(iFunc->getName() > friendName){
                        firstName = friendName;
                        secondName = *inner_it;
                    }

                    cout << boost::format("bug: %s in %s, pair: (%s, %s), support: %d, confidence: %.2f%%")
                        % iFunc->getName() % func->getName() % firstName % secondName
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
