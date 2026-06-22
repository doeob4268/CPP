#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <random>

#define SAFE_DELETE(p) do { delete(p); p = nullptr; } while (0)
#define SAFE_DELETE_ARRAY(p) do { delete[](p); p = nullptr; } while (0)

using namespace std;