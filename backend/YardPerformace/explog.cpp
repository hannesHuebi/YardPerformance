//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#include "explog.h"
#include <QProcess>

ExpLog::ExpLog()
{
    run_ = false;

    // default = one hour buffer size
    set_time_range(1);
}

ExpLog::ExpLog(const char* _port)
{
    run_ = false;
    start_daemon(_port);

    // default = one hour buffer size
    set_time_range(1);
}

ExpLog::ExpLog(const char* _port, double _hours)
{
    run_ = false;

    start_daemon(_port);

    set_time_range(_hours);
}

ExpLog::~ExpLog()
{
    stop_daemon();
}

void ExpLog::start_daemon(const char* _port)
{
    if(!run_)
    {
        run_ = true;

        // create thread
        thread_ = std::thread(&ExpLog::daemon, this, _port);
    }

}

void ExpLog::stop_daemon()
{
    if(run_)
    {
        run_ = false;

        // wait until thread is finished
        thread_.join();
    }
}

void ExpLog::set_time_range(double _hours)
{
    time_range_ = _hours*3600;

    for(unsigned int i=0; i<NUMCHANNELS; ++i)
    {
        channels_[i].set_time_range(time_range_);
    }
}

double ExpLog::time_range() const
{
    return time_range_ / 3600;
}

double ExpLog::channel(unsigned int _id,
                       double _averaging/* = 0*/,
                       double _offset/* = 0*/)
{

    if(_id < NUMCHANNELS)
    {
        return channels_[_id].value(_averaging, _offset);
    }
    else
        return 0;

}

void ExpLog::daemon(const char* _port)
{

    // create port
    UDPPort port(_port);

    // run
    while(run_)
    {

        if(port.is_valid())
        {

            std::string packet;

            if(port.recv_packet(&packet))
            {

                parse(packet);

            }

        }

    }

}
void ExpLog::parse(std::string& _packet)
{

    // Format: #0,<channel number>,<value>,...

    std::stringstream ss(_packet);

    std::string channel;
    std::string value;

    // skip introductory part
    ss.ignore(3);

    // now read always the tuple (channel, value)
    while(std::getline(ss, channel, ',') && std::getline(ss, value, ','))
    {

        unsigned int i = atoi(channel.c_str());
        double val = atof(value.c_str());
//        double val = std::stod(value);
//        double val = QString::fromStdString(value).toDouble();

        channels_[i].add_value(val);

        //std::cout << channel << ": " << value << " | ";
        //std::cout << i << ": " << val << std::endl;

        /*switch(i)
        {
        case 1:
             channels_[i].add_value(val);
             break;
        default:
            break;

        }*/

    }

}
