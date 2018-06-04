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

int quiet;
int showinfo;

static struct option long_options[] = {
    {"quiet", no_argument, 0, 'q'},

    
    {"package", required_argument, 0, 'p'},

    {"info", no_argument, &showinfo, 1},

    {"install", required_argument, 0, 'i'},
    {0, 0, 0, 0}
};

static char* short_options = "qp:i";

int main(int argc, char *argv[]) 
{
    int option_index;
    char c;
    while ((c = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        if (c == 'q') messages->setQuiet();
        else if (c == 'p') pkg->set_package_path(optarg);
        else if (c == 'i') pkg->set_install_path(optarg);
    }

    std::ostringstream* s = new std::ostringstream();
    *s << "PACKAGE ARCHIVE: '" << pkg->get_pkg_path() << "'";
    messages->message(s->str());
    delete s;

    if (!pkg->verifyPackage()) {
        messages->status_message("INVALID OR CORRUPTED PACKAGE!", status_error);
        exit(1);
    }

    pkg->loadMetadata();

    if (showinfo) {
        messages->message("PACKAGE INFORMATION:");
        pkg->loadMetadata();
    }

    return 0;
}