// Anda tidak perlu melakukan perubahan pada file ini untuk memenuhi spek
// wajib. Namun, hal tersebut diperbolehkan.
#include "oop.hpp"

#include <map>
#include <iostream>
#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point start = high_resolution_clock::now();

double time_since_start()
{
    high_resolution_clock::time_point now = high_resolution_clock::now();
        return duration_cast<duration<double>>(now - start).count();
}

SDL_Window* sdlWindow;
std::map<std::string, SDL_Surface*> loadedSurfaces;
std::map<int, TTF_Font*> loadedFontSizes;
SDL_Surface* gScreenSurface = NULL;
MouseLocation mouseLocation;
bool quit = false;
std::set<SDL_Keycode> tappedKeys;
Uint8 mouseClickKeys;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {

        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdlWindow = SDL_CreateWindow( "ArkavQuarium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( sdlWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( sdlWindow );
        }
    }

    return success;
}

void close()
{
    for (auto const& x : loadedSurfaces)
    {
        SDL_FreeSurface( x.second );
    }

    for (auto const& x : loadedFontSizes)
    {
        TTF_CloseFont( x.second );
    }

    SDL_DestroyWindow( sdlWindow );
    sdlWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

int generateRandom(int lower, int upper)
  {
    return lower + (rand() % (upper - lower + 1));
  }

void draw_image(std::string filename, int x, int y) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];
    SDL_Rect dest;

    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, gScreenSurface, &dest);
}

// SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *renderTarget)
// {
// 	SDL_Texture *texture = nullptr;
// 	SDL_Surface *surface = IMG_Load(filePath.c_str());
// 	if(surface == NULL)
// 		std::cout << "Error" << std::endl;
// 	else
// 	{
// 		//SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 0));
//     Uint32 colorkey = SDL_MapRGB(surface->format, 0, 0, 0);
//     SDL_SetColorKey(surface, SDL_TRUE, colorkey);
//     texture = SDL_CreateTextureFromSurface(renderTarget, surface);
// 		if(texture == NULL)
// 			std::cout << "Error" << std::endl;
// 	}
//
// 	SDL_FreeSurface(surface);
//
// 	return texture;
// }

// void draw_gif(std::string filename, int x, int y){
//     int frameWidth, frameHeight;
//     int textureWidth, textureHeight;
//
//     SDL_Rect fishRect;
//     SDL_Rect position;
//     SDL_Texture *currentImage = nullptr;
//     SDL_Renderer *renderTarget = nullptr;
//     position.x = position.y = 150;
//     position.w = position.h = 40;
//
//     renderTarget = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//     currentImage = LoadTexture(filename, renderTarget);
//
//     SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
//     frameWidth = textureWidth / 10;
//     frameHeight = textureHeight / 5;
//
//     fishRect.x = fishRect.y = 0;
//     fishRect.w = frameWidth;
//     fishRect.h = frameHeight;
//
//     int frameTime = 0;
//     bool isRunning = true;
//     int cycle = 0;
//     while (isRunning && cycle < 3){
//       SDL_SetRenderDrawBlendMode(renderTarget, SDL_BLENDMODE_BLEND);
//       SDL_SetRenderDrawColor(renderTarget, 0,0,0,0);
//       frameTime++;
//       if (60 / frameTime == 4){
//         frameTime = 0;
//         fishRect.x += frameWidth;
//         if (fishRect.x >= textureWidth){
//           fishRect.x = 0;
//         }
//         cycle++;
//       }
//
//       SDL_RenderClear(renderTarget);
//       SDL_RenderCopy(renderTarget, currentImage, &fishRect, &position);
//       SDL_RenderPresent(renderTarget);
//     }
//
//     SDL_DestroyTexture(currentImage);
//     SDL_DestroyRenderer(renderTarget);
//
//     currentImage = nullptr;
//     renderTarget = nullptr;
// }

void draw_text(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (loadedFontSizes.count(font_size) < 1) {
        loadedFontSizes[font_size] = TTF_OpenFont(FONT_NAME, font_size);
    }

    TTF_Font* font = loadedFontSizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, gScreenSurface, &dest);
    SDL_FreeSurface(result);
}

void clear_screen() {
    SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 255, 255, 255));
}

void update_screen() {
    SDL_UpdateWindowSurface(sdlWindow);
}

void handle_input() {
    SDL_Event e;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while( SDL_PollEvent( &e ) != 0 )
    {
      switch (e.type) {
        case SDL_QUIT:
          quit = true;
        break;
        case SDL_KEYDOWN:
          tappedKeys.insert(e.key.keysym.sym);
        break;
        case SDL_MOUSEBUTTONDOWN:
          mouseClickKeys = e.button.button;
          mouseLocation.x = e.button.x;
          mouseLocation.y = e.button.y;
        break;
        case SDL_MOUSEBUTTONUP:
          mouseLocation.x = -1;
          mouseLocation.y = -1;
          mouseClickKeys = -127;
        break;
      }
    }
}

bool quit_pressed() {
    return quit;
}

const Uint8& get_mouse_clicks() {
    return mouseClickKeys;
}

const int& get_mouse_x(){
  return mouseLocation.x;
}

const int& get_mouse_y(){
  return mouseLocation.y;
}

const std::set<SDL_Keycode>& get_tapped_keys() {
    return tappedKeys;
}
