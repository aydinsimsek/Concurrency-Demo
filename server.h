#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024  
#define PORT_NUM 5001 
#define BACKLOG 5 

class TCPServer
{
    private:
        int sockfd;

    public: 
        TCPServer();
        ~TCPServer()
        {
            close(sockfd);
        }
		int acceptClient(sockaddr_in &clientAddr);
		int getServerSocketFd() const;
};

class ClientHandler
{
    private:
        int newsockfd;
        sockaddr_in clientAddr;
        int clientNum;

    public:
        ClientHandler(int fd, sockaddr_in addr, int num) : newsockfd(fd), clientAddr(addr), clientNum(num) {}
        ~ClientHandler()
        {
            close(newsockfd);
        }
		void handleClient();
};

#endif
