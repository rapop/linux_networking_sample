#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
       fprintf(stderr,"Usage %s hostname port\n", argv[0]);
       exit(0);
    }

    int port_number = atoi(argv[2]);
    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_file_descriptor < 0) {
        error("ERROR opening socket");
    }

    // contains the name of a host on the Internet, e.g. cs.rpi.edu.
    struct hostent* server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    // Same as in the server. However, because the field server->h_addr is a character string, 
    // we use the function. 
    bcopy((char *)server->h_addr, 
         (char *)&server_address.sin_addr.s_addr,
         server->h_length);
    server_address.sin_port = htons(port_number);
    
    if (connect(socket_file_descriptor,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
        error("ERROR connecting");
    }

    printf("Please enter the message: ");

    char buffer[256];
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    int n = write(socket_file_descriptor,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(socket_file_descriptor,buffer,255);
    if (n < 0)
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    close(socket_file_descriptor);
    return 0;
}
