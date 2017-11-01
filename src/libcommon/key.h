#ifndef KEY_H
#define KEY_H

#include <memory>
#include <vector>
#include <algorithm>

template< int N, typename T = int>
class Key
{
public:
	Key()
	{
		std::uninitialized_fill(mtab, mtab + N, T());
	}

	Key(const vector<T>& tab)
	{
		copy(tab.begin(), tab.end(), mtab);
	}

	template <typename... U>
	Key(U... ts) : mtab{ ts... } { }

	const T&	cKey(const  int& id) const { return mtab[id]; }
	T&			rKey(const  int& id) { return mtab[id]; }

	void		Sort() { std::sort(mtab, mtab + N); }

private:
	T mtab[N];
};

template< int N, typename T>
inline bool	operator==(const Key<N, T>& k1, const Key<N, T>& k2)
{
	for (int i = 0; i < N; ++i)
	{
		if (k1.cKey(i) != k2.cKey(i)) return false;
	}
	return true;
}

template< int N, typename T>
inline bool	operator<(const Key<N, T>& k1, const Key<N, T>& k2)
{
	if (k1.cKey(0) < k2.cKey(0))		return true;
	else if (k1.cKey(0) > k2.cKey(0))	return false;

	Key<N - 1, T>	subk1, subk2;
	for (int i = 0; i < N - 1; ++i)
	{
		subk1.rKey(i) = k1.cKey(i + 1);
		subk2.rKey(i) = k2.cKey(i + 1);
	}

	return subk1 < subk2;
}

template<typename T>
inline bool	operator<(const Key<1, T>& k1, const Key<1, T>& k2)
{
	return k1.cKey(0) < k2.cKey(0);
}

#endif // KEY_H 