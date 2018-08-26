LIST ( APPEND common_files
	key.h
	key.cpp
	helpers.h
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( common ${common_files} )