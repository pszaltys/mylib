LIST ( APPEND assocvector_files
	assocvector.h
	assocvector.cpp
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( assocvector ${assocvector_files} )