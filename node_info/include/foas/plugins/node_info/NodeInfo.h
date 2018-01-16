#ifndef __FOAS_PLUGINS_NODEINFO_H__
#define __FOAS_PLUGINS_NODEINFO_H__


#include <memory>

#include <foas/plugin/Plugin.h>


namespace foas {
  namespace plugins {
    class NodeInfo : public plugin::Plugin {
    public:
      NodeInfo();
      ~NodeInfo();
    };
  }
}


extern "C" {
  std::shared_ptr<foas::plugin::Plugin> CreateInstance() {
    return std::make_shared<foas::plugins::NodeInfo>();
  }
}


#endif /* __FOAS_PLUGINS_NODEINFO_H__ */