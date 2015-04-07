#include "friendship.h"

//Friendship represents a pair of functions with a confidence level above the threshold
Friendship::Friendship(std::string friendName, int support, float confidence){
    this->friendName = friendName;
    this->support = support;
    this->confidence = confidence;
}
