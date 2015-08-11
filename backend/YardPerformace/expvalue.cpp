//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#include "expvalue.h"

ExpValue::ExpValue()
{
   set_value(0);
}

ExpValue::ExpValue(float _value)
{
   set_value(_value);
}

ExpValue::ExpValue(ExpValue& _cpy)
{
    // copy constructor: copy value and time, i.e. the new object represents the
    // same data point

    value_ = _cpy.value();
    time_ = _cpy.time();

}

ExpValue::ExpValue(const ExpValue& _cpy)
{
    // copy constructor: copy value and time, i.e. the new object represents the
    // same data point

    value_ = _cpy.value();
    time_ = _cpy.time();
}

ExpValue::~ExpValue()
{
    //dtor
}

void ExpValue::set_value(float _value)
{

    value_ = _value;
    std::time(&time_);  // current time

}

