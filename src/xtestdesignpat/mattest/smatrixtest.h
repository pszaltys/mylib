#ifndef __SMATRIX_TEST_H__
#define __SMATRIX_TEST_H__

#include "testmaster.h"
#include "key.h"

class SMatrixTest : public UnitTest::Test
{
	template<typename T, int N>
	void Init2dTest();
public:
	void Run();
};

 #endif //__SMATRIX_TEST_H__
