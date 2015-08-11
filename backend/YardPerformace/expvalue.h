//****************************************************************************//
// Sebastian Greshake
// 08.08.2015
//****************************************************************************//

#ifndef EXPVALUE_H
#define EXPVALUE_H

#include <ctime>

class ExpValue
{
    public:

        // constructors
        ExpValue();
        ExpValue(float _value);
        ExpValue(ExpValue& _cpy);
        ExpValue(const ExpValue& _cpy);

        // destructor
        virtual ~ExpValue();

        // read-only access to data (once set, no change possible anymore)
        const float& value() const { return value_; };
        const time_t& time() const { return time_; };

    protected:
    private:

        // setter
        void set_value(float _value);

        float  value_;      // value
        time_t time_;       // time stamp (automatically set on creation)
};

#endif // EXPVALUE_H
