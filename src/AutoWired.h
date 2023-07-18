#pragma once
#include <memory>
#include <string>

#include "AutoWiredManager.h"

#define BEAN(ClassName)

#define AUTO_WIRED_SERVICE(TypeName, Member)                                   \
  virtual void SetService(std::shared_ptr<IService> value) override {          \
    this->Member = std::static_pointer_cast<TypeName>(std::move(value));       \
  }                                                                            \
  virtual std::string GetServiceName() const override { return #TypeName; }    \
                                                                               \
private:                                                                       \
  std::shared_ptr<TypeName> Member;
