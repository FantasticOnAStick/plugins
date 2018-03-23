#ifndef __FOAS_PLUGINS_NODEINFO_H__
#define __FOAS_PLUGINS_NODEINFO_H__


#include <iostream>
#include <memory>

#include <foas/common/Task.h>
#include <foas/common/Protected.hpp>

#include <foas/plugin/Plugin.h>


namespace foas {
  namespace plugins {
    class NodeInfo : public plugin::Plugin {
    private:
      common::Task mRunner;
      common::Protected<bool> mStop;
      
    public:
      NodeInfo(std::shared_ptr<message::Bus> bus);
      ~NodeInfo();
      
      virtual bool Initialize() override;
      virtual void Deinitialize() override;

      void Run();
    };
  }
}


extern "C" {
  std::string GetName() {
    return "node_info";
  }
  
  std::shared_ptr<foas::plugin::Plugin> CreateInstance(std::shared_ptr<foas::message::Bus> bus) {
    return std::make_shared<foas::plugins::NodeInfo>(bus);
  }
}


#endif /* __FOAS_PLUGINS_NODEINFO_H__ */
