#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define FONTSET_SIZE 80
#define RAM_SIZE 4096
#define NUM_KEYS 16
#define NUM_REGS 16
#define STACK_SIZE 16
#define SCALE 8
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32
#define WINDOW_WIDTH SCREEN_WIDTH *SCALE
#define WINDOW_HEIGHT SCREEN_HEIGHT *SCALE

static const uint8_t FONT_SET[FONTSET_SIZE] = {
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80 // F
};

/// Initialize a new Chip 8 Core
struct Core *new_core(void);
/// Starts the next cycle in the CPU
void tick(struct Core *state);
/// Draws the screen buffer onto the window
void draw_screen(struct Core *state);
/// Load a game rom into the core's RAM
void load_rom(struct Core *state, FILE *file);
/// Get the current screen buffer
bool *get_screen(struct Core *state);
