/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/16 12:20:21 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup)
		dup = ft_strcpy(dup, src);
	return (dup);
}

static char	*ft_strrev(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(str);
	while (j > i)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return str;
}

char	*ft_itoa(int nbr)
{
	int i;
	int neg;
	char *tmp;

	i = 0;
	neg = 0;
	tmp = malloc(sizeof(char) * 12);
	if (tmp == NULL || nbr == 0)
		return ((nbr == 0) ? ft_strdup("0") : NULL);
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	while (nbr)
	{
		tmp[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		tmp[i] = '-';
	return ft_strrev(tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

static int	init_individual_semaphores(t_data *d)
{
	int		i;
	char	*itoa;
	char	*sem_name;

	i = -1;
	while (++i < d->philo_count)
	{
		itoa = ft_itoa(i);
		if (!itoa)
			return (ERR_MALLOC_FAILED);
		sem_name = ft_strjoin(SEM_NAME_01, itoa);
		if (!sem_name)
			return (free(itoa), ERR_MALLOC_FAILED);
		sem_unlink(sem_name);
		d->philo_list[i].updater = sem_open(sem_name, O_CREAT, S_IWUSR, 1);
		if (SEM_FAILED == d->philo_list[i].updater)
			return (free(itoa), free(sem_name), ERR_SEMOPEN_FAILED);
		sem_unlink(sem_name);
		free(itoa);
		free(sem_name);
	}
	return (0);
}

static int	init_program_semaphores(t_data *d)
{
	d->fork_list = sem_open(SEM_NAME_00, O_CREAT, S_IWUSR, d->philo_count);
	if (SEM_FAILED == d->fork_list)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_00);
	d->global_updater = sem_open(SEM_NAME_01, O_CREAT, S_IWUSR, d->philo_count);
	if (SEM_FAILED == d->global_updater)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_01);
	d->notifier = sem_open(SEM_NAME_02, O_CREAT, S_IWUSR, 1);
	if (SEM_FAILED == d->notifier)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_02);
	d->end_simulation = sem_open(SEM_NAME_03, O_CREAT, S_IWUSR, 0);
	if (SEM_FAILED == d->end_simulation)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_03);
	d->finished_philo = sem_open(SEM_NAME_04, O_CREAT, S_IWUSR, d->philo_count);
	if (SEM_FAILED == d->finished_philo)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_04);
	d->death_message = sem_open(SEM_NAME_05, O_CREAT, S_IWUSR, 0);
	if (SEM_FAILED == d->death_message)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_05);
	return (init_individual_semaphores(d));
}

static void	init_philo(t_data *d, int i)
{
	d->philo_list[i].id = i + 1;
	d->philo_list[i].data = d;
	d->philo_list[i].meal_count = 0;
}

void	pre_init_data(t_data *d)
{
	d->has_allocated_memory = 0;
	d->fork_list = SEM_FAILED;
	d->global_updater = SEM_FAILED;
	d->notifier = SEM_FAILED;
	d->end_simulation = SEM_FAILED;
	d->finished_philo = SEM_FAILED;
}

int	init_data(t_data *d)
{
	int	error_code;
	int	i;

	i = -1;
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	if (NULL == d->philo_list)
		return (ERR_MALLOC_FAILED);
	error_code = init_program_semaphores(d);
	if (0 != error_code)
		return (free(d->philo_list), error_code);
	d->has_allocated_memory = 1;
	while (++i < d->philo_count)
		init_philo(d, i);
	return (0);
}
