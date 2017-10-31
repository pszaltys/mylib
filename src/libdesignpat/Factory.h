#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <map>
#include <string>

//#include "ProductBase.h"
//#include "FactoryBase.h"
//#include "ConcProd.h"

template<
	class ProductBase,
	class Creator = ProductBase* (*)()
>
class Factory
{
	typedef std::map<std::string, Creator> MapType;

public:
	bool Register(const std::string& str, Creator pbase)
	{
		return mtypemap.insert(MapType::value_type(str, pbase)).second;
	}

	bool Unregister(const std::string& str)
	{
		MapType::iterator it = mtypemap.find(str);
		if (it == mtypemap.end())
		{
			return false;
		}
		else
		{
			return (mtypemap.erase(str) == 1);
		}
	}

	ProductBase* CreateObj(const std::string& str)
	{
		MapType::iterator it = mtypemap.find(str);
		if (it != mtypemap.end())
			return mtypemap[str]();

		return NULL;
	}

private:
	MapType	mtypemap;
};

#endif //__FACTORY_H__
