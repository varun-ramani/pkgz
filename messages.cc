#include "messages.h"

void Messages::status_message(std::string message, int status) 
{
    if (!quiet) {
        switch (status) {
            case status_error:
            std::cout << TERM_RED << message << std::endl;
            break;

            case status_normal:
            std:: cout << TERM_NORMAL << message << std::endl;
            break;

            case status_success:
            std::cout << TERM_GREEN << message << std::endl;
            break;
        }
    }
}

void Messages::message(std::string message) 
{
    if (!quiet) {
        std::cout << message << std::endl;
    }
}
