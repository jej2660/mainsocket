//
//  sock.cpp
//  TnsSocket
//
//  Created by 장재원 on 2020/10/29.
//  Copyright © 2020 장재원. All rights reserved.
//

#include "sock.h"


Sock::Sock(){
    memset(&this->serverAddr, 0, sizeof(this->serverAddr));
    inet_aton("127.0.0.1", (struct in_addr *)&this->serverAddr.sin_addr.s_addr);
    serverAddr.sin_port = htons(25565);
           
    if((this->client_socket = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        std::cout << "occur Socket excption.." << std::endl;
    }
}
void Sock::sendData(){
    this->sendbyte = sendto(this->client_socket, this->senbbuf, strlen(this->senbbuf), 0, (struct sockaddr *)&this->serverAddr, sizeof(this->serverAddr));
}
Sock::~Sock(){
    close(this->client_socket);
}
