#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <unordered_map>
#include <string>

class Function {
    static std::unordered_map<std::string, Function> functions;
    std::unordered_map<std::string, int> support;
		std::unordered_map<std::string, int> calls;
		std::string name;
    //TODO: calls
    public:
    Function() {}
    Function(std::string);
		std::string getName();
		void findBugs();
		void addSupport(std::string);
    void addCalls(std::string);
    int getSupport(std::string);
		std::unordered_map<std::string, Function> *getFunctions();
		std::unordered_map<std::string, int> *getSupportMap();
    int getCalls(std::string);
    static Function *getFunction(std::string);
};

#endif //FUNCTION_H_
