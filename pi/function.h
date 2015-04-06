#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <unordered_map>
#include <list>
#include <string>
#include "friendship.h"

class Function {
    static std::unordered_map<std::string, Function> functions;
    std::unordered_map<std::string, int> support;
   	std::unordered_set<std::string> calls;
    std::list<Friendship> friendships;
   	std::string name;
    public:
    Function() {}
    Function(std::string);
   	std::string getName();
    void addSupport(std::string);
    void addCalls(std::string);
    int getSupport(std::string);
    bool doesCall(std::string);
    std::unordered_map<std::string, int> *getSupportMap();
    static std::unordered_map<std::string, Function> *getFunctions();
    static Function *getFunction(std::string);
    static void findBugs(int, float);
};

#endif //FUNCTION_H_
