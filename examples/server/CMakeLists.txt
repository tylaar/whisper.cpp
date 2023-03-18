set(TARGET server)


find_package(Drogon CONFIG REQUIRED)

add_executable(${TARGET} server.cpp test_ctrl.h)

set_property(TARGET server PROPERTY CXX_STANDARD 17)

include(DefaultTargetOptions)

target_link_libraries(${TARGET} PRIVATE Drogon::Drogon common whisper ${CMAKE_THREAD_LIBS_INIT})
