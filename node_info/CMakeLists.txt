project(foas_plugins_node_info)

include_directories(
  include
  ../../foas_common/include
  ../../foas_message/include
  ../../foas_plugin/include)

file(GLOB_RECURSE LIB_SRC src/node FOLLOW_SYMLINKS *.cpp)
add_library(${PROJECT_NAME} SHARED
  ${LIB_SRC})

target_link_libraries(${PROJECT_NAME}
  foas_common
  foas_message
  foas_plugin)
