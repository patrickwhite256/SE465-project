#include <iostream>
#include <unordered_set>
#include <string>

#include "parse.h"
#include "function.h"

using namespace std;

void create_support(unordered_set<Function *> *function_set){
    //for each function, create a bidirectional support link
    //to all subsequent functions
    for(auto fn = function_set->begin();
            fn != function_set->end();
            ++fn){
        for(auto inner_fn = fn;
                inner_fn != function_set->end();
                ++inner_fn){
            (*fn)->addSupport((*inner_fn)->getName());
            if(inner_fn != fn) (*inner_fn)->addSupport((*fn)->getName());
        }
    }
}

void create_support(unordered_set<string> *function_set){
    //convert to Functions *s and forward
    unordered_set<Function *> functions;
    for(auto it = function_set->begin();
            it != function_set->end();
            ++it){
        functions.insert(Function::getFunction(*it));
    }
    create_support(&functions);
    function_set->clear();
}

int main(int argc, char **argv){
    int t_support = 3;
    float t_confidence = 0.65;
    bool expand_nodes = false;
    if(argc >= 3) {
        t_support = atoi(argv[1]);
        t_confidence = (float)atoi(argv[2]) / 100;
    }
    if (argc == 4) {
        expand_nodes = true;
    }
    string line;
    Function *current_function;
    unordered_set<string> function_set;
    while(!cin.eof()){
        getline(cin, line);
        if(line.length() > 0){
            LineData *ld = new LineData(line);
            switch(ld->getLineType()) {
                case NODE:
                    if(!expand_nodes){
                        create_support(&function_set);
                    }
                    current_function = Function::getFunction(ld->getFunctionName());
                    break;
                case CALL:
                    if(current_function != NULL){
                        function_set.insert(ld->getFunctionName());
                        current_function->addCalls(ld->getFunctionName());
                    }
                    break;
                case EXTERNAL_CALL:
                    break;
                case NODE_NULL:
                    current_function = NULL;
                    break;
            }
        }
    }
    if(!expand_nodes){
        create_support(&function_set);
    } else {
        for(auto it = Function::getFunctions()->begin();
                it != Function::getFunctions()->end();
                ++it){
            it->second.createExpandedCalls();
            create_support(it->second.getExpandedCalls());
        }
    }
    Function::findBugs(t_support, t_confidence, expand_nodes);
}
