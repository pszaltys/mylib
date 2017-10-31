LIST ( APPEND factorytest_files
	ConcProd.h
	ProductBase.h
	factorytest.h
	factorytest.cpp
) 

INCLUDE_DIRECTORIES (
  ${UnitTest_SOURCE_DIR}/libunittest
)
INCLUDE_DIRECTORIES (
  ${UnitTest_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( factorytest ${factorytest_files} )
# SET_TARGET_PROPERTIES(factorytest PROPERTIES LINKER_LANGUAGE CXX)
# SET_PROPERTY(TARGET factorytest PROPERTY FOLDER "xtestdesignpat")