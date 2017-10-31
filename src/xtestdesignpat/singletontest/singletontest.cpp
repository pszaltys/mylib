#include "singletontest.h"
#include "singleton.h"
#include <vector>

struct A
{
	int mdata;
};

void SingletonTest::TestAccess()
{
	Singleton<A>::GetInstance()->mdata = 11;
	test_(Singleton<A>::GetInstance()->mdata == 11);
}

void SingletonTest::TestAftAccess()
{
	test_(Singleton<A>::GetInstance()->mdata == 11);
}

void SingletonTest::Run()
{
	TestAccess();
	TestAftAccess();
}