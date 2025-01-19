/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:28 by ajelloul          #+#    #+#             */
/*   Updated: 2025/01/14 11:27:27 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

// ********************** dup2 ************************** 

// int main (void)
// {
// 	int fd;

// 	fd = open("file.txt", O_CREAT | O_RDWR, 0644);
// 	if (fd == -1)
// 	{
// 		perror("faild");
// 	}
// 	printf ("file.txt fd  : %d\n", fd);

// 	int fd_dup = dup2(fd, 1);   //    int dup2(int oldfd, int newfd);

// 	if (fd_dup == -1)
// 	{
// 		perror ("faild");
// 	}

// 	printf ("after using dup2 : %d", fd_dup);
// 	printf ("\nprint from the file\n");

// 	return (0);
// }


// ********************** dup ************************** 


// int main (void)
// {
// 	int fd;

// 	fd = open("file.txt", O_CREAT | O_RDWR, 0644);
// 	if (fd == -1)
// 	{
// 		perror("faild");
// 	}
// 	printf ("file.txt fd  : %d\n", fd);

// 	int fd_dup = dup(fd);   //    int dup(int oldfd);

// 	if (fd_dup == -1)
// 	{
// 		perror ("faild");
// 	}

// 	printf ("after using dup : %d", fd_dup);
	
// 	return (0);
// }


// ******************   access Function   ******************  

	/*  int access (const char *pathname, int mode);  */

	/*	F_OK flag: Used to check for the existence of a file.
		R_OK flag: 						read permission bit.
		W_OK flag: 						write permission bit.
		X_OK flag: 						execute permission bit.	*/

// int main (void)
// {
// 	int acc;

// 	acc = access ("usr/local/munki", F_OK | X_OK);

// 	printf ("\n%d", acc);
	
// 	// 0 = access 
// 	// -1 = does not have permissions

// 	return (0);
// }



// ******************  execve()  Function   ******************  



// int main (int ac, char **av, char **env)
// {
// 	/*	int execve(const char *pathname, char *const argv[], char *const envp[]); 	*/
// 	(void) ac;
// 	(void) av;


// 	char *args[] = {"/bin/ls", "-l", NULL}; // path of command + "-la ...."


//     if (execve("/bin/ls", args, env) == -1) // -1 fail
//     {
//         perror("execve");
//         exit (1);
//     }

// 	return (0);
// }


// *********************** fork () *********************
// int main(void)
// {
//     pid_t pid;

//     printf("Fork here.\n");
//     pid = fork();
//     if (pid == -1)
//     {
//         return (-1);
//     }
//     printf("\nFork successful!\n");
//     if (pid == 0)
//     {
//         printf("Child: I'm the child, my pid is %d using get pid : %d using git parent pid : %d \n", pid , getpid(), getppid());
// 			// for what the parent pid is 1 ha9ach parent khrej (no wait) ohowa b9a itiem tbnato init hahah
//     }
//     else if (pid > 0)
//     {
//         printf("Parent: I'm the parent, my pid is %d my child pid : %d using git parent pid : %d .\n", pid, getpid(), getppid());
// 		wait (NULL);
//     }
//     return(0);
// }


//  *********************** fork () Memory Duplicated but Not Shared *********************


// void	child_process(pid_t	pid, int *nb)
// {
// 	printf ("I'm child my pid is : %d\n", pid);
// 	printf ("Child : the number is : %d\n", *nb);
// }

// void	parent_process(pid_t	pid, int *nb)
// {
// 	printf ("I'm parent my pid is : %d\n", pid);
// 	printf ("Parent : the number is : %d\n", *nb);
// 	*nb *= 2;
// 	printf ("Parent : the number modified is : %d\n", *nb);
// }

// int main (void)
// {
// 	pid_t	pid;
// 	int		nb;

