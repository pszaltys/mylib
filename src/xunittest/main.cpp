#include "testmaster.h"

using namespace std;

class TestTest : public UnitTest::Test
{
	void Test1()
	{
		test_(1 < 2);
		test_(sizeof(int) < sizeof(double));
		test_(false);
		test_(1 > 2);
	}

public:
	void Run()
	{
		Test1();
	}
};

class TestTest2 : public UnitTest::Test
{
	void Test1()
	{
		test_(1 < 2);
		test_(sizeof(int) < sizeof(double));
		test_(false);
		test_(1 > 2);
	}

public:
	void Run()
	{
		Test1();
	}
};

int main()
{
	try
	{
		UnitTest::TestMaster master("UnitTest Master");
		master.AddTest(new TestTest);
		master.AddTest(new TestTest2);
		//master.AddTest(NULL);
		master.Run();
		master.Report();
		master.Free();

	}
	catch (UnitTest::UnitTestError& err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}


	return 0;
}