#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 64

char *read_buffer(int fd, char *buffer, char **jump)
{
    ssize_t bytes_read = 0;

    if (*jump)
    {
        // Si hay contenido en jump, copiarlo a r y limpiar jump
        char *temp = *jump;
        *jump = NULL;
        return temp;
    }

    // Si no hay contenido en jump, realizar una nueva lectura
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return NULL;

    buffer[bytes_read] = '\0'; // Asegurar que el buffer esté terminado con nulo
    return strdup(buffer);
}

char *read_line(int fd, char *buffer, char **jump)
{
    char *r = read_buffer(fd, buffer, jump);
    if (!r)
        return NULL;

    char *newline_pos = strchr(r, '\n');
    while (!newline_pos)
    {
        // Seguir leyendo hasta encontrar un salto de línea
        char *next_chunk = read_buffer(fd, buffer, jump);
        if (!next_chunk)
            break;

        char *temp = r;
        r = malloc(strlen(temp) + strlen(next_chunk) + 1);
        strcpy(r, temp);
        strcat(r, next_chunk);
        free(temp);

        newline_pos = strchr(r, '\n');
    }

    return r;
}

char *trim_until_newline(char *str)
{
    if (str)
    {
        char *newline_pos = strchr(str, '\n');
        if (newline_pos)
        {
            *newline_pos = '\0'; // Truncar la cadena hasta el primer salto de línea
        }
    }

    return str;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static char *jump = NULL;
    char *r = NULL;

    // Paso 1
    r = read_line(fd, buffer, &jump);

    // Paso 2
    if (jump == NULL)
    {
        // Si no hay contenido en jump, realizar una nueva lectura para la próxima línea
        jump = read_buffer(fd, buffer, &jump);
    }

    // Paso 3
    r = trim_until_newline(r);

    return r;
}

int main()
{
    int fd = open("a.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }

    close(fd);

    return 0;
}

