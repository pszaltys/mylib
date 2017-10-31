#include "assocvectortest/assocvecttest.h"
#include "factorytest/factorytest.h"
#include "functortest/functortest.h"
#include "singletontest/singletontest.h"
#include "visitortest/visitortest.h"

#include "commontest/keytest.h"

#include "testmaster.h"

using namespace std;

int main()
{
	try
	{
		UnitTest::TestMaster despatttests("Design Patterns unit tests");
		despatttests.AddTest(new FactoryTest);
		despatttests.AddTest(new FunctorTest);
		despatttests.AddTest(new SingletonTest);
		despatttests.AddTest(new VisitorTest);
		despatttests.AddTest(new AssocVectTest);

		UnitTest::TestMaster commontests("Common lib unit tests");
		commontests.AddTest(new KeyTest);

		UnitTest::TestMaster runtest("Run test master");
		runtest.AddTestMaster(despatttests);
		runtest.AddTestMaster(commontests);
		runtest.Run();
		runtest.Report();
		runtest.Free();
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