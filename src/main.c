/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:51:55 by capapes           #+#    #+#             */
/*   Updated: 2024/08/03 15:53:40 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char *line = NULL;
    char *delimiter = NULL;

    // Define the delimiter
    delimiter = readline("Enter the delimiter: ");
    if (delimiter == NULL) {
        perror("Error reading delimiter");
        return 1;
    }

    printf("Enter your input (end with '%s'):\n", delimiter);

    // Initialize an array to hold the input lines
    char **lines = malloc(MAX_LINE_LENGTH * sizeof(char *));
	if (lines == NULL) {
    perror("Error allocating memory");
    free(delimiter); // Free memory allocated for delimiter
    return 1;
}

    int line_count = 0;

    // Read lines until the delimiter is encountered
    while (1) {
        line = readline("");
        if (line == NULL) {
            perror("Error reading line");
            free(delimiter);
            return 1;
        }

        // Check if the line matches the delimiter
        if (strcmp(line, delimiter) == 0) {
            free(line);
            break;
        }

        // Store the line in the array
        lines[line_count] = line;
        line_count++;
    }

    // Process and print the collected lines
    printf("Collected input:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]); // Free each line after printing
    }

    // Clean up
    free(delimiter);
	free(lines);
    return 0;
}
