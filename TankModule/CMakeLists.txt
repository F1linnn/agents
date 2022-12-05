set(SOURCES
        "TankModule.cpp"
        "agent/FindTankAgent.cpp"
        "keynodes/TankKeynodes.cpp"
        )

set(HEADERS
        "TankModule.hpp"
        "agent/FindTankAgent.hpp"
        "keynodes/TankKeynodes.hpp"
        )

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}
        ${SC_MEMORY_SRC}
        ${SC_KPM_SRC}
        ${SC_TOOLS_SRC}
)

add_library(TankModule SHARED ${SOURCES} ${HEADERS})

target_link_libraries(
        TankModule
        sc-memory
        sc-agents-common
)

sc_codegen_ex(TankModule ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/generated)



