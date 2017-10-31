ADD_SUBDIRECTORY ( assocvectortest )
ADD_SUBDIRECTORY ( factorytest )
ADD_SUBDIRECTORY ( functortest )
ADD_SUBDIRECTORY ( visitortest )
ADD_SUBDIRECTORY ( singletontest )
ADD_SUBDIRECTORY ( commontest )
ADD_SUBDIRECTORY ( xtestmaster )

SET_PROPERTY(TARGET assocvectortest factorytest functortest visitortest singletontest commontest xtestmaster PROPERTY FOLDER "xtestdesignpat")