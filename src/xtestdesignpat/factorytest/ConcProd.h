#ifndef __CONC_PROD_H__
#define __CONC_PROD_H__


#include "ProductBase.h"

class ConcProduct1 : public TestProductBase
{
	int mdata;
public:
	ConcProduct1() : mdata(1)	{}

	virtual bool CreateProd()
	{
		//cout << "Prod1" << endl;
		return true;
	}
	virtual int& SetVar()				{ return mdata; }
	virtual const int& GetVar() const	{ return mdata; }
};

class ConcProduct2 : public TestProductBase
{
	int mdata;
public:
	ConcProduct2() : mdata(2)	{}

	virtual bool CreateProd()
	{
		//cout << "Prod2" << endl;
		return true;
	}
	virtual int& SetVar()				{ return mdata; }
	virtual const int& GetVar() const	{ return mdata; }
};

#endif //__CONC_PROD_H__
