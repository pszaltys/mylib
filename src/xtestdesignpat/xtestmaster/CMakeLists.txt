LIST ( APPEND xtestmaster_files
	main.cpp
) 


INCLUDE_DIRECTORIES (
  ${UnitTest_SOURCE_DIR}/libdesignpat
  ${UnitTest_SOURCE_DIR}/xtestdesignpat
  ${UnitTest_SOURCE_DIR}/libunittest
)

#LINK_DIRECTORIES (
 # ${UnitTest_BINARY_DIR}/xtestdesignpat/factorytest
#)

ADD_EXECUTABLE ( xtestmaster ${xtestmaster_files} )
# SET_PROPERTY(TARGET xtestmaster PROPERTY FOLDER "xtestdesignpat")

##############################################################
# !!!  the order of the libraries in the list is IMPORTANT !!!
TARGET_LINK_LIBRARIES ( xtestmaster 
	unittest
	designpat
	factorytest
	functortest
	singletontest
	visitortest
) 
