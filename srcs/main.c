#include "philo.h"

static	int	init_env(t_env *env)
{
	env->is_dead = 0;
	env->nb_feed = 0;
	env->start_time = 0;
	env->is_all_created = 0;
	init_philo(env);
	return (0);
}

static	int	check_arg(int argc, char **arg)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 4 || argc > 6)
		return (aie("Wrong number of arguments"));
	while (arg[i])
	{
		j = 0;
		while (arg[i] && arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (aie("Arguments must have only numeric characters"));
			++j;
		}
		if (is_uintovf(arg[0]) == YES)
			return (aie("An argument overflow"));
		++i;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env *));
	if (check_arg(argc, argv + 1))
		return (1);
	if (get_arg(&env, argv + 1))
	{
		aie("Can't get data's arguments");
		return (1);
	}
	if (init_env(&env))
		return (1);
	launch_philo(&env);
	return (0);
}
