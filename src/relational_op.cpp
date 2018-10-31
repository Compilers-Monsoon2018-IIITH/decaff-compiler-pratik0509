#include "executables.h"

executables::executables() {
    #ifdef __TEST
        std::cout << "executables created\n";
    #endif
    id_list = NULL;
}

executables::~executables() {
    if (id_list != NULL)
        delete id_list;
}