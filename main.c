#define _GNU_SOURCE
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	char	*station;
	float	temp;
}	t_data;

typedef struct s_dict
{
	char	*station;
	float	min;
	float	max;
	float	mean;
	int		count;
}	t_dict;

void	split_line(char *line, t_data *data, int i)
{
	data[i].station = strdup(strtok(line, ";"));
	data[i].temp = atof(strtok(NULL, ";"));
}

int open_file_and_store(t_data *data)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int i = 0;

	data = malloc(sizeof(t_data) * 100);
	if (!data)
	{	
		perror ("malloc() error");
		return (i);
	}
	fp = fopen ("measurements.txt", "r");
	if (fp == NULL)
	{
		free (data);
		perror ("open() error");
		return (i);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		split_line(line, data, i);
		printf("%d: %s", i + 1, line);
		i ++;
	}
	fclose (fp);
	if (line)
		free (line);
	return (i);
}

// void	calculate(t_data *data, int j)
// {
// 	t_list *list;


// }

int main (void)
{
	t_data *data = NULL;
	int 	len;

	len = 0;
	len = open_file_and_store(data);
	if (!data || len == 0)
		return (EXIT_FAILURE);
	int j = 0;
	while (j < len)
	{
		// calculate(data, j);
		printf("%s: %f\n", data[j].station, data[j].temp);
		j ++;
	}
	if (data)
		free (data);
	return (EXIT_SUCCESS);
}