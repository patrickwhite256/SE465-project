#include <iostream>
#include <unordered_set>
#include <string>

#include "parse.h"
#include "function.h"

using namespace std;

void create_support(unordered_set<string> *function_set){
    for(auto it = function_set->begin(); it != function_set->end(); ++it){
        Function *outer_fn = Function::getFunction(*it);
        for(auto inner_it = it; inner_it != function_set->end(); ++inner_it){
            Function *inner_fn = Function::getFunction(*inner_it);
            outer_fn->addSupport(*inner_it);
            if(inner_it != it) inner_fn->addSupport(*it);
        }
    }
    function_set->clear();
}

int main(int argc, char **argv){
    string line;
    Function *current_function;
    unordered_set<string> function_set;
    while(!cin.eof()){
        getline(cin, line);
        if(line.length() > 0){
            LineData *ld = new LineData(line);
            switch(ld->getLineType()) {
                case NODE:
                    create_support(&function_set);
                    current_function = Function::getFunction(ld->getFunctionName());
                    cout << "Function " << ld->getFunctionName() << endl;
                    break;
                case CALL:
                    if(current_function != NULL){
                        function_set.insert(ld->getFunctionName());
                        current_function->addCalls(ld->getFunctionName());
                        cout << " calls " << ld->getFunctionName() << endl;
                    }
                    break;
                case NODE_NULL:
                    current_function = NULL;
                    break;
            }
        }
    }
    create_support(&function_set);
    current_function->findBugs();
}
