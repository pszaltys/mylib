#ifndef __KEY_TEST_H__
#define __KEY_TEST_H__

#include "testmaster.h"
#include "key.h"

class KeyTest : public UnitTest::Test
{
	template< int N>
	void Constructors();
	template< int N, typename T>
	void Constructors();
	template<typename... I>
	void Constructors(I... ids);
	void Constructors();

	template< int N, typename T>
	void Accessors();
	void Accessors();

	void Ops();
	void Sort();
public:
	void Run();
};

 #endif //__KEY_TEST_H__
