LIST ( APPEND singletontest_files
	singletontest.h
	singletontest.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
  ${MyLib_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( singletontest ${singletontest_files} )
SET_TARGET_PROPERTIES(singletontest PROPERTIES LINKER_LANGUAGE CXX)