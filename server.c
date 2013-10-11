#include<stdio.h>
#include<sys/socket.h>
#include<strings.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char* str="hello\n";
	int serverfd=socket(AF_INET,SOCK_STREAM,0);
	int reuse=1;
	setsockopt(serverfd,SOL_SOCKET,SO_REUSEADDR,(int*)&reuse,sizeof(int));
	//perror("setsockopt:\n");
	struct sockaddr_in servaddr;
	struct sockaddr_in accept_addr;
	char accept_ip[20];
	int addr_len=sizeof(struct sockaddr_in),accept_addr_len=sizeof(struct sockaddr_in);
	bzero(&servaddr,addr_len);
	bzero(&accept_addr,addr_len);
	servaddr.sin_port=htons(8888);
	servaddr.sin_family=AF_INET;
	bind(serverfd,(struct sockaddr*)&servaddr,addr_len);
	//perror("bind:\n");
	listen(serverfd,100);
	int acceptfd;
	while(acceptfd=accept(serverfd,NULL,NULL))
	{
		//perror("accept:\n");
		write(acceptfd,str,strlen(str));
		getpeername(acceptfd,(struct sockaddr *)&accept_addr,&accept_addr_len);
		//perror("getpeername:\n");
		inet_ntop(AF_INET,&accept_addr.sin_addr,accept_ip,20);
		printf("%s : %d\n",accept_ip,ntohs(accept_addr.sin_port));
	}

	return 0;
}
