#ifndef TESTMASTER_H
#define TESTMASTER_H
#include <vector>
#include <stdexcept>
#include "testbase.h"

using std::vector;
using std::logic_error;

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
namespace UnitTest {
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

	//////////////////////////////////////////////////////////////////////
	// class UnitTestError
	//////////////////////////////////////////////////////////////////////

	class UnitTestError : public logic_error
	{
	public:
		UnitTestError(const string& s = "")
			: logic_error(s) {}
	};

	//////////////////////////////////////////////////////////////////////
	// class TestMaster
	//////////////////////////////////////////////////////////////////////

	class TestMaster
	{
	public:
		TestMaster(const string& name, ostream* osptr = &cout)
			: mname(name)
		{
			this->mpostr = osptr;
		}
		const string&		cName() const		{ return mname; }
		ostream* const&		cStream() const		{ return mpostr; }
		ostream*&			rStream()			{ return mpostr; }

		long int			cNumPassed() const;
		long int			cNumFailed() const;

		void AddTest(Test* t) /*throw(UnitTestError)*/;
		void AddTestMaster(const TestMaster&);
		void Run();
		long Report() const;
		void Free();

	private:
		void Reset();

		TestMaster(const TestMaster&);
		TestMaster& operator=(const TestMaster&);

		string			mname;
		ostream*		mpostr;
		vector<Test*>	mcoltests;
	};

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
} // namespace UnitTest
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

#endif //TESTMASTER_H