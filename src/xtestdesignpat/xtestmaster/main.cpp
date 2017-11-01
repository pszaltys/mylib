#include "assocvectortest/assocvecttest.h"
#include "factorytest/factorytest.h"
#include "functortest/functortest.h"
#include "singletontest/singletontest.h"
#include "visitortest/visitortest.h"

#include "commontest/keytest.h"
#include "mattest/smatrixtest.h"

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
		despatttests.Run();
		despatttests.Report();
		despatttests.Free();

		UnitTest::TestMaster commontests("Common lib unit tests");
		commontests.AddTest(new KeyTest);
		commontests.Run();
		commontests.Report();
		commontests.Free();

		UnitTest::TestMaster mattests("Mat lib unit tests");
		mattests.AddTest(new SMatrixTest);
		mattests.Run();
		mattests.Report();
		mattests.Free();

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