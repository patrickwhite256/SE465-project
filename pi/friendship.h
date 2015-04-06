#ifndef FRIENDSHIP_H_
#define FRIENDSHIP_H_

#include <string>

struct Friendship {
    std::string friendName;
    int support;
    float confidence;
    Friendship(std::string friendName, int support, float confidence);
};

#endif
