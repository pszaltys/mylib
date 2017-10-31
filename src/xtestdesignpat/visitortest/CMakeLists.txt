LIST ( APPEND visitortest_files
	visitortest.h
	visitortest.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
  ${MyLib_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( visitortest ${visitortest_files} )
# SET_TARGET_PROPERTIES(factorytest PROPERTIES LINKER_LANGUAGE CXX)
# SET_PROPERTY(TARGET factorytest PROPERTY FOLDER "xtestdesignpat")