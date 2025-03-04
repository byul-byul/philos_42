/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:31:38 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 12:13:01 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

# define TRUE				1
# define FALSE				0
# define ERR_MSG_ENABLED	TRUE
# define MIN_ARG_COUNT		4
# define MAX_ARG_COUNT		5

# define ERR_MSG_00	"Error\n"
# define ERR_MSG_01	"ERROR: incorrect arg count.\nPlease provide 5 or 6 args\n"
# define ERR_MSG_02	"ERROR: incorrect arg value.\nPlease provide only digits.\n"
# define ERR_MSG_03	"ERROR: incorrect arg value.\nPlease provide only integers.\n"
# define ERR_MSG_04	"ERROR: argument parsing failed: number is NOT integer.\n"
# define ERR_MSG_05	"ERROR: argument parsing failed: number is duplicate.\n"

typedef struct s_data
{
	int			philo_count;
	int			eat_count;
	long long	die_time;
	long long	eat_time;
	long long	sleep_time;
}				t_data;

void		philo(int ac, char **av);
int			validate_arg(int ac, char **av);
int			parse_arg(int ac, char **av, t_data *data);
void		print_error(int error_code);
int			ft_is_digits(const char *str);
int			ft_is_integer(const char *str);
int			ft_atoi(char *str);
long long	ft_atoll(char *str);

#endif