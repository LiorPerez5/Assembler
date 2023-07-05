#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		printf("Usage: ./%s input_file output_file", argv[0]);
		return -1;
	}

	char * line = NULL;
	FILE * input_file = fopen(argv[1], "r");
	// Validate the file has actually opened.
	FILE * output_file = fopen(argv[2], "w");
	// Validate the file has actually opened.
	size_t line_length = -1;
	char *token = NULL;
	char * colon_pos = NULL;
	char * label = NULL;

	while (getline(&line, &line_length, input_file) != -1)
	{
		token = strtok(line, " \t\n");
		colon_pos = strchr(token, ':');
		if (colon_pos != NULL)
		{
			label = malloc(colon_pos - token);
			// Check that malloc didn't fail
			strncpy(label, token, colon_pos - token);
			// Call validate_label that will check if the label has spaces (before or after)
			// Add address of label to symbols array
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{
				continue;
			}
		}

		if (strcmp(token, "mov") == 0)
		{
			// opcode = Call to parse_mov
		}
		else if (strcmp(token, "jmp") == 0)
		{
			// Call to parse_jmp
		}
		else if (strcmp(token, ".data") == 0)
		{
			// Call to parse_data
		}
		else if (strcmp(token, ".string") == 0)
		{
			// Call to parse_string
		}

		if (label != NULL)
		{
			
		}
	}
	

	return 0;
}
