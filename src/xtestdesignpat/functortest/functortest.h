#ifndef __FUNCTOR_TEST_H__
#define __FUNCTOR_TEST_H__

#include "testmaster.h"

class FunctorTest : public UnitTest::Test
{
	void TestFunctions();
	void TestObjFunction();
	void TestMemFunction();
public:
	void Run();
};

 #endif //__FUNCTOR_TEST_H__
