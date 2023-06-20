cmake_minimum_required(VERSION 3.17)

project(openrsync)
set(CMAKE_CXX_STANDARD 17)

aux_source_directory(. DIR_SRCS)
aux_source_directory(. DIR_HEADER)

add_library(${PROJECT_NAME}
        ${DIR_SRCS}
        )

add_executable(${PROJECT_NAME}bin
        ${DIR_SRCS}
        )

target_include_directories(${PROJECT_NAME}bin
        PUBLIC ${DIR_HEAD}
        PUBLIC openrsync
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC ${DIR_HEAD}
        PUBLIC openrsync
        )

set(INSTALL_HEAD_FILES openrsync/openrsync.h)

install(
        TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib # 动态库安装路径
        ARCHIVE DESTINATION lib # 静态库安装路径
        RUNTIME DESTINATION bin # 可执行文件安装路径
        PUBLIC_HEADER DESTINATION include # 头文件安装路径
)

install(
        FILES ${INSTALL_HEAD_FILES} DESTINATION include/openrsync
)
