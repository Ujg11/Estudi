/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:31:53 by ojimenez          #+#    #+#             */
/*   Updated: 2024/03/08 13:31:53 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int print_error(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int cd(char **argv, int i, int w_cont)
{
	if (w_cont != 2)
		return (print_error("error: cd: bad arguments\n"));
	else if (!chdir(argv[i]))
	{
		print_error("error: cd: cannot change directory to ");
		print_error(argv[i]);
		return (print_error("\n"));
	}
	return (0);
}

int executor(char **argv, int i, int wcont, char **env)
{
	int fd[2];
	int ret_val;
	int is_pipe = 0;
	int pid;
	int j = 0;
	char *arguments[wcont + 1];

	while (j < wcont)
	{
		arguments[j] = argv[i + j];
		j++;
	}
    arguments[wcont] = NULL;
	if (argv[i] && strcmp(argv[i], "|") == 0)
		is_pipe = 1;
	if (is_pipe)
	{
		if (pipe(fd) == -1)
			return (print_error("error: fatal\n"));
	}
	pid = fork();
	if (pid == 0) //En el fill
	{

		if (is_pipe && dup2(fd[OUT], STDOUT_FILENO) == -1)
			return (print_error("error: fatal\n"));
		if (close(fd[IN]) == -1 || close(fd[OUT]) == -1)
			return (print_error("error: fatal\n"));
		execve(arguments[0], arguments, env);
		print_error("error: cannot execute ");
		print_error(arguments[0]);
		return (print_error("\n"));
	}
	else // En el pare
	{
		waitpid(pid, &ret_val, 0);
		if (is_pipe && (dup2(fd[IN], STDIN_FILENO) == -1 || close(fd[IN] == -1) || close(fd[OUT]) == -1))
			return (print_error("error: fatal\n"));
		return (WIFEXITED(ret_val) && WEXITSTATUS(ret_val));
	}
}

int main(int argc, char *argv[], char **env)
{
	int	i = 0;
	int w_cont = 0;
	int ret_val = 0;
	
	if (argc > 1)
	{
		while (argv[i] && argv[i + 1])
		{
			w_cont = 0;
			while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
				w_cont++;
			if (strcmp(argv[i], "cd"))
				ret_val = cd(argv, i + 1, w_cont);
			else if (w_cont > 0)
				ret_val = executor(argv, i + 1, w_cont, env);
		}
	}
	return (ret_val);
}
