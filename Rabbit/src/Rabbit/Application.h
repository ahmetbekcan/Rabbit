#pragma once
#include "Core.h"
namespace Rabbit {

  class RABBIT_API Application
  {
  public:
    Application();
    virtual ~Application();
    void Run();
  };

  //To be defined in CLIENT
  Application* CreateApplication();
}

