#include <unistd.h>
#include <sstream>

class Package {
    private:
    std::string name;
    std::string pkg_path;
    std::string install_path;
    double version;

    public:
    void set_pkg_path(std::string);
    void set_install_path(std::string);
    void loadPackage();
    void checkArchive();
};