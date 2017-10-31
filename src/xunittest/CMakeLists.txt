LIST ( APPEND xunittest_files
	main.cpp
) 


INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libunittest
)


# LINK_DIRECTORIES (
  # ${UnitTest_BINARY_DIR}/libunittest
# )

ADD_EXECUTABLE ( xunittest ${xunittest_files} )


##############################################################
# !!!  the order of the libraries in the list is IMPORTANT !!!
TARGET_LINK_LIBRARIES ( xunittest 
	unittest
) 
