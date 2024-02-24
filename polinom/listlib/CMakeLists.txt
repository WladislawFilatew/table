#CmakeLists для библиотеки listlib
file(GLOB hdrs "*.h") 
file(GLOB srcs "*.cpp")

add_library(${listlib} STATIC ${srcs} ${hdrs})

