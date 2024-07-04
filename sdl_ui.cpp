//
// Created by juno on 24-7-4.
//

#include <iostream>

#include "sdl_ui.h"

sdl_ui::sdl_ui():
info(nullptr),
ready(false),
running(false)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK)) {
        std::cerr<<"SDL Init err:"<<errno<<std::endl;
        return;
    }

    int expected_file_format_support = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(expected_file_format_support) & expected_file_format_support) != expected_file_format_support) {
        std::cerr<<"SDL Img init err:"<<errno<<std::endl;
        goto quit_sdl;
    }

    if (TTF_Init()) {
        std::cerr<<"SDL TTF init err:"<<errno<<std::endl;
        goto quit_img;
    }

    SDL_ShowCursor(SDL_DISABLE);

    info = SDL_GetVideoInfo();

    if (!info) {
        std::cerr<<"SDL GetVideoInfo err"<<std::endl;
        goto quit_ttf;
    }

    surfaces.screen = SDL_SetVideoMode(640, 320, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (!surfaces.screen) {
        std::cerr<<"SetVideoMode err"<<std::endl;
        goto quit_ttf;
    }

    ready = true;

    return;
quit_ttf:
    TTF_Quit();
quit_img:
    IMG_Quit();
quit_sdl:
    SDL_Quit();
}

sdl_ui::~sdl_ui()
{
    if (ready) {
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}

void sdl_ui::update()
{
    SDL_Event event;

    if (!ready)
        return;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

void sdl_ui::render() {

}
