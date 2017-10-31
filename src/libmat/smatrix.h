#ifndef SMATRIX_H
#define SMATRIX_H

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
private:
	map<KeyVal, T>		mmap;

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
		if (!mmap.insert(make_pair(key, val[k])).second)
			throw "Error: SMatrix<T, N>::Init2d - duplicate entry";
	}
}


#endif // SMATRIX_H 