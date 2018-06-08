#include <unistd.h>
#include <sstream>
#include <string>
#include <iostream>
#include <limits.h>
#include <cstdio>
#include <memory>

#define INVALID_PACKAGE false
#define VALID_PACKAGE true

class Package {
    private:
    char *pkg_path;
    char *install_path;

    const char *name;
    double version;

    public:
    void set_package_path(char *path);
    void set_install_path(char *path);

    bool verifyPackage();
    void loadMetadata();
    void install();

    char* get_pkg_path();
    char* get_install_path();
};