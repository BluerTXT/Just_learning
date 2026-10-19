cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Sort.cpp")

add_executable (Sort.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Sort.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/func/BubbleSort.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/func/Random.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/func/printArray.cpp)
target_include_directories(Sort.cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

target_compile_options(Sort.cpp  PRIVATE $<$<COMPILE_LANGUAGE:CXX>:$<$<CXX_COMPILER_ID:MSVC>:/utf-8>>)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sort.cpp PROPERTY CXX_STANDARD 20)
endif()