#include "keytest.h"
#include <utility>
#include <algorithm>

template< int N>
void KeyTest::Constructors()
{
	Key<N>* key = new Key<N>;
	test_(key != NULL);

	for (int i = 0; i < N; i++)
	{
		test_(key->cKey(i) == 0);
	}

	vector<int> tab(N);
	for (int i = 0; i < N; i++)
	{
		tab[i] = int(rand());
	}
	Key<N> key2(tab);
	for (int i = 0; i < N; i++)
	{
		test_(key2.cKey(i) == tab[i]);
	}

	
}

template< int N, typename T>
void KeyTest::Constructors()
{
	Key<N, T>* key = new Key<N, T>;
	test_(key != NULL);

	for (int i = 0; i < N; i++)
	{
		test_(key->cKey(i) == T());
	}

	vector<T> tab(N);
	for (int i = 0; i < N; i++)
	{
		tab[i] = T(rand());
	}
	Key<N, T> key2(tab);
	for (int i = 0; i < N; i++)
	{
		test_(key2.cKey(i) == tab[i]);
	}
}

template<typename... I>
void KeyTest::Constructors(I... ids)
{
	Key<sizeof...(ids)> key(ids.second...);
	
	auto f = [this](Key<sizeof...(ids)>& k, std::pair<int,int> p) {test_( k.cKey(p.first) == p.second); };
	int dummy[] = { 0, (f(key, std::forward<I>(ids)), 0)... };
}

void KeyTest::Constructors()
{
	Constructors<1>();
	Constructors<1, int>();

	Constructors<1>();
	Constructors<1, double>();

	Constructors<2>();
	Constructors<2, int>();

	Constructors<2>();
	Constructors<2, double>();

	Constructors<3>();
	Constructors<3, int>();

	Constructors<3>();
	Constructors<3, double>();

	Key<3> key = { 1, 22, 333 };
	test_(key.cKey(0) == 1);
	test_(key.cKey(1) == 22);
	test_(key.cKey(2) == 333);

	
	Constructors(std::make_pair( 0,1 ), std::make_pair( 1, 22 ), std::make_pair( 2, 333 ), std::make_pair(3, 4444));
}

template< int N, typename T>
void KeyTest::Accessors()
{
	Key<N,T> k1;
	T controltab[N];

	for (int i = 0; i < N; i++)
	{
		controltab[i] = T(rand());
		k1.rKey(i) = controltab[i];
	}

	for (int i = 0; i < N; i++)
	{
		test_(k1.cKey(i) == controltab[i]);
	}

	for (int i = 0; i < N; i++)
	{
		controltab[i] = T(rand());
		k1.rKey(i) = controltab[i];
	}

	for (int i = 0; i < N; i++)
	{
		test_(k1.cKey(i) == controltab[i]);
	}
}

void KeyTest::Accessors()
{
	Accessors<1,int>();
	Accessors<2, int>();
	Accessors<3, int>();
	Accessors<10, int>();

	Accessors<1, double>();
	Accessors<2, double>();
	Accessors<3, double>();
	Accessors<10, double>();
}

void KeyTest::Ops()
{
	Key<3> k = { 1, 22, 333 };
	Key<3> k2 = { 1, 22, 333 };

	test_(k == k2);

	k.rKey(0) = 0;
	test_(!(k == k2));
	test_(k < k2);
	k2.rKey(0) = -1;
	test_(k2 < k);

	k.rKey(0) = -1;
	k.rKey(1) = 2;
	test_(!(k == k2));
	test_(k < k2);
	k2.rKey(1) = 1;
	test_(k2 < k);

	k.rKey(1) = 1;
	k.rKey(2) = 33;
	test_(!(k == k2));
	test_(k < k2);
	k2.rKey(2) = 3;
	test_(k2 < k);
}

void KeyTest::Sort()
{
	Key<10> k1;
	int controltab[10];

	for (int i = 0; i < 10; i++)
	{
		controltab[i] = int(rand());
		k1.rKey(i) = controltab[i];
	}
	std::sort(controltab, controltab + 10);

	k1.Sort();
	for (int i = 0; i < 10; i++)
	{
		test_(k1.cKey(i) == controltab[i]);
	}
}

void KeyTest::Run()
{
	Constructors();
	Accessors();
	Ops();
	Sort();
}

