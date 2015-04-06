#include "friendship.h"

Friendship::Friendship(std::string friendName, int support, float confidence){
    this->friendName = friendName;
    this->support = support;
    this->confidence = confidence;
}
