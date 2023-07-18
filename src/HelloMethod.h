#pragma once
#include <memory>

#include "AutoWired.h"
#include "AutoWiredManager.h"

class HelloService;

class HelloMethod : public IMethod {
public:
  using Super = IMethod;
  inline static const std::string kMethod = "Hello";

  HelloMethod() = default;
  HelloMethod(std::shared_ptr<HelloService> service);
  virtual void Run(const std::string& message) override;

public:
  AUTO_WIRED_SERVICE(HelloService, service_)
};