#pragma once

#include <memory>

#include "IMethod.h"

class AutoWiredManager {
public:
  static void
  AddService(const std::string& name, std::shared_ptr<IService> service);

  static std::shared_ptr<IService> GetService(const std::string& name);

  static void
  AddServiceSetter(const std::string& serviceName, ServiceSetter functor);

  static ServiceSetter GetServiceSetter(const std::string& name);
};