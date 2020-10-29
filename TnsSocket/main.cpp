//
//  main.cpp
//  TnsSocket
//
//  Created by 장재원 on 2020/10/26.
//  Copyright © 2020 장재원. All rights reserved.
//




class Socket{
    int client_socket;
    struct sockaddr_in serverAddr;
    int server_addr_size;
    char senbbuf[MAXBUF];
    char readbuf[MAXBUF];
    
    ssize_t recvbyte;
    ssize_t sendbyte;
    
    Socket(){
       
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
