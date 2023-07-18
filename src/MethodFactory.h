#pragma once

#include <memory>
#include <string>

#include "AutoWiredManager.h"

class MethodFactory {
public:
  static MethodFactory* Get() {
    static MethodFactory factory;
    return &factory;
  }

  template <typename T> std::shared_ptr<T> CreateMethod() const {
    std::shared_ptr<T> method = std::make_shared<T>();
    auto service = AutoWiredManager::GetService(method->GetServiceName());
    method->SetService(std::move(service));
    return method;
  }
};