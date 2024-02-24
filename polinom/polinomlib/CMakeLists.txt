#CmakeLists для библиотеки polinomlib
file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${polinomlib} STATIC ${srcs} ${hdrs}) 


