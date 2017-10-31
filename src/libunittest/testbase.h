
#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
#include <cassert>

using std::string;
using std::ostream;
using std::cout;

#define test_(cond) \
  DoTest(cond, #cond, __FILE__, __LINE__)
#define fail_(str) \
  DoFail(str, __FILE__, __LINE__)

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
namespace UnitTest {
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

	//////////////////////////////////////////////////////////////////////
	// class Test
	//////////////////////////////////////////////////////////////////////

	class Test
	{
		Test(const Test&);
		Test& operator=(const Test&);
	protected:
		void DoTest(bool cond, const string& lbl, const char* fname, long lineno);
		void DoFail(const string& lbl, const char* fname, long lineno);

	public:
		Test(ostream* osptr = &cout)
		{
			this->mpostr = osptr;
			mnpass = mnfail = 0;
		}

		virtual ~Test() {}
		virtual void Run() = 0;

		const long int&		cNumPassed() const		{ return mnpass; }
		const long int&		cNumFailed() const		{ return mnfail; }
		ostream* const&		cStream() const			{ return mpostr; }
		ostream*&			rStream()				{ return mpostr; }

		void				Succeed_()				{ ++mnpass; }
		const long int&		Report() const;
		virtual void		reset()					{ mnpass = mnfail = 0; }

	private:
		ostream* mpostr;
		long int mnpass;
		long int mnfail;
	};

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
} // namespace UnitTest
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

#endif //TEST_H 
