LIST ( APPEND mat_files
	smatrix.h
	smatrix.cpp
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( mat ${mat_files} )