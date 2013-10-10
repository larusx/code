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
	struct sockaddr_in acceptaddr;
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
	}

	return 0;
}
