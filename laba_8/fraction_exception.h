#ifndef FRACTION_EXCEPTION_H
#define FRACTION_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class FractionException : public runtime_error
{
public:
    explicit FractionException(const string& message);
};

#endif 
