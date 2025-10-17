#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <random>
#include <thread>
#include <memory>
#include <utility>
#include <limits>
#include <map>
#include <unordered_map>

void ClearBuffer()
{
    fflush(stdin);
    while (_kbhit()) _getch();
}
using namespace std;
