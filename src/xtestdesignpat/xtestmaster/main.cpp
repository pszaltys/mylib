#include "factorytest/factorytest.h"
#include "functortest/functortest.h"
#include "singletontest/singletontest.h"
#include "visitortest/visitortest.h"
#include "testmaster.h"

using namespace std;

int main()
{
	try
	{
		UnitTest::TestMaster testmaster("Design Patterns unit tests");
		testmaster.AddTest(new FactoryTest);
		testmaster.AddTest(new FunctorTest);
		testmaster.AddTest(new SingletonTest);
		testmaster.AddTest(new VisitorTest);

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