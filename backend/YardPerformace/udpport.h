//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#ifndef UDPPORT_H
#define UDPPORT_H

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

class UDPPort
{
    public:

        UDPPort();
        UDPPort(const char* _port);
        virtual ~UDPPort();

        // set a port
        bool set_port(const char* _port);

        // status
        bool is_valid() const;

        // receive a package from the port
        bool recv_packet(std::string* _packet) const;

    protected:
    private:

        // invalidate
        void invalidate();

        int socket_;

};

#endif // UDPPORT_H
