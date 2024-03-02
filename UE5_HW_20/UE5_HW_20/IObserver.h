#pragma once
#include <iostream>

using namespace std;

class IObserver {
public:
    virtual ~IObserver() {};

    virtual void Update() = 0;
};