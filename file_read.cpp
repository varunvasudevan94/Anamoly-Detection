#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
int count;
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    
    count += last_comma < (a_str + strlen(a_str) - 1);

  
    count++;

    result = (char **)malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}









int main(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 
	stream = fopen("creditcard.csv", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);
 
	while ((read = getline(&line, &len, stream)) != -1) {
		char **result=NULL;
		 //printf("Retrieved line of length %du :\n", str_split(line, ',',result));
		result=str_split(line, ',');
		if (result[30][1]=='1')
			printf("Hello\n");
		//printf("%c\n",result[30][1]);			
		//printf("%s", line);
	}
 
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
