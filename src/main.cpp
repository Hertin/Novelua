#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <selene.h>

int main(int argc, char *argv[]) {
    // Lua test
    sel::State luaState{true};
    luaState["message"] = "Hello world!";
    std::string message = luaState["message"];
    std::cout << "Message: " << message << std::endl;

    // SDL test
    SDL2pp::SDL sdl(SDL_INIT_VIDEO);
    SDL2pp::SDLTTF ttf;
    SDL2pp::SDLImage img;
    SDL2pp::Window win("Hello world", 0, 0, 800, 600, SDL_WINDOWPOS_UNDEFINED);
    for (int i = 0; i < 10; ++i) {
        luaState["number"] = i;
        std::cout << "Number: " << int(luaState["number"]) << std::endl;
        SDL_Delay(1000);
    }

    luaState("print(\"Goodbye from Lua!\")");
}
