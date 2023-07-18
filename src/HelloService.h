#pragma once

#include <string>

#include "AutoWired.h"
#include "IService.h"

BEAN(HelloService)
class HelloService : public IService {
public:
  HelloService() = default;
  virtual ~HelloService() = default;
  void PrintMessage(const std::string& message);

private:
};