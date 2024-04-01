cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)


# did these 2 made it actually work?!
set(wxWidgets_USE_STATIC 1)
set(wxBUILD_SHARED OFF)
# Include FetchContent module
include(FetchContent)

project(game_of_life)

# Fetch wxWidgets
FetchContent_Declare(
    wxWidgets
    URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(wxWidgets)
FetchContent_GetProperties(wxWidgets)
if(NOT wxWidgets_POPULATED)
    if(NOT EXISTS ${wxWidgets_SOURCE_DIR})
        FetchContent_Populate(wxWidgets)
        add_subdirectory(${wxWidgets_SOURCE_DIR} ${wxWidgets_BINARY_DIR})
    endif()
endif()
# if(NOT wxWidgets_POPULATED)
#    FetchContent_Populate(wxWidgets)
#    add_subdirectory(${wxWidgets_SOURCE_DIR} ${wxWidgets_BUILD_DIR})
# endif()

# include(wxWidgets)
add_executable(game_of_life
    ./src/app.cpp
    ./src/draw_board_pane.cpp
    ./src/gamefield.cpp
)

target_include_directories(game_of_life PRIVATE ${wxWidgets_SOURCE_DIR}/include)
target_link_libraries(game_of_life PRIVATE wx::core wx::base)