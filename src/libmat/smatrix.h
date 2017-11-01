#ifndef SMATRIX_H
#define SMATRIX_H

#include <map>
#include "key.h"

template<typename T, int N = 2>
class SMatrix
{
public:
	typedef Key<N>	KeyVal;

	template<typename... I>
	const T&	cVal(I... ids)
	{
		Key<sizeof...(ids)> k(ids...);
		return mmap[k];
	}

	template<typename... I>
	T&	rVal(I... ids)
	{
		Key<sizeof...(ids)> k(ids...);
		return mmap[k];
	}

	void Init2d(const vector<int>& i, const vector<int>& j, const vector<T>& val);

//	template<Args... A>
//	void Init(A... args);

private:
	std::map<KeyVal, T>		mmap;

};

template<typename T, int N>
void SMatrix<T, N>::Init2d(const vector<int>& i, const vector<int>& j, const vector<T>& val)
{
	if (i.size() != j.size()) throw "Error: SMatrix<T, N>::Init2d - size: i != j";
	if (i.size() != val.size()) throw "Error: SMatrix<T, N>::Init2d - size: i != val";
	if (val.size() != j.size()) throw "Error: SMatrix<T, N>::Init2d - size: j != val";

	for (size_t k = 0; k < i.size(); ++k)
	{
		Key<2> key(i[k], j[k]);
		if (!mmap.insert(std::make_pair(key, val[k])).second)
			throw "Error: SMatrix<T, N>::Init2d - duplicate entry";
	}
}

//template<typename T, int N>
//template<Args... A>
//void SMatrix<T, N>::Init(A... args)
//{
//
//}

#endif // SMATRIX_H 