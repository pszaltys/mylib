#ifndef __SINGLETON_TEST_H__
#define __SINGLETON_TEST_H__

#include "testmaster.h"

class SingletonTest : public UnitTest::Test
{
	void TestAccess();
	void TestAftAccess();
public:
	void Run();
};

 #endif //__SINGLETON_TEST_H__
