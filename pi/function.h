#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <unordered_map>

class Function {
    std::unordered_map<std::string, int> support;
    std::string name;
    //TODO: calls
    public:
    Function() {}
    Function(std::string);
    void addSupport(std::string);
    void addCalls(std::string);
    int getSupport(std::string);
    //TODO: get calls
};

Function getFunction(std::string);

#endif //FUNCTION_H_
