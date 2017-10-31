LIST ( APPEND unitest_files
	testbase.h
	testbase.cpp
	testmaster.h
	testmaster.cpp
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( unittest ${unitest_files} )