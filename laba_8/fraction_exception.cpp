#include "fraction_exception.h"
using namespace std;
FractionException :: FractionException(const string& message) : runtime_error(message)
{
}
