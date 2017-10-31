#include "assocvecttest.h"


using namespace std;

int main()
{
	try
	{
		UnitTest::TestMaster testmaster("AssocVector unit tests");
		testmaster.AddTest(new AssocVectTest);

		testmaster.Run();
		testmaster.Report();
		testmaster.Free();
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