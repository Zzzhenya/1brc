#ifndef STRUCTS_H
# define STRUCTS_H

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

#endif