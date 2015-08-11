//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#ifndef EXPBUFFER_H
#define EXPBUFFER_H

#include <iostream>
#include <deque>
#include <ctime>

#include "expvalue.h"

// contains a list of data points that covers a given time span

class ExpBuffer
{
    public:
        ExpBuffer();
        ExpBuffer(double _hours);
        virtual ~ExpBuffer();

        // get a value
        //
        // in:
        //   _average   : time span the value is averaged in seconds
        //   _offset    : offset from the newest data point in seconds
        //
        double value(double _average = 0, double _offset = 0) const;

        // add a new value to the buffer
        void add_value(double _value);

        // time range covered by the buffer
        void set_time_range(double _seconds);

        // print buffer to stdout
        void print_to_stdout() const;

    protected:
    private:

        // typedefs

        typedef std::deque<ExpValue> DataContainer;
        typedef std::deque<ExpValue>::iterator DataIterator;
        typedef std::deque<ExpValue>::const_iterator ConstDataIterator;

        // members

        DataContainer buffer_;  // data points

        double time_range_;     // the time range covered by the buffer
                                // in seconds
};

#endif // EXPBUFFER_H
