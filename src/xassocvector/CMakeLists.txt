LIST ( APPEND xassocvector_files
	main.cpp
	assocvecttest.h
	assocvecttest.cpp
) 


INCLUDE_DIRECTORIES (
  ${UnitTest_SOURCE_DIR}/libassocvector
  ${UnitTest_SOURCE_DIR}/libunittest
)


# LINK_DIRECTORIES (
  # ${UnitTest_BINARY_DIR}/libunittest
# )

ADD_EXECUTABLE ( xassocvector ${xassocvector_files} )


##############################################################
# !!!  the order of the libraries in the list is IMPORTANT !!!
TARGET_LINK_LIBRARIES ( xassocvector 
	assocvector
	unittest
) 
