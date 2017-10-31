LIST ( APPEND assocvectortest_files
	assocvecttest.h
	assocvecttest.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
)
INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( assocvectortest ${assocvectortest_files} )
# SET_TARGET_PROPERTIES(factorytest PROPERTIES LINKER_LANGUAGE CXX)
# SET_PROPERTY(TARGET factorytest PROPERTY FOLDER "xtestdesignpat")