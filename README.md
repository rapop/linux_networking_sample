# Linux Networking Sample

## Build
`mkdir build`
Avoids cluttering the source directory with the build files.

`cd mkdir`
`cmake ..`
Reads the CMakeLists.txt and generate build files.

`cmake --build .`
Call the build system to compile/link the project.

## Test
`./build/networking_server 51715`
`./build/networking_client localhost 51715`

## Notes

[https://www.linuxhowtos.org/C_C++/socket.htm](https://www.linuxhowtos.org/C_C++/socket.htm)

## Linux

### `errno`

`perror` prints also the system error message found by the errno code.
when a system call fails, POSIX library will set the errno variable

## Networking

### Sockets

When a socket is created, the program has to specify the address domain and the socket type. Two processes can communicate with each other only if their sockets are of the same type and in the same domain.

unix domain = 2 processes share a common file system. The address of a socket is a character string which is basically an entry in the file system.

internet domain = two processes running on any two hosts on the Internet communicate.

Port numbers are 16 bit unsigned integers. Port numbers above 2000 are generally available.

The address of a socket in the Internet domain consists of the Internet address of the host machine (every computer on the Internet has a unique 32 bit address, often referred to as its IP address.

**TCP (Transmission Control Protocol)**, is a stream socket (one of the 2 types), is reliable, is stream oriented, treat communications as a continuous stream of characters.

**UDP (Unix Datagram Protocol)**, which is unreliable and message oriented. Is a datagram socket and has to read entire messages at once.

There is a lot less overhead associated with a datagram socket because connections do not need to be established and broken down, and packets do not need to be acknowledged. This is why datagram sockets are often used when the service to be provided is short, such as a time-of-day service.