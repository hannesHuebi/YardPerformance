//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#ifndef EXPLOG_H
#define EXPLOG_H

#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

#include "expbuffer.h"
#include "expvalue.h"
#include "udpport.h"

#define NUMCHANNELS 255

class ExpLog
{
    public:

        ExpLog();
        ExpLog(const char* _port);
        ExpLog(const char* _port, double _hours);

        virtual ~ExpLog();

        // daemon

        void start_daemon(const char* _port);
        void stop_daemon();

        // buffer size

        void set_time_range(double _hours);
        double time_range() const;

        // interface: name_of_channel(averaging, offset)

        double channel(unsigned int _id,
                       double _averaging = 0,
                       double _offset = 0);

    protected:
    private:

        // daemon for udp

        void daemon(const char* _port);
        void parse(std::string& _packet);

        bool run_;              // daemon status
        std::thread thread_;    // daemon thread

        // channels

        ExpBuffer channels_[NUMCHANNELS];

        // time range to buffer in seconds

        double time_range_;
};

#endif // EXPLOG_H
