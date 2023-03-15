//written by Zeynep Su Uçan
//22103044 - Section 3

#ifndef __SUBSCRIBER_NODE_H
#define __SUBSCRIBER_NODE_H
#include <string>
#include <iostream>
#include "Subscriber.h"
using namespace std;

class SubscriberNode {
    public:
    SubscriberNode(){}

    Subscriber subscriber;
    SubscriberNode* nextSubscriberNode = nullptr;
};
#endif
