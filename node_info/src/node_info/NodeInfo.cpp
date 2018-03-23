#include <foas/plugins/node_info/NodeInfo.h>


namespace foas {
  namespace plugins {
    NodeInfo::NodeInfo(std::shared_ptr<message::Bus> bus) : plugin::Plugin(bus), mRunner([=]() { this->Run(); }), mStop(false) {
    }
    
    NodeInfo::~NodeInfo() {
    }
    
    bool NodeInfo::Initialize() {
      mRunner.Start();
      
      return true;
    }
    
    void NodeInfo::Deinitialize() {
      mStop = true;
      mRunner.Wait();
    }
    
    void NodeInfo::Run() {
      while(mStop == false) {
	std::cout << "Step." << std::endl;

	common::Task::Sleep(1000);
      }
    }
  }
}
