#include "package.h"
#include <iostream>

void Package::set_package_path(std::string path) {
    pkg_path = path;
}

void Package::set_install_path(std::string path) {
    install_path = path;
}

void Package::loadMetadata() {
    struct archive *archive = archive_read_new();
    archive_read_support_format_zip(archive);
    int archive_status = archive_read_open_filename(archive, pkg_path.c_str(), 1024);

    struct archive_entry* entry;
}

bool Package::verifyPackage() {
    struct archive* archive = archive_read_new();
    archive_read_support_format_zip(archive);

    int archive_status = archive_read_open_filename(archive, pkg_path.c_str(), 1024);

    if (archive_status != ARCHIVE_OK) {
        return INVALID_PACKAGE;
    } else {
        return VALID_PACKAGE; 
    }
}

std::string Package::get_install_path() {
    return install_path;
}

std::string Package::get_pkg_path() {
    return pkg_path;
}