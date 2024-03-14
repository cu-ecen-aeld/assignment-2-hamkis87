#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    openlog(argv[0], LOG_PID | LOG_NDELAY, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <write_file> <write_str>", argv[0]);
        closelog();
        return 1;
    }

    char *write_file = argv[1];
    char *write_str = argv[2];
    FILE *file = fopen(write_file, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "ERROR: could not create %s", write_file);
        closelog();
        return 1;
    }

    if (fputs(write_str, file) == EOF) {
        syslog(LOG_ERR, "ERROR: could not write to %s", write_file);
        fclose(file);
        closelog();
        return 1;
    }
    fclose(file);

    syslog(LOG_DEBUG, "Writing %s to %s", write_str, write_file);

    closelog();

    return 0;
}
