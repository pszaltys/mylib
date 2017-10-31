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

	void Constructors();

	template< int N, typename T>
	void Accessors();

	void Accessors();
public:
	void Run();
};

 #endif //__KEY_TEST_H__
