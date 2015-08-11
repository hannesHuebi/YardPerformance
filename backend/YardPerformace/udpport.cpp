//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#include "udpport.h"

UDPPort::UDPPort()
{

    // invalidate socket

    socket_ = -1;

}

UDPPort::UDPPort(const char* _port)
{

    // invalidate socket

    socket_ = -1;

    // try to set port

    set_port(_port);


}

UDPPort::~UDPPort()
{
    // close socket

    if(socket >= 0)
    {
        close(socket_);
    }

}

bool UDPPort::set_port(const char* _port)
{

    // close old socket, if any

    if(socket >= 0)
    {
        close(socket_);
    }

    // get a local address for communication

    struct addrinfo local_hints;            // criterias to select the address

    memset(&local_hints,0,sizeof(local_hints));

    local_hints.ai_family = AF_UNSPEC;      // IPv4 or IPv6
    local_hints.ai_socktype = SOCK_DGRAM;   // UDP
    local_hints.ai_flags = AI_PASSIVE;      // Use IP of this machine

    struct addrinfo* local_addr;            // now, receive the address

    if(getaddrinfo(NULL, _port, &local_hints, &local_addr) != 0)
    {
        std::cerr << "Could not get an address for the socket."  << std::endl;
    }
    else
    {

        // create socket:

        socket_ = socket (local_addr->ai_family,
                          local_addr->ai_socktype,
                          local_addr->ai_protocol);

        // succesful?

        if(socket < 0)
        {
            std::cerr << "Unable to create socket." << std::endl;
        }
        else
        {

            // bind port to socket

            if(bind(socket_, local_addr->ai_addr, local_addr->ai_addrlen) < 0)
            {
                std::cerr << "Unable to bind socket." << std::endl;

                // close socket
                close(socket_);socket_=-1;

            }

        }

    }

    // free memory

    freeaddrinfo(local_addr);

    // status

    return is_valid();

}

bool UDPPort::recv_packet(std::string* _packet) const
{

    // reive packet from UDP-port

    if(is_valid())
    {

        // packet content

        char buffer[1024];

        // receive packet

        int len = recv(socket_, buffer, 1024, MSG_DONTWAIT);

        if(len > 0)
        {
            if(_packet)
            {
                *_packet = std::string(buffer, len);
                return true;
            }
        }
    }

    // nothing?
    return false;

}

bool UDPPort::is_valid() const
{

    if(socket < 0)
        return false;
    else
        return true;

}
