#include <libreborn/libreborn.h>
#include <symbols/minecraft.h>

#include "input-internal.h"
#include <mods/input/input.h>
#include <mods/creative/creative.h>

// Store Should Open Crafting Menu
static int should_open_crafting = 0;
void input_open_crafting() {
    should_open_crafting = 1;
}
static void _handle_open_crafting(unsigned char *minecraft) {
    if (should_open_crafting) {
        should_open_crafting = 0;

        // Set Screen
        if (!creative_is_restricted() || !(*Minecraft_isCreativeMode)(minecraft)) {
            unsigned char *screen = (unsigned char *) ::operator new(WORKBENCH_SCREEN_SIZE);
            ALLOC_CHECK(screen);
            screen = (*WorkbenchScreen)(screen, 0);
            (*Minecraft_setScreen)(minecraft, screen);
        }
    }
}

// Init
void _init_crafting() {
    input_run_on_tick(_handle_open_crafting);
}
