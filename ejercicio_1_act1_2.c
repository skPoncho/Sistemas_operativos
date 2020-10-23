#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
//Carlos Alfonso Barrón Rivera  2CV8
int main(){
	pid_t pid,pid2;
	char hijo[] = {"Yo soy el proceso Hijo y mi Id es:"};
	char papa_hijo[] = {" y el ID de mi padre es:"};
	char nieto[] = {"Yo soy el proceso Nieto y mi Id es:"};
	system("gcc imprime.c -o imprime");
	pid = fork();
	if( pid == -1 )
		perror("Error al crear  proceso hijo: \n");
	else if( pid == 0){
		pid2 = fork();
		if( pid2 == -1  )
			perror("Error al crear  proceso Nieto \n");
		else if( pid2 == 0 )
			execl("./imprime","imprime",nieto,papa_hijo,NULL);
		else{
			wait(NULL);
			execl("./imprime","imprime",hijo,papa_hijo,NULL);
		}
	}
	else{
		wait(NULL);
		imprimef("Yo soy el proceso Padre y mi Id es: %d\n",getpid());
	}
	return 0;
}
