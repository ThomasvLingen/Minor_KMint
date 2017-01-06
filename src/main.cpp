#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL2/SDL_events.h>
#include "SDL2/SDL_timer.h"
#include <time.h>
#include "RandomUtil.hpp"
#include "graph/BeeField.hpp"

const int screen_width = 600;
const int screen_height = 650;

int main()
{
    auto application = new FWApplication(0, 0, screen_width, screen_height);
    if (!application->GetWindow())
    {
        LOG("Couldn't create window...");
        return EXIT_FAILURE;
    }
    
    application->SetTargetFPS(60);
    application->SetColor(Color(255, 10, 40, 255));

    BeeField map;

    while (application->IsRunning())
    {
        application->StartTick();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                application->Quit();
                break;
            default:
                break;
            }
        }

        application->UpdateGameObjects();
        application->RenderGameObjects();
        application->EndTick();
        // For the background
        application->SetColor(Color(255, 255, 255, 255));
    }
        
    return EXIT_SUCCESS;
}
