#pragma once
#include "Basic.h"

enum class BallType
{
    Normal,
    Master
};

struct Ball
{
    string name;
    BallType type;
    float catchRate;
};