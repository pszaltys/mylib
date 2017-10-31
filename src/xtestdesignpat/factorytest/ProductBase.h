#ifndef __PRODUCT_BASE_H__
#define __PRODUCT_BASE_H__

//#include "FactoryBase.h"

class TestProductBase
{
public:
	virtual bool CreateProd() = 0;
	virtual int& SetVar() = 0;
	virtual const int& GetVar() const = 0;
};

#endif //__PRODUCT_BASE_H__
