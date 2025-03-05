/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:31:38 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/05 14:48:29 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

# define TRUE				1
# define FALSE				0
# define ERR_MSG_ENABLED	TRUE
# define MIN_ARG_COUNT		4
# define MAX_ARG_COUNT		5
# define MAX_PHILO_COUNT	200
# define MIN_MSEC_VALUE		60

# define ERR_MSG_00	"Error\n"

# define ERR_MSG_01	"ERROR: \
input validation failed: please provide 5-6 args.\n"

# define ERR_MSG_02	"ERROR: \
input validation failed: please provide only digits.\n"

# define ERR_MSG_03	"ERROR: \
input validation failed: please provide only INTs.\n"

# define ERR_MSG_04	"ERROR: \
data validation failed: \'philo_count\' should be >0.\n"

# define ERR_MSG_05	"ERROR: \
data validation failed: \'time_to_die\' should be >0.\n"

# define ERR_MSG_06	"ERROR: \
data validation failed: \'time_to_eat\' should be >0.\n"

# define ERR_MSG_07	"ERROR: \
data validation failed: \'time_to_sleep\' should be >0.\n"

# define ERR_MSG_08	"ERROR: \
data validation failed: \'eat_count\' should be >0.\n"

# define ERR_MSG_09	"ERROR: \
data initialization failed: malloc() failed.\n"

# define ERR_MSG_10	"ERROR: \
data initialization failed: pthread_mutex_init() failed.\n"

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_fork		*left;
	t_fork		*right;
}				t_philo;

typedef struct s_data
{
	int			has_allocated_memory;
	int			has_active_mutex;
	int			philo_count;
	int			eat_count;
	long long	die_time;
	long long	eat_time;
	long long	sleep_time;
	t_philo		*philo_list;
	t_fork		*fork_list;
}				t_data;

void		philo(int ac, char **av);
int			validate_arg(int ac, char **av);
int			parse_arg(int ac, char **av, t_data *data);
int			validate_data(int ac, t_data *data);
int			init_data(t_data *data);
int			do_simulation(t_data *d);
void		destroy_mutex_list(t_data *d, int size);
void		clean_data(t_data *d);
void		print_error(int error_code);
int			ft_is_digits(const char *str);
int			ft_is_integer(const char *str);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);

#endif