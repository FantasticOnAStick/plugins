#include <foas/plugins/node_info/NodeInfo.h>


namespace foas {
  namespace plugins {
    NodeInfo::NodeInfo(std::shared_ptr<message::Bus> bus) : plugin::Plugin(bus), mRunner([=]() { this->Run(); }), mStop(false) {
    }
    
    NodeInfo::~NodeInfo() {
    }
    
    bool NodeInfo::Initialize() {
      std::shared_ptr<message::Class> nodeInfoClass = mBus->GetClassManager()->CreateClass("NodeInfo");
      nodeInfoClass->AddSuperClass("Info");
      
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
	
	std::shared_ptr<common::Property> nodeInfo = mBus->GetClassManager()->InstantiateClass("NodeInfo");
	// ...
	
	mBus->QueueMessage("/info", std::make_shared<message::Message>(nodeInfo));
	
	common::Task::Sleep(1000);
      }
    }
  }
}
