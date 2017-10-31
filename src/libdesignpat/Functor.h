#ifndef __FUNCTOR_H__
#define __FUNCTOR_H__

#include <tuple>
#include <iostream>

/*
TODO:
- Chain
- Bind nth arg
*/


template<
	typename RETTYPE,
	typename... PARAM
>
class FunctorBase
{
public:
	virtual RETTYPE operator()(const PARAM&... param) = 0;
};

template<
	typename RETTYPE,
	class FUN,
	typename... PARAM
>
class FunctorHandler : public FunctorBase<RETTYPE, PARAM...>
{
public:
	FunctorHandler(const FUN& fun) : mfun(fun)	{}
	RETTYPE operator()(const PARAM&... p)
	{
		return mfun(p...);
	}

private:
	FUN mfun;
};

template<
	typename RETTYPE,
	class OBJ,
	class FUN,
	typename... PARAM
>
class FunctorMemFunHandler : public FunctorBase<RETTYPE, PARAM...>
{
public:
	FunctorMemFunHandler(const OBJ& obj, const FUN& fun) : mpobj(obj), mfun(fun)	{}
	RETTYPE operator()(const PARAM&... p)
	{
		return ((*mpobj).*mfun)(p...);
	}

private:
	OBJ mpobj;
	FUN mfun;
};

template<
	typename RETTYPE,
	typename... PARAM
>
class Functor
{
public:
//	using TYPW = PARAM;
	//typedef std::tuple<PARAM...>	PP;
	//enum { nparam = sizeof...(PARAM) };

	Functor()				{}

	template<typename FUN>
	Functor(FUN f) : mpfuncimpl(new FunctorHandler<RETTYPE, FUN, PARAM...>(f))	{}

	template<class OBJ, class FUN>
	Functor(OBJ obj, FUN f) : mpfuncimpl(new FunctorMemFunHandler<RETTYPE, OBJ, FUN, PARAM...>(obj, f))	{}

	RETTYPE operator()(const PARAM&... p)
	{
		return (*mpfuncimpl)(p...);
	}

	~Functor()
	{
		if (!mpfuncimpl)
			delete mpfuncimpl;
	}

protected:
	//PP	GetTuple()	{ return  }
private:
	FunctorBase<RETTYPE, PARAM...>*	mpfuncimpl;
};

//template<
//	class FUNC1,
//	class FUNC2
//>
//class ChainHelper : public FUNC2
//{
//public:
//	typedef typename FUNC2::PP	P;
//private:
//	enum { size = FUNC2::nparam };
//public:
//	//typedef typename FUNC2::PP	P;
//
//	ChainHelper(FUNC1 func1, FUNC2 func2) : mfunc1(func1), mfunc2(func2)	{}
//
//	FUNC2 operator()(...)
//	{
//		mfunc1(const std::get<size>(P)...);
//		return mfunc2;
//	}
//
//private:
//	//enum { size = P::nparam };
//
//	FUNC1 mfunc1;
//	FUNC2 mfunc2;
//};
//
//template<
//	class FUNC1,
//	class FUNC2
//>
//FUNC2 Chain(FUNC1 f1, FUNC2 f2)
//{
//	return FUNC2(new ChainHelper<FUNC1, FUNC2>(f1, f2));
//}
//

#endif //__FUNCTOR_H__
