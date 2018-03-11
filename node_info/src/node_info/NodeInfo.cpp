#include <foas/plugins/node_info/NodeInfo.h>


namespace foas {
  namespace plugins {
    NodeInfo::NodeInfo() {
      std::cout << "NodeInfo!" << std::endl;
    }

    NodeInfo::~NodeInfo() {
      std::cout << "Oh no, let's go!" << std::endl;
    }
  }
}
