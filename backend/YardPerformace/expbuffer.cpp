//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#include "expbuffer.h"

ExpBuffer::ExpBuffer()
{
    // default buffer time range is one hour
    set_time_range(3600);
}

ExpBuffer::ExpBuffer(double _seconds)
{
    set_time_range(_seconds);
}

ExpBuffer::~ExpBuffer()
{
    //dtor
}

double ExpBuffer::value(double _averaging /*=0*/,
                        double _offset /*= 0*/) const
{

    if(buffer_.size() == 0)
        return 0;

    ConstDataIterator it = buffer_.cbegin();

    // skip all data points in the offset range (if necessary)

    if(_offset > 0)
    {
        // get time stamp of newest element

        time_t t0 = buffer_.front().time();

        // skip

        while(difftime(t0, it->time()) < _offset)
        {
            ++it;

            if(it == buffer_.cend())
                return 0;
        }

    }

    // average (using trapezoid formula for integral)
    //
    //             t2
    //            /
    //            | xi dt
    //            /
    //          t1
    // x_mean = -----------
    //            t2 - t1
    //

    if(_averaging > 0)
    {

        double xmean = 0;

        // time stamp of first data point used
        time_t t1 = it->time();

        while(difftime(t1, it->time()) < _averaging)
        {
            // first element
            double x1_val = it->value();
            time_t x1_time = it->time();

            // next element
            ++it;

            if(it == buffer_.cend())
                return 0;

            // first element
            double x2_val = it->value();
            time_t x2_time = it->time();

            // trapezoid
            xmean += 0.5*(x1_val+x2_val)*difftime(x1_time, x2_time);

        }

        // time stamp of last data point used
        time_t t2 = it->time();

        // return result
         return xmean / difftime(t1, t2);

    }
    else
    {
        // no averaging? return simply the value of this element
        return it->value();
    }

    return 0;

}

void ExpBuffer::add_value(double _value)
{
    // add new value at the beginning of the buffer

    buffer_.push_front(ExpValue(_value));

    // get time stamp of new element

    time_t curtime = buffer_.front().time();

    // now, delete all elements from the end of the buffer that are older than
    // curtime + time_range_

    // start with last element
    DataIterator it = --buffer_.end();

    // iterate upwards
    while(it != buffer_.begin())
    {

        // stop loop when first element is in time-range
        if(difftime(curtime, it->time()) < time_range_)
            break;

        // delete
        buffer_.erase(it);

        // next element
        --it;

    }

}

void ExpBuffer::set_time_range(double _seconds)
{
    time_range_ = _seconds;
}

void ExpBuffer::print_to_stdout() const
{

    for(std::size_t i=0; i<buffer_.size(); ++i)
    {

        std::cout << buffer_[i].value() << "\t"
                  << ctime(&buffer_[i].time());

    }

}
