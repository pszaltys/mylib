LIST ( APPEND mattest_files
	smatrixtest.h
	smatrixtest.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
  ${MyLib_SOURCE_DIR}/libcommon
   ${MyLib_SOURCE_DIR}/libmat
  # ${MyLib_SOURCE_DIR}/libdesignpat
)

ADD_LIBRARY ( mattest ${mattest_files} )
# SET_TARGET_PROPERTIES(commontest PROPERTIES LINKER_LANGUAGE CXX)