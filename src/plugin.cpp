#include "plugin.h"

#include <string>
#include <euroscope/EuroScopePlugIn.h>
#include "input.h"

// Scan code for the physical key on the keyboard.
const UINT SCAN_CODE = 0x29;

static Plugin* INSTANCE = nullptr;

Plugin& Plugin::instance() {
    if (!INSTANCE) {
        INSTANCE = new Plugin();
    }
    return *INSTANCE;
}

void Plugin::reset() {
    if (INSTANCE) {
        delete INSTANCE;
        INSTANCE = nullptr;
    }
}

Plugin::Plugin()
        : EuroScopePlugIn::CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
                                   PLUGIN_NAME.c_str(),
                                   PLUGIN_VERSION.c_str(),
                                   PLUGIN_AUTHOR.c_str(),
                                   PLUGIN_COPYRIGHT.c_str()) {

    DWORD thread_id = GetCurrentThreadId();

    // Get the virtual key code for the physical key based on the current keyboard layout.
    HKL layout = GetKeyboardLayout(thread_id);
    this->vk_code = MapVirtualKeyExA(SCAN_CODE, MAPVK_VSC_TO_VK_EX, layout);
    if (this->vk_code == 0) {
        this->debug("Failed to get virtual key code key.");
        return;
    }

    // Install keyboard event hook.
    this->hook = SetWindowsHookExA(WH_KEYBOARD, input::KeyboardProc, nullptr, thread_id);
    if (this->hook == nullptr) {
        this->debug("Failed to install keyboard event hook.");
    }
}


Plugin::~Plugin() {
    UnhookWindowsHookEx(this->hook);
}

void Plugin::debug(const std::string& msg) {
    this->DisplayUserMessage(
            PLUGIN_NAME.c_str(),
            PLUGIN_NAME.c_str(),
            msg.c_str(),
            true,
            true,
            false,
            true,
            false
    );
}
