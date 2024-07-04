//
// Created by juno on 24-7-4.
//

#ifndef SDL_UI_SDL_UI_H
#define SDL_UI_SDL_UI_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

class sdl_ui {
private:
    const SDL_VideoInfo *info;
    bool ready;
    bool running;
    struct gui_surfaces {
        SDL_Surface *screen;
    }surfaces{};
public:
    sdl_ui();
    ~sdl_ui();
    [[nodiscard]] bool is_ready() const {
        return ready;
    }

    void update();

    [[nodiscard]] bool is_running() const {
        return running;
    }

    void startup() {
        running = true;
    }

    void render();
};


#endif //SDL_UI_SDL_UI_H
