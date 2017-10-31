#ifndef ASSOCVECTOR_H
#define ASSOCVECTOR_H

#include <algorithm>
#include <vector>
#include <bitset>

struct NullType {};

template <class T, size_t SHIFT = 10, class ALLOC = std::allocator<T> >
class arrvector;

template <class T>
class fgvector;

template <class T, size_t SHIFT = 16>
class fgarrvector;

template <class T>
class fvector;

enum VectorList
{
	vt_arrvector,
	vt_fgvector,
	vt_fgarrvector,
	vt_fvector,
	vt_vector
};

template< typename T, VectorList VectorSelect>
struct MakeVect
{
	typedef NullType	Vector;
};

template< typename T>
struct MakeVect<T, vt_arrvector>
{
	typedef arrvector<T>	Vector;
};

template< typename T>
struct MakeVect<T, vt_fgvector>
{
	typedef fgvector<T>	Vector;
};

template< typename T>
struct MakeVect<T, vt_fgarrvector>
{
	typedef fgarrvector<T>	Vector;
};

template< typename T>
struct MakeVect<T, vt_fvector>
{
	typedef fvector<T>	Vector;
};

template< typename T>
struct MakeVect<T, vt_vector>
{
	typedef std::vector<T>	Vector;
};

template<typename U, typename V>
bool Comp(const std::pair<U, V>& p1, const std::pair<U, V>& p2)
{
	return (p1.first < p2.first);
}

//template<
//	class KEY,
//	class T,
//	VectorList VL
//>
//class AssocVect : public MakeVect< std::pair<KEY, T>, VL>::Vector
template<
	class KEY,
	class T,
	class Vect = std::vector< pair<KEY, T> >
>
class AssocVect : public Vect
{
	//typedef typename MakeVect< std::pair<KEY, T>, VL>::Vector	Base;
	typedef typename Vect	Base;
public:
	typedef KEY													key_type;
	typedef T													mapped_type;
	typedef std::pair<KEY, T>									value_type;

	typedef typename Base::iterator								iterator;
	typedef typename Base::const_iterator						const_iterator;


	AssocVect() : Base()		{}
	//T&	operator[]	

	void						insertnonstrict(const std::pair<KEY, T>& val)
	{
		Base::push_back(val);
		flag[0] = false;
		flag[1] = false;
	}

	void						unique()
	{
		if (!flag[0])
		{
			sort(Base::begin(), Base::end());
			flag[0] = true;
		}
		if (!flag[1])
		{
			const_iterator citr = std::unique(Base::begin(), Base::end());
			Base::erase(citr, Base::end());
			flag[1] = true;
		}
	}

	iterator					find(const value_type& val)
	{
		this->unique();
		return std::lower_bound(Base::begin(), Base::end(), val, Comp<KEY, T>);
	}

	const_iterator				find(const value_type& val) const
	{
		if (!flag[0])
		{
			sort(Base::begin(), Base::end());
			flag[0] = true;
		}
		if (!flag[1])
		{
			const_iterator citr = std::unique(Base::begin(), Base::end());
			Base::erase(citr, Base::end());
			flag[1] = true;
		}
		return itr = std::lower_bound(Base::begin(), Base::end(), val, Comp<KEY, T>);
	}

	std::pair<iterator, bool>	insert(const value_type& val)	//not optimal
	{
		iterator itr = this->find(val);
		if (itr != Base::end())
		{
			if (itr->first != val.first)
			{
				return std::pair<iterator, bool>(Base::insert(itr, val), true);
			}
			else
			{
				return std::pair<iterator, bool>(itr, false);
			}
		}
		else
		{
			if (Base::empty())
			{
				Base::push_back(val);
			}
			else
			{
				Base::insert(Base::end(), val);
			}
			return std::pair<iterator, bool>(Base::end() - 1, true);
		}
	}

	mapped_type&				operator[](const key_type& key)
	{
		return insert(value_type(key, mapped_type())).first->second;
	}

	void						Dump()
	{
		cout << "==================" << endl;
		for (typename Base::const_iterator cit = Base::begin();
			cit != Base::end();
			++cit)
		{
			cout << "[\t" << cit->first << ",\t" << cit->second << "]" << endl;
		}
	}
private:
	std::bitset<2> flag; //is sorted, is unique

};

#endif // ASSOCVECTOR_H 