#include <iostream>
#include <sstream>
#include <ostream>

#define TERM_NORMAL "\x1B[0m"
#define TERM_RED "\x1B[31m"
#define TERM_GREEN "\x1B[32m"
#define TERM_YELLOW "\x1B[33m"
#define TERM_BLUE "\x1B[34m"
#define TERM_MAGENTA "\x1B[35m"
#define TERM_CYAN "\x1B[36m"
#define TERM_WHITE "\x1B[37m"

#define status_error -1
#define status_normal 0
#define status_success 1

class Messages 
{

    public:
    bool quiet = false;
    void status_message(std::string, int);
    void message(std::string);
    void setQuiet();
};