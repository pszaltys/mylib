LIST ( APPEND functortest_files
	functortest.h
	functortest.cpp
) 

INCLUDE_DIRECTORIES (
  ${UnitTest_SOURCE_DIR}/libunittest
  ${UnitTest_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( functortest ${functortest_files} )
SET_TARGET_PROPERTIES(functortest PROPERTIES LINKER_LANGUAGE CXX)
# SET_PROPERTY(TARGET factorytest PROPERTY FOLDER "xtestdesignpat")