#ifndef __FACTORY_TEST_H__
#define __FACTORY_TEST_H__
	
#include "testmaster.h"

class FactoryTest : public UnitTest::Test
{

	void CreatorByFunction();
	void CreatorByClass();

	template<class FACTORY>
	void MakeTest(FACTORY& fct);

public:
	void Run()
	{
		CreatorByFunction();
		CreatorByClass();
	}
};
#endif //__FACTORY_TEST_H__
