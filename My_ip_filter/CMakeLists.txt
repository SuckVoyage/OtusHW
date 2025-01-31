cmake_minimum_required(VERSION 3.10)

project(IP_ADRESS_SORT VERSION 0.0.1)

configure_file(
	config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config.h
)

set (
	SOURCES
	My_ip_filter.cpp
	IpAdress.cpp
	Version.cpp
)

set(
	HEADERS
	IpAdress.h
	Version.h
)

add_executable(MyProject ${SOURCES} ${HEADERS})

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
