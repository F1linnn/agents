file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

include_directories(${CMAKE_CURRENT_LIST_DIR} ${SC_MEMORY_SRC} ${SC_KPM_SRC})

add_library (Search_mil_equipment SHARED ${SOURCES})
target_link_libraries(Search_mil_equipment sc-memory sc-agents-common)

sc_codegen_ex(Search_mil_equipment ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/generated)
