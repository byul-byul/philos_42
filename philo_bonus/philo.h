/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:31:38 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/08 14:05:37 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

# define TRUE				1
# define FALSE				0
# define ERR_MSG_ENABLED	TRUE
# define MIN_ARG_COUNT		4
# define MAX_ARG_COUNT		5
# define MAX_PHILO_COUNT	200
# define MIN_MSEC_VALUE		60
# define MIN_USLEEP_TIME	21

# define SEM_NAME_00	"/fork_list"
# define SEM_NAME_01	"/updater"
# define SEM_NAME_02	"/notifier"
# define SEM_NAME_03	"/end_simulation"
# define SEM_NAME_04	"/finished_philo"

# define PHILO_MSG_00	"unknown action\n"
# define PHILO_MSG_01	"has taken a fork\n"
# define PHILO_MSG_02	"is eating\n"
# define PHILO_MSG_03	"is sleeping\n"
# define PHILO_MSG_04	"is thinking\n"
# define PHILO_MSG_05	"died\n"

# define ERR_MSG_00	"ERROR: unknown error.\n"
# define ERR_MSG_01 "ERROR: input validation: provide only 5-6 args.\n"
# define ERR_MSG_02	"ERROR: input validation: provide only digits.\n"
# define ERR_MSG_03	"ERROR: input validation: provide only INTs.\n"
# define ERR_MSG_04	"ERROR: data validation: \'philo_count\' must be >0.\n"
# define ERR_MSG_05	"ERROR: data validation: \'time_to_die\' must be >60.\n"
# define ERR_MSG_06	"ERROR: data validation: \'time_to_eat\' must be >60.\n"
# define ERR_MSG_07	"ERROR: data validation: \'time_to_sleep\' must be >60.\n"
# define ERR_MSG_08	"ERROR: data validation: \'eat_count\' must be >0.\n"
# define ERR_MSG_09	"ERROR: data initialization: malloc() failed.\n"
# define ERR_MSG_10	"ERROR: data initialization: sem_open() failed.\n"
# define ERR_MSG_11	"ERROR: simulation: fork() failed.\n"
# define ERR_MSG_12	"ERROR: simulation: pthread_create() failed.\n"

typedef struct s_data	t_data;

typedef enum e_error
{
	ERR_UNKNOWN,
	ERR_ARG_COUNT,
	ERR_ARG_DIGITS,
	ERR_ARG_INTS,
	ERR_DATA_PHILO_COUNT,
	ERR_DATA_DIE_TIME,
	ERR_DATA_EAT_TIME,
	ERR_DATA_SLEEP_TIME,
	ERR_DATA_EAT_COUNT,
	ERR_MALLOC_FAILED,
	ERR_SEMOPEN_FAILED,
	ERR_FORK_FAILED,
	ERR_P
}				t_error;

typedef enum e_philo_action
{
	PHILO_ACTION_UNKNOWN,
	PHILO_ACTION_TAKE_FORK,
	PHILO_ACTION_EAT,
	PHILO_ACTION_SLEEP,
	PHILO_ACTION_THINK,
	PHILO_ACTION_DIE
}				t_philo_action;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	pthread_t		thread;
	long long		last_meal_time;
	int				meal_count;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	int			has_allocated_memory;
	int			philo_count;
	int			eat_count;
	long long	die_time;
	long long	eat_time;
	long long	sleep_time;
	long long	simulation_start_time;
	t_philo		*philo_list;
	sem_t		*finished_philo;
	sem_t		*fork_list;
	sem_t		*notifier;
	sem_t		*updater;
	sem_t		*end_simulation;
}				t_data;

int			philo(int ac, char **av);
int			validate_arg(int ac, char **av);
int			parse_arg(int ac, char **av, t_data *data);
int			validate_data(int ac, t_data *data);
int			init_data(t_data *data);
void		pre_init_data(t_data *d);
int			do_simulation(t_data *d);
void		clean_data(t_data *d);
void		print_error(int error_code);
long long	get_current_timestamp(void);
int			ft_is_digits(const char *str);
int			ft_is_integer(const char *str);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
void		print_philo_action(t_philo *philo, long long tstamp, int msg_code);
void		custom_usleep(t_data *data, long long sleep_time);
void		rise_simulation_endflag(t_data *d);
int			is_simulation_endflag_rised(t_data *d);
int			is_all_philos_finished(t_data *d);
void		take_fork(t_philo *philo);
void		drop_fork(t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		*simulate_philo(void *arg);

#endif