
#include "testbase.h"

#include <iostream>
#include <typeinfo>

using namespace std;


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
namespace UnitTest {
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

void Test::DoTest(bool cond, const std::string& lbl, const char* fname, long lineno)
{
	if (!cond)
		DoFail(lbl, fname, lineno);
	else
		Succeed_();
}

void Test::DoFail(const std::string& lbl, const char* fname, long lineno)
{
	++mnfail;
	if (mpostr) {
		*mpostr << typeid(*this).name()
			<< " failure: (" << lbl << ") , " << fname
			<< " (line " << lineno << ")" << endl;
	}
}

const long int& Test::Report() const 
{
	if (mpostr) {
		*mpostr << "Test \"" << typeid(*this).name()
			<< "\":\n\tPassed: " << mnpass
			<< "\tFailed: " << mnfail
			<< endl;
	}
	return mnfail;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
} // namespace UnitTest
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
