#include "ft_printf.h"

void log_result(const char *test_name, const char *result) {
    char filename[100];

    snprintf(filename, sizeof(filename), "%s_result.txt", test_name);

    printf("Resultado de la prueba '%s': %s\n", test_name, result);
}

int redirect_stdout_to_file(const char *filename) {
    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1)
        return -1;

    int file_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (file_fd == -1)
        return -1;

    if (dup2(file_fd, STDOUT_FILENO) == -1) {
        close(file_fd);
        return -1;
    }

    close(file_fd);
    return saved_stdout;
}

void restore_stdout(int saved_stdout) {
    if (saved_stdout != -1) {
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
    }
}
