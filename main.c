#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define MAX_CMD 128
#define AMKFILE "amkfile"

void trim(char* line) {
    char *end;
    while (*line == ' ' || *line == '\t') line++;

    end = line + strlen(line) - 1;
    while (end > line && (*end == '\n' || *end == '\r' ||*end == ' ')) *end-- = '\0';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
	fprintf(stderr, "usage: %s <commands>\n", argv[0]);
	return 1;
    }

    FILE *file = fopen(AMKFILE, "r");

    if (!file) {
	perror("Error: Unable to read the file 'amkfile'.\n");
	return 1;
    }

    char line[MAXLINE];
    char cmd[MAX_CMD];
    char target[MAX_CMD];
    int run = 0;

    snprintf(target, MAX_CMD, "@%s", argv[1]);

    while(fgets(line, MAXLINE, file)) {
	trim(line);

	
	if (*line == '\n') continue;
	if (line[0] == '#' || strlen(line) == 0) continue;

	if (line[0] == '@') {
	    run = strcmp(line, target) == 0;
	    continue;
	}

	if (run) {
	    
	    printf("amk: %s\n", line);
	    
	    int code = system(line);
	    if (code != 0) {
		fprintf(stderr, "amkerror: Command execution failed: %s\n", line);
		fclose(file);
		return code;
	    }
	}
    }

    fclose(file);
    return 0;
}




# 69
