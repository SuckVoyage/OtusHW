cmake_minimum_required(VERSION 3.10)

project(IP_ADRESS_SORT VERSION 0.0.1)

configure_file(
	config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config.h
)
set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/ip_filter.tsv")
set(DESTINATION_DIR "${CMAKE_BINARY_DIR}/destination/")

# Создаем целевую директорию, если она не существует
file(MAKE_DIRECTORY ${DESTINATION_DIR})

# Копируем файл
file(COPY ${SOURCE_FILE} DESTINATION ${DESTINATION_DIR})

set (
	SOURCES
	My_ip_filter.cpp
	IpAdress.cpp
	IpPool.cpp
	Version.cpp
)

set(
	HEADERS
	IpAdress.h
	IpPool.h
	Version.h
)

add_executable(MyProject ${SOURCES} ${HEADERS})

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "my_project")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_DESCRIPTION "Описание моего проекта")
set(CPACK_PACKAGE_MAINTAINER "Ваше имя <ваш_email@example.com>")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "MyProject")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Данила")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")

# Включите CPack
include(CPack)


set_target_properties(
	MyProject PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(
	MyProject
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)
