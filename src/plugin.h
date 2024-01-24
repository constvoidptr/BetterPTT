#pragma once

#include <euroscope/EuroScopePlugIn.h>
#include <string>

const std::string PLUGIN_NAME = "BetterPTT";
const std::string PLUGIN_VERSION = "1.0.0";
const std::string PLUGIN_AUTHOR = "constvoidptr";
const std::string PLUGIN_COPYRIGHT = "(c) 2023-2024, MIT License";

class Plugin : public EuroScopePlugIn::CPlugIn {
public:
    static Plugin& instance();
    static void reset();
    Plugin(const Plugin&) = delete;
    Plugin& operator=(const Plugin&) = delete;

    void debug(const std::string& msg);

    BYTE vk_code;
private:
    Plugin();
    ~Plugin() override;

    HHOOK hook;
};
