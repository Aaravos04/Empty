#include<iostream>
using namespace std;

int main() {
    string Default = "\033[0m";
    string Bold = "\033[1m";
    string Faint = "\033[2m";
    string Italic = "\033[3m";
    string Underline = "\033[4m";
    string SlowBlink = "\033[5m";
    string RapidBlink = "\033[6m";
    string Swap = "\033[7m";    // Swap foreground and background colors.
    string Invisible = "\033[8m";
    string StrikeThrough = "\033[9m";

    string Black = "\033[30m";
    string Red = "\033[31m";
    string Green = "\033[32m";
    string Yellow = "\033[33m";
    string Blue = "\033[34m";
    string Magenta = "\033[35m";
    string Cyan = "\033[36m";
    string White = "\033[37m";
    string Color = "\033[38;5;<color>m";    // Color: 0 - 255
    string RGBA = "\033[38;2;<r>;<g>;<b>m"; // RGBA: 0 - 255

    string back_Black = "\033[40m";
    string back_Red = "\033[41m";
    string back_Green = "\033[42m";
    string back_Yellow = "\033[43m";
    string back_Blue = "\033[44m";
    string back_Magenta = "\033[45m";
    string back_Cyan = "\033[46m";
    string back_White = "\033[47m";
    string back_Color = "\033[48;5;<color_code>m";
    string back_RGBA = "\033[48;2;<r>;<g>;<b>m";

    // Example of combinations
    printf("\033[38;5;196m\033[48;5;18mRed text on blue background\033[0m\n");

    return 0;
}