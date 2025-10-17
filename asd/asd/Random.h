#pragma once
#include "Basic.h"

class Random {
private:
    random_device rd; 
    mt19937 gen;      

public:
    Random(int min = 1, int max = 100) : gen(rd()) {}

    int Rand(int min = 1, int max = 100)
    {
        uniform_int_distribution<> distr(min, max);
        return distr(gen);
   }
    
    int MaxRand(int value1, int value2)
    {
        return Rand(value1, value2); 
    }

};