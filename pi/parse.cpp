#include "parse.h"

#include <boost/regex.hpp>

using namespace boost;

regex nodeRegex("^Ca[^']+'([^']+)'");
regex callRegex("^\\s+CS[^']+'([^']+)'");

LineData::LineData(const std::string &line){
    smatch matches;
    regex_search(line, matches, nodeRegex);
    if(matches[0].matched){
        this->type = NODE;
        this->functionName = matches[1];
        return;
    }

    regex_match(line, matches, callRegex);
    if(matches[0].matched){
        this->type = CALL;
        this->functionName = matches[1];
        return;
    }
    this->type = NODE_NULL;
}

LineType LineData::getLineType(){return this->type;}
std::string LineData::getFunctionName(){return this->functionName;}
