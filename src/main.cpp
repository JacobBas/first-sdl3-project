#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_video.h>

/**
 * Contains the main state for the running application
 */
struct SDLState {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

/**
 * Cleans up the application to ensure we are removing all allocated resources
 */
void cleanup(SDLState &state);

int main(int argc, char *argv[]) {
    // initializing the state of the application
    SDLState state;

    // initializing the video subsystem
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR, "Error", "Error initializing SDL3", nullptr
        );
        return 1;
    }

    // creating the window
    int width = 800;
    int height = 600;
    state.window = SDL_CreateWindow("SDL3 First Project", width, height, 0);
    if (!state.window) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", state.window
        );
        cleanup(state);
        return 1;
    }

    // create a renderer
    state.renderer = SDL_CreateRenderer(state.window, nullptr);
    if (!state.renderer) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            "Error creating renderer",
            state.window
        );
        cleanup(state);
        return 1;
    }

    // starting the game loop
    bool running = true;
    while (running) {
        // handling the different type of user input events to the game loop
        // currently only hanlding the type of event for quiting the event loop
        SDL_Event event{0};
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: {
                    running = false;
                }
            }
        }

        // perform our drawing commnands
        SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, 255);
        SDL_RenderClear(state.renderer);

        // swap buffers and present
        SDL_RenderPresent(state.renderer);
    }

    // quiting and cleaning up the SDL3 application
    cleanup(state);
    return 0;
}

void cleanup(SDLState &state) {
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();
}
