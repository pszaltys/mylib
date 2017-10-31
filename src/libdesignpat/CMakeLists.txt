LIST ( APPEND designpat_files
	factory.h
	functor.h
	factory.cpp
	singleton.h
	visitor.h
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( designpat ${designpat_files} )
SET_TARGET_PROPERTIES(designpat PROPERTIES LINKER_LANGUAGE CXX)