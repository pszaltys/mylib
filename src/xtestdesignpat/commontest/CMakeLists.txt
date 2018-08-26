LIST ( APPEND commontest_files
	keytest.h
	keytest.cpp
	helperstest.h
	helperstest.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
  ${MyLib_SOURCE_DIR}/libcommon
  # ${MyLib_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( commontest ${commontest_files} )
# SET_TARGET_PROPERTIES(commontest PROPERTIES LINKER_LANGUAGE CXX)