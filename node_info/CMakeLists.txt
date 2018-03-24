project(foas_plugins_node_info)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -fPIC")

include_directories(
  include
  ../../foas_common/include
  ../../foas_message/include
  ../../foas_plugin/include)

file(GLOB_RECURSE LIB_SRC FOLLOW_SYMLINKS src/node_info/*.cpp)
add_library(${PROJECT_NAME} SHARED
  ${LIB_SRC})

target_link_libraries(${PROJECT_NAME}
  foas_common
  foas_message
  foas_plugin)
