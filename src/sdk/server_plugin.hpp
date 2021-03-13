#pragma once

#include "interfaces.hpp"

class Edict;
class Command;
enum class QueryCvarValueStatus;

enum class PluginResult {
    CONTINUE,
    OVERRIDE,
    STOP
};

static const char* interface_version_server_plugin_callbacks = "ISERVERPLUGINCALLBACKS003";

class IServerPluginCallbacks {
public:
    virtual bool load(create_interface_fn ef, create_interface_fn sf) = 0;
    virtual void unload() = 0;
    virtual void pause() = 0;
    virtual void unpause() = 0;
    virtual const char* get_plugin_description() = 0;
    virtual void level_init(const char* map_name) = 0;
    virtual void server_activate(Edict* edict_list, int edict_count, int max_clients) = 0;
    virtual void game_frame(bool is_simulating) = 0;
    virtual void level_shutdown() = 0;
    virtual void client_active(Edict* e) = 0;
    virtual void client_disconnect(Edict* e) = 0;
    virtual void client_put_in_server(Edict* e, const char* name) = 0;
    virtual void set_command_client(int index) = 0;
    virtual void client_settings_changed(Edict* e) = 0;
    virtual PluginResult client_connect(bool* allow_connect, Edict* e, const char* name, const char* address, char* reject, int max_reject_len) = 0;
    virtual PluginResult client_command(Edict* e, const Command& args) = 0;
    virtual PluginResult network_id_validated(const char* name, const char* network_id) = 0;
    virtual void on_query_cvar_value_finished(int cookie, Edict* e, QueryCvarValueStatus status, const char* name, const char* value) = 0;
    virtual void on_edict_allocated(Edict* e) = 0;
    virtual void on_edict_freed(const Edict* e) = 0;
};
