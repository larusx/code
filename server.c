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
	struct sockaddr_in servaddr;
	struct sockaddr_in accept_addr;
	int accept_addr_len;
	char accept_ip[20];
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&servaddr,addr_len);
	servaddr.sin_port=htons(8888);
	servaddr.sin_family=AF_INET;
	bind(serverfd,(struct sockaddr*)&servaddr,addr_len);
	listen(serverfd,100);
	int acceptfd;
	while(acceptfd=accept(serverfd,NULL,NULL))
	{
		write(acceptfd,str,strlen(str));
		getpeername(acceptfd,&accept_addr,&accept_addr_len);
		inet_ntop(AF_INET,&accept_addr.sin_addr,accept_ip,20);
		printf("%s : %d\n",accept_ip,ntohs(accept_addr.sin_port));
	}

	return 0;
}
