#include "keytest.h"


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

void KeyTest::Run()
{
	Constructors();
	Accessors();
}

