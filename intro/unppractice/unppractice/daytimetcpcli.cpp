//
//  main.cpp
//  unppractice
//
//  Created by dogrest on 2018/10/31.
//  Copyright © 2018 dogrest. All rights reserved.
//

#include <iostream>
#include "unp.h"

int main(int argc, const char * argv[]) {
    int sockfd,n;
    char recvline[MAXLINE+1];
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(13);
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr)<0)
        return 1;
    if(connect(sockfd,(SA*)&servaddr,sizeof(MAXLINE))>0)
    {
        return 1;
    }
    while((n=read(sockfd,recvline,MAXLINE))>0)
    {
        recvline[n]=0;
        if(fputs(recvline,stdout)==EOF)
        {
            return 1;
        }
    }
    if(n<0)
        return 1;
    
    return 0;
    std::cout << "Hello, World!\n";
    return 0;
}
