# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

typedef	struct	s_philo
{
	pthread_mutex_t	mutex;
}				t_philo;

void	*func1(void *arg)
{
	int	i;
	char	str[] = "hello world !";

	(void)arg;
	pthread_mutex_lock(&mutex);
	i = 0;
	while (i < 13)
	{

		fprintf(stderr, "%c", str[i]);
		usleep(100000);
		i++;
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "end 1\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

void	*func2(void *arg)
{
	int	i;
	char	str[] = "goodbye hell!";

	(void)arg;
	pthread_mutex_lock(&mutex);
	i = 0;
	while (i < 13)
	{
		fprintf(stderr, "%c", str[i]);
		usleep(100000);
		i++;
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "end 2\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	t_philo	philo;
	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);
		
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}