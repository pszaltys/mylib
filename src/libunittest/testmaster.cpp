#include "testmaster.h"
#include <iostream>
#include <cassert>
#include <cstddef>

using namespace std;


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
namespace UnitTest {
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

void TestMaster::AddTest(Test* t) /*throw(UnitTestError) */
{
	if (t == 0)
	{
		throw UnitTestError("Null test in TestMaster::addTest");
	}	
	else if (mpostr && !t->cStream())
	{
		t->rStream() = mpostr;
	}
	mcoltests.push_back(t);
	t->reset();
}

void TestMaster::AddTestMaster(const TestMaster& s)
{
	for (size_t i = 0; i < s.mcoltests.size(); ++i) {
		assert(mcoltests[i]);
		AddTest(s.mcoltests[i]);
	}
}

void TestMaster::Free()
{
	for (size_t i = 0; i < mcoltests.size(); ++i) {
		delete mcoltests[i];
		mcoltests[i] = 0;
	}
}

void TestMaster::Run()
{
	Reset();
	for (size_t i = 0; i < mcoltests.size(); ++i) {
		assert(mcoltests[i]);
		mcoltests[i]->Run();
	}
}

long TestMaster::Report() const
{
	if (mpostr) {
		long totFail = 0;
		*mpostr << "TestMaster \"" << mname
			<< "\"\n=======";
		size_t i;
		for (i = 0; i < mname.size(); ++i)
			*mpostr << '=';
		*mpostr << "=" << endl;
		for (i = 0; i < mcoltests.size(); ++i) {
			assert(mcoltests[i]);
			totFail += mcoltests[i]->Report();
		}
		*mpostr << "=======";
		for (i = 0; i < mname.size(); ++i)
			*mpostr << '=';
		*mpostr << "=" << endl;
		return totFail;
	}
	else
		return cNumFailed();
}

long int TestMaster::cNumPassed() const
{
	long totPass = 0;
	for (size_t i = 0; i < mcoltests.size(); ++i) {
		assert(mcoltests[i]);
		totPass += mcoltests[i]->cNumPassed();
	}
	return totPass;
}

long int TestMaster::cNumFailed() const
{
	long totFail = 0;
	for (size_t i = 0; i < mcoltests.size(); ++i) {
		assert(mcoltests[i]);
		totFail += mcoltests[i]->cNumFailed();
	}
	return totFail;
}

void TestMaster::Reset()
{
	for (size_t i = 0; i < mcoltests.size(); ++i) {
		assert(mcoltests[i]);
		mcoltests[i]->reset();
	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
} // namespace UnitTest
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//