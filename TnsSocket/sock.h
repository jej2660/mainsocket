//
//  sock.h
//  TnsSocket
//
//  Created by 장재원 on 2020/10/29.
//  Copyright © 2020 장재원. All rights reserved.
//

#ifndef sock_h
#define sock_h
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAXBUF 1024

class Sock{
    int client_socket;
    struct sockaddr_in serverAddr;
    int server_addr_size;
    char senbbuf[MAXBUF];
    char readbuf[MAXBUF];
    
    ssize_t recvbyte;
    ssize_t sendbyte;
    
    Sock();
    void sendData();
    ~Sock();
    
};

#endif /* sock_h */
