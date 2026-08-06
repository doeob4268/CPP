#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <random>
#include <cassert>
#include <vector>

#define SAFE_DELETE(p) do { delete(p); p = nullptr; } while (0)
#define SAFE_DELETE_ARRAY(p) do { delete[](p); p = nullptr; } while (0)

#define DECLARE_SINGLETON(CLASS_NAME)					\
private:												\
	CLASS_NAME() = default;								\
	~CLASS_NAME() = default;							\
	CLASS_NAME(const CLASS_NAME&) = delete;				\
	CLASS_NAME& operator=(const CLASS_NAME&) = delete;	\
	CLASS_NAME(CLASS_NAME&&) = delete;					\
	CLASS_NAME& operator=(CLASS_NAME&&) = delete;		\
public:													\
	static CLASS_NAME& GET()							\
{														\
	static CLASS_NAME instance;							\
	return instance;									\
}

using namespace std;