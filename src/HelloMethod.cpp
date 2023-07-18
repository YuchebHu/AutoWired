#include "HelloMethod.h"

#include "HelloService.h"

HelloMethod::HelloMethod(std::shared_ptr<HelloService> service)
    : service_(std::move(service)) {}

void HelloMethod::Run(const std::string& message) {
  this->service_->PrintMessage(message);
}
