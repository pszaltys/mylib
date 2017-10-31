ADD_SUBDIRECTORY ( factorytest )
ADD_SUBDIRECTORY ( functortest )
ADD_SUBDIRECTORY ( visitortest )
ADD_SUBDIRECTORY ( singletontest )
ADD_SUBDIRECTORY ( xtestmaster )

SET_PROPERTY(TARGET factorytest functortest visitortest singletontest xtestmaster PROPERTY FOLDER "xtestdesignpat")