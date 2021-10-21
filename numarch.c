int main(){
    int fd[2];
    int pid;
    pipe(fd);
    pid=fork();
    if (pid==0){
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp("ws","ws","-l",NULL);
    }else{
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls",NULL);
    }
    return 0;
}