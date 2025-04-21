cmake_minimum_required(VERSION 3.10)

# 1. project()
project(MyProject VERSION 1.0)

# 2. set()
set(SRC_DIR src)
set(INCLUDE_DIR include)

include_directories(${INCLUDE_DIR})

add_library(Author
    ${SRC_DIR}/Author.cpp
)
add_library(Book
    ${SRC_DIR}/Book.cpp
)
add_library(BookDetail
    ${SRC_DIR}/BookDetail.cpp
)
add_library(EBook
    ${SRC_DIR}/EBook.cpp
)
add_library(Library
    ${SRC_DIR}/Library.cpp
)

# 6. add_executable()
add_executable(main main.cpp)

# 7. target_link_libraries()
target_link_libraries(main PRIVATE Author Book BookDetail EBook Library)
