# CMakeList.txt: проект CMake для Multifile_example; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Multifile_example")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Multifile_example "Multifile_example.cpp" "Multifile_example.h" "functions/myadd.cpp")
target_include_directories(Multifile_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/functions)

target_compile_options(Multifile_example PRIVATE $<$<COMPILE_LANGUAGE:CXX>:$<$<CXX_COMPILER_ID:MSVC>:/utf-8>>)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Multifile_example PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
