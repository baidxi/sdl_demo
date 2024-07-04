#include <iostream>

#include "sdl_ui.h"

int main() {
    sdl_ui ui;

    if (!ui.is_ready())
        return -1;

    ui.startup();

    while(ui.is_running()) {
        ui.update();
        ui.render();
    }

    return 0;
}
