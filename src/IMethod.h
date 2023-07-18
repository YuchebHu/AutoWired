#pragma once

#include <memory>
#include <string>

class IService;
class IMethod {
public:
  inline static const std::string kMethodName = "IMethod";

  virtual void Run(const std::string& message) = 0;
  virtual void SetService(std::shared_ptr<IService>) = 0;
  virtual std::string GetServiceName() const = 0;
};

typedef void (IMethod::*ServiceSetter)(std::shared_ptr<IService>);