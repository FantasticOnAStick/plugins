#include <foas/plugins/node_info/NodeInfo.h>


namespace foas {
  namespace plugins {
    NodeInfo::NodeInfo(std::shared_ptr<message::Bus> bus) : plugin::Plugin(bus) {
      std::cout << "NodeInfo!" << std::endl;
    }

    NodeInfo::~NodeInfo() {
      std::cout << "Oh no, let's go!" << std::endl;
    }
  }
}
