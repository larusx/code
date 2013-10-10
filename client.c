#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h>
#include<arpa/inet.h>
int main()
{
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in remote_addr;
	struct sockaddr_in accept_addr;
	int accept_addr_len;
	char accept_ip[20];
	char buf[100];
	int addr_len=sizeof(remote_addr);
	bzero(&remote_addr,addr_len);
	bzero(&accept_addr,addr_len);
	remote_addr.sin_family=AF_INET;
	remote_addr.sin_port=htons(8888);
	inet_pton(AF_INET,"127.0.0.1",&remote_addr.sin_addr);
	connect(sockfd,(struct sockaddr*)&remote_addr,addr_len);
	perror("connect");
	getsockname(sockfd,&accept_addr,&accept_addr_len);
	inet_ntop(AF_INET,&accept_addr.sin_addr,accept_ip,20);
	printf("%s : %d\n",accept_ip,ntohs(accept_addr.sin_port));
	read(sockfd,buf,100);
	printf("%s\n",buf);
	getpeername(sockfd,&accept_addr,&accept_addr_len);
	inet_ntop(AF_INET,&accept_addr.sin_addr,accept_ip,20);
	printf("%s : %d\n",accept_ip,ntohs(accept_addr.sin_port));
	while(1);
	return 0;
}
