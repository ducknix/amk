#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define MAX_CMD 128
#define AMKFILE "amkfile"

void trim(char* line) {
    char *start = line;
    char *end;

   while (*start == ' ' || *start == '\t')
        start++;

   if (*start == '\0') {
        *line = '\0';
        return;
    }

   end = start + strlen(start) - 1;

   while (end > start &&
          (*end == '\n' || *end == '\r' ||
           *end == ' '  || *end == '\t'))
        end--;

    *(end + 1) = '\0';

   if (start != line)
        memmove(line, start, strlen(start) + 1);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: %s <target>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(AMKFILE, "r");

    if (!file) {
        perror("Error: Unable to read the file 'amkfile'");
        return 1;
    }

    char line[MAXLINE];
    char target[MAX_CMD];
    int run = 0;
    int found = 0;

    snprintf(target, MAX_CMD, "@%s", argv[1]);

    while (fgets(line, MAXLINE, file)) {

        trim(line);

        if (strlen(line) == 0)
            continue;

        if (line[0] == '#')
            continue;

        if (line[0] == '@') {
            run = (strcmp(line, target) == 0);
            if (run)
                found = 1;
#69
            continue;
        }

        if (run) {
            printf("amk: %s\n", line);

            int code = system(line);

            if (code != 0) {
                fprintf(stderr,
                        "amkerror: Command execution failed: %s\n",
                        line);
                fclose(file);
                return code;
            }
        }
    }

    fclose(file);

    if (!found) {
        fprintf(stderr, "amkerror: Target not found: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
