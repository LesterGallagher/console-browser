#include <stdio.h>
#include <wchar.h>
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include "console.h"

int columns;
int rows;

void ansiconf()
{
    #if defined(_WIN32) || defined(WIN32)
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "INVALID_HANDLE_VALUE");
        exit(1);
    }
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        fprintf(stderr, "GetConsoleMode() failed");
        exit(1);
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        fprintf(stderr, "SetConsoleMode() failed");
        exit(1);
    }
    #endif
}

void console_dim() {
    #if defined(_WIN32) || defined(WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    #else
    columns = atoi(getenv("COLUMNS"));
    rows = atoi(getenv("ROWS"));
    #endif
}

int init() {
    ansiconf();
    console_dim();

    return 0;
}



