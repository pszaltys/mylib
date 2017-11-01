LIST ( APPEND xtestmaster_files
	main.cpp
) 


INCLUDE_DIRECTORIES (
  ${MyLib_SOURCE_DIR}/libdesignpat
  ${MyLib_SOURCE_DIR}/libcommon
  ${MyLib_SOURCE_DIR}/libmat
  ${MyLib_SOURCE_DIR}/xtestdesignpat
  ${MyLib_SOURCE_DIR}/libunittest
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
	mat
	common
	designpat
	mattest
	commontest
	factorytest
	functortest
	singletontest
	visitortest
) 
