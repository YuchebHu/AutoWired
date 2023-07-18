#include <iostream>
#include <memory>
#include <string>

#include "AutoWiredManager.h"
#include "HelloMethod.h"
#include "HelloService.h"
#include "MethodFactory.h"

int main(int, char**) {
  std::string serviceName = "HelloService";
  AutoWiredManager::AddService(
      "HelloService",
      std::make_shared<HelloService>());

  auto helloMethod = MethodFactory::Get()->CreateMethod<HelloMethod>();

  helloMethod->Run("Hello AutoWired");
  return 0;
}
