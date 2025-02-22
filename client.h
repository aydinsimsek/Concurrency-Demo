#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024  
#define PORT_NUM 5001 

class TCPClient
{
    private:
        int sockfd;
        struct sockaddr_in serverAddr;

    public:
        TCPClient(const char *serverAddress, int port);
        ~TCPClient()
        {
            close(sockfd);
        }
		void connectToServer();
		int getClientSocketFd() const;
};

class Communication
{
    public:
		Communication() {}
        void sendMessage(int fd, const char *buffer);
		void receiveMessage(int fd, char *buffer);
};

#endif
