/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:31:53 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/11 17:58:49 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

int error(char *str)
{
	int i = 0;

	while (str[i])
	{
		write (2, &str[i], 1);
		i++;
	}
	return (1);
}

int cd(char **argv, int wcont)
{
	if (wcont != 2)
		return (error("error: cd: bad arguments\n"));
	else if (chdir(argv[1]) == -1)
		return (error("error: cd: cannot change directory to "), error(argv[1]), error("\n"));
	return (0);
}

int executor(char **argv, char **env, int wcont)
{
	int fd[2];
	int status;
	int pid;
	int is_pipe = 0;

	if (argv[wcont] && strcmp(argv[wcont], "|") == 0)
		is_pipe = 1;
	if (is_pipe && pipe(fd) == -1)
		return(error("error: fatal\n"));
	pid = fork();
	if (pid == 0)
	{
		argv[wcont] = 0;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1] == -1)))
			return (error("error: fatal\n"));
		execve(*argv, argv, env);
		error("error: cannot execute ");
		error(*argv);
		return (error("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error("error: fatal"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char **env)
{
	int	ret_val = 0;
	(void)argc;
	int wcont = 0;

	while (*argv && *(argv + 1))
	{
		argv++;
		wcont = 0;
		while (argv[wcont] && strcmp(argv[wcont], "|") != 0 && strcmp(argv[wcont], ";") != 0)
			wcont++;
		if (strcmp(*argv, "cd") == 0)
			ret_val = cd(argv, wcont);
		else if (wcont > 0)
			ret_val = executor(argv, env, wcont);
		argv += wcont;
	}
	return (ret_val);
}
