LIST ( APPEND functortest_files
	functortest.h
	functortest.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
  ${MyLib_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( functortest ${functortest_files} )
SET_TARGET_PROPERTIES(functortest PROPERTIES LINKER_LANGUAGE CXX)
# SET_PROPERTY(TARGET factorytest PROPERTY FOLDER "xtestdesignpat")