// 	nb = 1337;
// 	printf ("before fork, the number is %d\n", nb);
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		return (EXIT_FAILURE);
// 	}
// 	if (pid == 0)
// 		child_process(pid, &nb);
// 	else if (pid > 0)
// 		parent_process(pid, &nb);
	
// 	return (0);
// }


//  *********************** Wait: Stick Around for the Child Processes *********************


// int main(void)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		return(EXIT_FAILURE);
	
// 	if (pid == 0)
// 	{
// 		printf ("Child : I'm child pid : %d\n", pid);
// 		sleep(2); // sleep 2 second after the programm exite
// 		printf ("\nChild : Done !!\n");
// 		fflush(stdout); 
// 		return (-1);
// 	}
// 	else if (pid > 0)
// 	{
// 		printf ("Parent : I'm paernt pid : %d\n", pid);
// 		printf ("Parent : Done !!\n");
// 	}

// 	return (0);
// }


// ****************************** Waiting to Avoid Zombies ***************************

// int main(void)
// {
//     pid_t pid;

//     pid = fork();
//     if (pid == -1)
//         return (1);
//     if (pid == 0)
//     {
//         printf("Child: I'm the child, my internal pid is %d.\n", pid);
//         printf("Child: Done!\n");
//     }
//     else if (pid > 0)
//     {
//         printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
//         while (1) // Infinite loop, the parent will never end !
//             usleep(1);
//     }
//     return (0); // fhad lhala tha zombie ha9ach parent khrej o child ba9i
// 				// But before we kill the infinite process with ctrl-c,
// 				// we can open a new terminal and do the ps aux | grep <pid_du_fils> // 0 | grep Z+ 
// }

// ****************************** The Wait and Waitpid System Calls  ******************************

// Define a macro for a specific child exit code (if we do not
// specify this exit code during compilation with the
// -D CHILD_EXIT_CODE=[number] option), by default, it will be 42:
// #ifndef CHILD_EXIT_CODE
// # define CHILD_EXIT_CODE 42
// #endif

// // Define a macro for the expected exit status
// #define EXPECTED_CODE 42

// // Child process routine:
// void	child_routine(pid_t pid)
// {
// 	printf("\e[36mChild: Hi! I'm the child. PID received from fork = %d\e[0m\n", pid);
// 	printf("\e[36mChild: Exiting with exit code %d.\e[0m\n", CHILD_EXIT_CODE);
// 	exit(CHILD_EXIT_CODE);
// }

// // Parent process routine:
// void	parent_routine(pid_t pid)
// {
// 	int	status;

// 	printf("Parent: I'm the parent. PID received from fork = %d\n", pid);
// 	printf("Parent: Waiting for my child with PID [%d].\n", pid);
// 	waitpid(pid, &status, 0); // Wait for child
// 	printf("Parent: My child exited with status %d\n", status);
// 	if (WIFEXITED(status)) // If child exited normally
// 	{
// 		printf("Parent: My child's exit code is %d\n", WEXITSTATUS(status));
// 		if (WEXITSTATUS(status) == EXPECTED_CODE)
// 			printf("Parent: That's the code I expected!\n");
// 		else
// 			printf("Parent: I was not expecting that code...\n");
// 	}
// }

// int	main(void)
// {
// 	pid_t	pid; // Store fork's return value

// 	pid = fork(); // Create child process
// 	if (pid == -1)
// 		return (EXIT_FAILURE);
// 	else if (pid == 0) // Child process
// 		child_routine(pid);
// 	else if (pid > 0) // Parent process
// 		parent_routine(pid);
// 	return (EXIT_SUCCESS);
// }

// ****************** Check  *********************



//unset PATH

//-fsanitize=address -g

// void foo()
// {
// 	system("leaks -q pipex");
// }
// int	main(int ac, char	**av, char	**env)
// {
// 	atexit(foo);
// }

// + ./program


// -fsanitize=address

// -fsanitize=leak

//  -fsanitize=undefined

// valgrind --leak-check=full --track-origins=yes ./your_program