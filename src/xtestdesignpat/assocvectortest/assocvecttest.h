#ifndef ASSOCVECTOR_TEST_H
#define ASSOCVECTOR_TEST_H

#include <string>
#include <vector>
#include <list>

#include "assocvector.h"
#include "testmaster.h"


class AssocVectTest : public UnitTest::Test
{
	template<typename KEY, typename T>
	void DefaultConstructor()
	{
		AssocVect<KEY, T>* assocv = new AssocVect<KEY, T>();
		test_(assocv != NULL);
	}

	void DefaultConstructor()
	{
		DefaultConstructor<int, int>();
		DefaultConstructor<double, int>();
		DefaultConstructor<int, double>();
		DefaultConstructor<std::string, std::string>();
	}

	template<typename KEY, typename T, template<typename,typename> class STLVECT>
	void InstertionTest(const STLVECT< std::pair<KEY, T>, std::allocator<std::pair<KEY, T> > >& vect)
	{
		typedef STLVECT< std::pair<KEY, T>, std::allocator<std::pair<KEY, T> > >	VECT;
		AssocVect<KEY, T, VECT> avect;
		test_(avect.size() == 0);
		test_(avect.empty());
		avect.insertnonstrict(vect[0]);
		avect.insertnonstrict(vect[1]);
		test_(avect.size() == 2);

		AssocVect<KEY, T, VECT> avect2;
		avect2.insert(vect[0]);
		avect2.insert(vect[1]);
		test_(avect2.size() == 1);

		avect2.insert(vect[2]);
		test_(avect2.size() == 2);

		avect2.insert(vect[4]);
		test_(avect2[11] != avect2[33]);
		test_(avect2[11] == avect2[66]);

		avect2[12] = 9;
		test_(avect2.size() == 4);
		test_(avect2[12] == (T)9.);
		avect2[12] = 13;
		test_(avect2.size() == 4);
		test_(avect2[12] == (T)13.);

		test_(avect2.insert(vect[3]).second == true);
		test_(avect2.insert(vect[3]).second == false);
		test_(avect2.insert(vect[3]).first->first == (KEY)55.);
		test_(avect2.insert(vect[3]).second == false);
		test_(avect2.insert(vect[3]).first->second == (T)66.);
		test_(avect2.insert(vect[3]).second == false);
		test_(avect2.size() == 5);

		AssocVect<KEY, T, VECT> avect3;
		avect3.insertnonstrict(vect[0]);
		avect3.insertnonstrict(vect[0]);
		avect3.insertnonstrict(vect[1]);
		avect3.insertnonstrict(vect[1]);
		avect3.insertnonstrict(vect[2]);
		avect3.insertnonstrict(vect[2]);
		test_(avect3.size() == 6);
		avect3.unique();
		test_(avect3.size() == 2);
		test_(avect3[11] == (T)22.);
		test_(avect3[33] == (T)44.);
		//avect.insert(vect[2]);
		//test_(avect)
	}

	void InstertionTest()
	{
		std::vector< std::pair<int, int> > vect;
		vect.push_back(std::make_pair<int, int>(11, 22));
		vect.push_back(std::make_pair<int, int>(11, 22));
		vect.push_back(std::make_pair<int, int>(33, 44));
		vect.push_back(std::make_pair<int, int>(55, 66));
		vect.push_back(std::make_pair<int, int>(66, 22));

		InstertionTest<int, int, std::vector>(vect);

		std::vector< std::pair<double, double> > vect2;
		vect2.push_back(std::make_pair<int, int>(11, 22));
		vect2.push_back(std::make_pair<int, int>(11, 22));
		vect2.push_back(std::make_pair<int, int>(33, 44));
		vect2.push_back(std::make_pair<int, int>(55, 66));
		vect2.push_back(std::make_pair<int, int>(66, 22));

		InstertionTest<double, double, std::vector>(vect2);

		std::vector< std::pair<int, double> > vect3;
		vect3.push_back(std::make_pair<int, int>(11, 22));
		vect3.push_back(std::make_pair<int, int>(11, 22));
		vect3.push_back(std::make_pair<int, int>(33, 44));
		vect3.push_back(std::make_pair<int, int>(55, 66));
		vect3.push_back(std::make_pair<int, int>(66, 22));

		InstertionTest<int, double, std::vector>(vect3);



		//std::list< std::pair<int, int> > vect4;
		//vect4.push_back(std::make_pair<int, int>(11, 22));
		//vect4.push_back(std::make_pair<int, int>(11, 22));
		//vect4.push_back(std::make_pair<int, int>(33, 44));
		//vect4.push_back(std::make_pair<int, int>(55, 66));
		//vect4.push_back(std::make_pair<int, int>(66, 22));

		//InstertionTest<int, int, std::list>(vect4);

		//std::vector< std::pair<double, double> > vect5;
		//vect5.push_back(std::make_pair<int, int>(11, 22));
		//vect5.push_back(std::make_pair<int, int>(11, 22));
		//vect5.push_back(std::make_pair<int, int>(33, 44));
		//vect5.push_back(std::make_pair<int, int>(55, 66));
		//vect5.push_back(std::make_pair<int, int>(66, 22));

		//InstertionTest<double, double, std::list>(vect5);

		//std::vector< std::pair<int, double> > vect6;
		//vect6.push_back(std::make_pair<int, int>(11, 22));
		//vect6.push_back(std::make_pair<int, int>(11, 22));
		//vect6.push_back(std::make_pair<int, int>(33, 44));
		//vect6.push_back(std::make_pair<int, int>(55, 66));
		//vect6.push_back(std::make_pair<int, int>(66, 22));

		//InstertionTest<int, double, std::list>(vect6);
	}


public:
	void Run()
	{
		DefaultConstructor();
		InstertionTest();
	}
};


#endif // ASSOCVECTOR_TEST_H 