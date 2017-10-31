#include "factorytest.h"

#include "ConcProd.h"
#include "Factory.h"
#include "Functor.h"

template<typename T>
struct CreateProdClass
{
	CreateProdClass()	{}

	TestProductBase* operator()()
	{
		return new T;
	}
};

struct CreateProdClass1
{
	TestProductBase* operator()()
	{
		return new ConcProduct1;
	}
};


TestProductBase* CreateP1()
{
	return new ConcProduct1;
}
TestProductBase* CreateP2()
{
	return new ConcProduct2;
}


void FactoryTest::CreatorByFunction()
{
	Factory<TestProductBase>	factory;
	test_(factory.Register("Prod1", CreateP1));
	test_(factory.Register("Prod2", CreateP2));

	MakeTest(factory);
}

void FactoryTest::CreatorByClass()
{
	Factory<TestProductBase, Functor<TestProductBase*> >	factory;

	typedef CreateProdClass<ConcProduct1> Creator1;
	typedef CreateProdClass<ConcProduct2> Creator2;

	test_(factory.Register("Prod1", Creator1() ) );
	test_(factory.Register("Prod2", Creator2() ) );

	MakeTest(factory);

	Factory<TestProductBase, Functor<TestProductBase*> >	factory2;

	CreateProdClass1 cr1;
	Creator2 cr2;

	Functor<TestProductBase*> func1(cr1);
	Functor<TestProductBase*> func2(cr2);

	test_(factory2.Register("Prod1", func1));
	test_(factory2.Register("Prod2", func2));

	MakeTest(factory2);
}

template<class FACTORY>
void FactoryTest::MakeTest(FACTORY& factory)
{
	TestProductBase* prod1[2] = { NULL, NULL };
	TestProductBase* prod2[2] = { NULL, NULL };
	prod1[0] = factory.CreateObj("Prod1");
	prod1[1] = factory.CreateObj("Prod1");

	test_(prod1[0] != NULL);
	test_(prod1[1] != NULL);

	test_(prod1[0]->GetVar() == 1);
	test_(prod1[1]->GetVar() == 1);

	prod2[0] = factory.CreateObj("Prod2");
	prod2[1] = factory.CreateObj("Prod2");

	test_(prod2[0] != NULL);
	test_(prod2[1] != NULL);

	test_(prod2[0]->GetVar() == 2);
	test_(prod2[1]->GetVar() == 2);

	TestProductBase* failprod = NULL;
	failprod = factory.CreateObj("SomeUnregisterStr");
	test_(failprod == NULL);

	test_(factory.Unregister("Prod1"));
	test_(factory.Unregister("Prod1") == false);
	test_(factory.Unregister("SomeUnregisterStr") == false);

	failprod = NULL;
	failprod = factory.CreateObj("Prod1");
	test_(failprod == NULL);
}
