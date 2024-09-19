#include <conio.h>

char* screen = (char*)(1024);
unsigned char* color = (unsigned char*)(55296);

char* joystick = (char*)(56320);

#define block_char 224
#define empty_char 96

int main() {
    unsigned short i;
    unsigned short placement_index;
    unsigned short delay;
    *((unsigned char*)53281) = 0;
    clrscr();
    delay = 0;
    placement_index = 0;
    screen[placement_index] = block_char;
    color[placement_index] = 2;
    for (;;) {
        screen[placement_index] = block_char;
        color[placement_index] = 2;
        if ((*joystick & 0x01) == 0) {
            screen[placement_index] = empty_char;
            color[placement_index] = 0;
            placement_index -= 40;
            screen[placement_index] = block_char;
            color[placement_index] = 2;
        }
        if ((*joystick & 0x02) == 0) {
            screen[placement_index] = empty_char;
            color[placement_index] = 0;
            placement_index += 40;
            screen[placement_index] = block_char;
            color[placement_index] = 2;
        }
        if ((*joystick & 0x04) == 0) {
            screen[placement_index] = empty_char;
            color[placement_index] = 0;
            placement_index -= 1;
            screen[placement_index] = block_char;
            color[placement_index] = 2;
        }
        if ((*joystick & 0x08) == 0) {
            screen[placement_index] = empty_char;
            color[placement_index] = 0;
            placement_index += 1;
            screen[placement_index] = block_char;
            color[placement_index] = 2;
        }
        if ((*joystick & 0x10) == 0) {
            screen[placement_index] = block_char;
            color[placement_index] = 7;
        }

        for (i = 0; i < 960; i++) {
            if (color[i] == 7 && screen[i] == block_char) {
                if (screen[i + 40] != block_char) {
                    screen[i + 40] = block_char;
                    color[i + 40] = 7;
                    screen[i] = empty_char;
                    color[i] = 0;
                } else if (screen[i + 39] != block_char) {
                    screen[i + 39] = block_char;
                    color[i + 39] = 7;
                    screen[i] = empty_char;
                    color[i] = 0;
                } else if (screen[i + 41] != block_char) {
                    screen[i + 41] = block_char;
                    color[i + 41] = 7;
                    screen[i] = empty_char;
                    color[i] = 0;
                }
            }
        }
    }

    return 0;
}