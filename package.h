#include <unistd.h>
#include <sstream>
#include <string>
#include <archive.h>

#define INVALID_PACKAGE false
#define VALID_PACKAGE true

class Package {
    private:
    std::string pkg_path;
    std::string install_path;

    std::string name;
    double version;

    public:
    void set_package_path(std::string);
    void set_install_path(std::string);

    bool verifyPackage();
    void loadMetadata();

    std::string get_pkg_path();
    std::string get_install_path();
};