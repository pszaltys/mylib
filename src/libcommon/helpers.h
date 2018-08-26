#ifndef __HELPERS_H__
#define __HELPERS_H__


template<typename T, size_t N>
constexpr size_t ArraySize(T (&)[N])
{
	return N;
}



#endif //__HELPERS_H__
