#include <cstring>

#include "plugin.hpp"

extern "C" __declspec(dllexport)
void* CreateInterface(const char* name, InterfaceReturnStatus* rc) {
    void* p = (std::strcmp(name, interface_version_server_plugin_callbacks) == 0) ? &plugin : nullptr;
    if (rc)
        *rc = (p ? InterfaceReturnStatus::OK : InterfaceReturnStatus::FAILED);
    return p;
}
