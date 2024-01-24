#pragma once

#include <windows.h>

namespace input {
    LRESULT CALLBACK KeyboardProc(int code, WPARAM wp, LPARAM lp) {
        if (code != HC_ACTION || wp != Plugin::instance().vk_code)
            return CallNextHookEx(nullptr, code, wp, lp);

        return 1;
    }
}
