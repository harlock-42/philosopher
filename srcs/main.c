#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
/*
static	int	check_arg(int argc, char **arg)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2 || argc > 4)
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
*/

void	*func1(void *arg)
{
	int	i;
	char	str[] = "hello world !";

	(void)arg;
	i = 0;
	pthread_cond_wait(&cond, &mutex);
	while (i < 13)
	{

		fprintf(stderr, "%c", str[i]);
		usleep(100000);
		i++;
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "end 1\n");
	pthread_exit(NULL);
}
void	*func2(void *arg)
{
	int	i;
	char	str[] = "goodbye hell!";

	(void)arg;
	i = 0;
	while (i < 13)
	{
		fprintf(stderr, "%c", str[i]);
		usleep(100000);
		i++;
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "end 2\n");
	pthread_cond_signal(&cond);
	pthread_exit(NULL);
}

int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	ft_bzero(&env, sizeof(t_env *));
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);
		
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	/*
	if (check_arg(argc, argv + 1))
		return (1);
	if (get_arg(&env, argv + 1))
	{
		aie("Can't get data's arguments");
		return (1);
	}
	*/

	return (0);
}