#include "messages.h"

void Messages::status_message(std::ostringstream stream, int status) 
{
    if (!quiet) {
        switch (status) {
            case status_error:
            std::cout << TERM_RED;
            break;
        
            case status_normal:
            std::cout << TERM_NORMAL;
            break;

            case status_success:
            std::cout << TERM_GREEN;
            break;
        }
        std::cout << stream.str() << std::endl;
    }
}

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

void Messages::message(std::ostringstream message) 
{
    if (!quiet) {
        std::cout << message.str() << std::endl;
    }
}

void Messages::message(std::string message) 
{
    if (!quiet) {
        std::cout << message << std::endl;
    }
}
