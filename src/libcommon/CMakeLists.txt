LIST ( APPEND common_files
	key.h
	key.cpp
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( common ${common_files} )