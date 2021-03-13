#include <Windows.h>

#include <sdk/game_movement.hpp>

#include "plugin.hpp"
#include "game_movement.hpp"
#include "prediction.hpp"

bool Plugin::load(create_interface_fn ef, create_interface_fn sf) {
    auto cf = reinterpret_cast<create_interface_fn>(GetProcAddress(GetModuleHandleA("client.dll"), "CreateInterface"));
    game_movement = static_cast<GameMovement*>(cf(interface_version_game_movement, nullptr));

    MEMORY_BASIC_INFORMATION mbi;
    void* vtable = *reinterpret_cast<void**>(game_movement);
    VirtualQuery(vtable, &mbi, sizeof(mbi));

    VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_READWRITE, &mbi.Protect);
    CheckJumpButton::original = reinterpret_cast<CheckJumpButton::T**>(vtable)[CheckJumpButton::index];

    enable_prediction();

    return true;
}

void Plugin::unload() {

}

void Plugin::pause() {

}

void Plugin::unpause() {

}

const char* Plugin::get_plugin_description() {
    return "bhop predict";
}

void Plugin::level_init(const char* map_name) {

}

void Plugin::server_activate(Edict* edict_list, int edict_count, int max_clients) {

}

void Plugin::game_frame(bool is_simulating) {

}

void Plugin::level_shutdown() {

}

void Plugin::client_active(Edict* e) {

}

void Plugin::client_disconnect(Edict* e) {

}

void Plugin::client_put_in_server(Edict* e, const char* name) {

}

void Plugin::set_command_client(int index) {

}

void Plugin::client_settings_changed(Edict* e) {

}

PluginResult Plugin::client_connect(bool* allow_connect, Edict* e, const char* name, const char* address, char* reject, int max_reject_len) {
    return PluginResult::CONTINUE;
}

PluginResult Plugin::client_command(Edict* e, const Command& args) {
    return PluginResult::CONTINUE;
}

PluginResult Plugin::network_id_validated(const char* name, const char* network_id) {
    return PluginResult::CONTINUE;
}

void Plugin::on_query_cvar_value_finished(int cookie, Edict* e, QueryCvarValueStatus status, const char* name, const char* value) {

}

void Plugin::on_edict_allocated(Edict* e) {

}

void Plugin::on_edict_freed(const Edict* e) {

}
