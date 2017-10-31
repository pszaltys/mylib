LIST ( APPEND winbgi_files
	winbgi2.h
	winbgi2.cpp
) 

# INCLUDE_DIRECTORIES (
  # ${FLOW2_SOURCE_DIR}/${NAME_CORE}
# )

ADD_LIBRARY ( winbgi ${winbgi_files} )