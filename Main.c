#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
 
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    char Line[256];
    while (fgets(Line, sizeof(Line), file)) {
        if (strncmp(Line, "log[\"", strlen("log[\"")) == 0) {
            char* Arg = Line + strlen("log[\"");
            if (Arg[strlen(Arg)-4] =! "\"];") {}
            
            printf("%s\n", Arg);
		} else {
            printf("Syntax error at: %s\n", Line);
            return -1;
        }
    }
 
    fclose(file);
    return 0;
}