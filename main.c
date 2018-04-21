#include <stdlib.h>
#include <stdio.h>

#include "config.h"
#include "console.h"

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    init();
}






