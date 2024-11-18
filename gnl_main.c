/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 08:12:02 by oscamurg          #+#    #+#             */
/*   Updated: 2024-11-15 08:12:02 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("story.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void    read_all_lines(int fd, const char *filename)
{
    char    *line;
    int     line_count = 0;

    printf("\nLeyendo archivo: %s (fd: %d)\n", filename, fd);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea %d: %s", ++line_count, line);
        free(line);
    }
    printf("Total de líneas leídas: %d\n", line_count);
}

int main(void)
{
    int     fd1, fd2, fd3;
    char    *line;

    // Abrir archivos
    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    fd3 = open("test3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("Error al abrir uno o más archivos\n");
        return (1);
    }

    printf("=== Lectura alternada de archivos ===\n");
    
    // Leer primeras líneas de cada archivo
    for (int i = 0; i < 2; i++)
    {
        // printf("\n--- Ronda %d ---\n", i + 1);
        
        line = get_next_line(fd1);
        printf("Archivo 1: línea %d: %s", i + 1, line);
        free(line);

        line = get_next_line(fd2);
        printf("Archivo 2: línea %d: %s", i + 1, line);
        free(line);

        line = get_next_line(fd3);
        printf("Archivo 3: línea %d: %s", i + 1, line);
        free(line);
    }

    printf("\n=== Lectura completa de cada archivo ===\n");
    
    // Volver al inicio de cada archivo
    lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);
    lseek(fd3, 0, SEEK_SET);

    // Leer cada archivo completo
    read_all_lines(fd1, "test1.txt");
    read_all_lines(fd2, "test2.txt");
    read_all_lines(fd3, "test3.txt");

    // Cerrar archivos
    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}