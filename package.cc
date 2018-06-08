#include "package.h"

void Package::set_package_path(char *path) {
    char buffer[PATH_MAX + 1];

    realpath(path, buffer);

    pkg_path = buffer;

}

void Package::set_install_path(char *path) {
    char buffer[PATH_MAX + 1];

    realpath(path, buffer);

    install_path = buffer;
}

void Package::install() {
    
}

void Package::loadMetadata() {

}

bool Package::verifyPackage() {
    std::ostringstream verify_tarxz;
    verify_tarxz << "(tar xf " << this->get_pkg_path() << " -O 2> /dev/null && xz -t " << this->get_pkg_path() << " 2>/dev/null) > /dev/null";

    int tarintegrity = system(verify_tarxz.str().c_str());
    if (WEXITSTATUS(tarintegrity) != 0) return false;

    std::ostringstream verify_pkginfo = std::ostringstream();
    verify_pkginfo << "(tar xf " << this->get_pkg_path() << " -O -p .pkginfo 2> /dev/null) > /dev/null";

    int pkginfo_found = system(verify_pkginfo.str().c_str());
    if (WEXITSTATUS((pkginfo_found)) != 0) return false;

    return true;
}

char* Package::get_install_path() {
    return install_path;
}

char* Package::get_pkg_path() {
    return pkg_path;
}