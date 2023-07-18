#include "AutoWiredManager.h"

#include <string>
#include <unordered_map>

#include "IService.h"

static std::unordered_map<std::string, std::shared_ptr<IService>> g_services_;
static std::unordered_map<std::string, ServiceSetter> g_service_setter;

void AutoWiredManager::AddService(
    const std::string& name,
    std::shared_ptr<IService> service) {
  g_services_.emplace(name, std::move(service));
}

std::shared_ptr<IService>
AutoWiredManager::GetService(const std::string& name) {
  if (auto itr = g_services_.find(name); itr != g_services_.end()) {
    return itr->second;
  }
  return nullptr;
}

void AutoWiredManager::AddServiceSetter(
    const std::string& method_name,
    ServiceSetter service_setter) {
  g_service_setter.emplace(method_name, service_setter);
}

ServiceSetter AutoWiredManager::GetServiceSetter(const std::string& name) {
  if (auto itr = g_service_setter.find(name); itr != g_service_setter.end()) {
    return itr->second;
  }
  return nullptr;
}
