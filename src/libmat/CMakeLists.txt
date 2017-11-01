LIST ( APPEND mat_files
	smatrix.h
	smatrix.cpp
) 

INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libcommon
)

ADD_LIBRARY ( mat ${mat_files} )