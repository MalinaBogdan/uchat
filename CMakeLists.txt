cmake_minimum_required(VERSION 3.17)
project(uchat C)

set(CMAKE_C_STANDARD 11)
add_link_options()


set(headers_inc inc/client.h inc/db.h inc/lib.h inc/replies.h inc/server.h)
AUX_SOURCE_DIRECTORY(src/lib lib_src)
AUX_SOURCE_DIRECTORY(src/client client_src)
AUX_SOURCE_DIRECTORY(src/server server_src)
AUX_SOURCE_DIRECTORY(src/server/db server_src)
AUX_SOURCE_DIRECTORY(src/server/command server_src)
AUX_SOURCE_DIRECTORY(src/server/replies server_src)
add_executable(uchat ${client_src} ${lib_src} ${headers_inc})
add_executable(uchat_server ${server_src} ${lib_src} ${headers_inc})

#target_link_libraries(uchat_server ${CMAKE_SOURCE_DIR}/libraries/sqlite3/libsqlite3.a)