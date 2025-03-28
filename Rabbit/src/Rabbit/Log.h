#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rabbit {

  class RABBIT_API Log
  {
  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };

}

// Core log macros
#define RB_CORE_ERROR(...) ::Rabbit::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RB_CORE_WARN(...)  ::Rabbit::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RB_CORE_INFO(...)  ::Rabbit::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RB_CORE_TRACE(...) ::Rabbit::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RB_CORE_FATAL(...) ::Rabbit::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define RB_ERROR(...) ::Rabbit::Log::GetClientLogger()->error(__VA_ARGS__)
#define RB_WARN(...)  ::Rabbit::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RB_INFO(...)  ::Rabbit::Log::GetClientLogger()->info(__VA_ARGS__)
#define RB_TRACE(...) ::Rabbit::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RB_FATAL(...) ::Rabbit::Log::GetClientLogger()->fatal(__VA_ARGS__)