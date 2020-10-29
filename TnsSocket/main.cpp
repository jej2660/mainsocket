//
//  main.cpp
//  TnsSocket
//
//  Created by 장재원 on 2020/10/26.
//  Copyright © 2020 장재원. All rights reserved.
//

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXBUF 1024
class Socket{
    int client_socket;
    struct sockaddr_in serverAddr;
    int server_addr_size;
    char senbbuf[MAXBUF];
    char readbuf[MAXBUF];
    
    ssize_t recvbyte;
    ssize_t sendbyte;
    
    Socket(){
        memset(&this->serverAddr, 0, sizeof(this->serverAddr));
        inet_aton("127.0.0.1", (struct in_addr *)&this->serverAddr.sin_addr.s_addr);
        serverAddr.sin_port = htons(25565);
        
        if((this->client_socket = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
            std::cout << "Creating Socket excption.." << std::endl;
        }
    }
    void sendData(){
        /* 기존 시스템에 맞춰서 구현...*/
        this->sendbyte = sendto(this->client_socket, this->senbbuf, strlen(this->senbbuf), 0, (struct sockaddr *)&this->serverAddr, sizeof(this->serverAddr));
    }
    ~Socket(){
        close(this->client_socket);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
