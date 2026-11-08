cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("StringExample")

add_executable (StringExample "${CMAKE_CURRENT_SOURCE_DIR}/src/StringExample.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/headers/StringExample.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET StringExample PROPERTY CXX_STANDARD 20)
endif()
