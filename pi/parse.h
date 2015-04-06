#include <string>

#ifndef PARSE_H_
#define PARSE_H_

enum LineType {NODE_NULL, EXTERNAL_CALL, NODE, CALL};

class LineData {
    LineType type;
    std::string functionName;

    public:
    LineData(const std::string &);
    LineType getLineType();
    std::string getFunctionName();
    private:
    LineData();
    LineData(const LineData &);
    LineData& operator=(const LineData &);
};

#endif
