#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ostream>

#include "messages.h"
#include "package.h"

Messages* messages = new Messages();
Package* pkg = new Package();

static struct option long_options[] = {
    {"quiet", no_argument, &messages->quiet, 1},
    
    {"package", required_argument, 0, 'p'},

    {"view", no_argument, 0, 'v'},
    {"extract", no_argument, 0, 'x'},

    {"install", optional_argument, 0, 'i'},
    {0, 0, 0, 0}
};

static char* short_options = "p:i:";

int main(int argc, char *argv[]) 
{
    int option_index;
    char c;
    while ((c = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        if (c == 0) {

        } else if (c == 'p') { 
            std::ostringstream s;
            s << "Package Archive => '" << optarg << "'";
            messages->message(s.str());

            pkg->set_pkg_path(optarg);
        } else if (c == 'v') {

        }
    }
    return 0;
}

