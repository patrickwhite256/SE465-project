#include "function.h"
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

int Function::getSupport(){
	int supportTotal = 0;
	for(auto it = support.begin(); it != support.end(); ++it){
		supportTotal += it->second;
	}
	return supportTotal;
}

int Function::getCalls(string func){
	return calls[func];
}

unordered_map<string, int> Function::getSupportMap(){
	return support;
}

void Function::findBugs(){
	for(auto iterator = calls.begin(); iterator != calls.end(); ++iterator){
		Function *functionCalled = Function::getFunction(iterator->first);
		unordered_map<string, int> functionSupport = functionCalled->getSupportMap();
		for (auto supportIterator = functionSupport.begin(); supportIterator != functionSupport.end(); ++supportIterator){
			if(calls.find(supportIterator->first) == calls.end()){
				float supportValue = (float)(functionCalled->getSupport(supportIterator->first)) / (float)(functionCalled->getSupport());
				if (supportValue >= 0.25){
					cout << boost::format("bug: %s in %s, pair: (%s, %s), support: %d, confidence: %.2f%%") % functionCalled->getName() % name % iterator->first % supportIterator->first % functionCalled->getSupport(supportIterator->first) % supportValue << endl;
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
