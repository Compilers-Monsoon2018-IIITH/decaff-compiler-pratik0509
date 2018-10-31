#include "method_call.h"

method_call::method_call() {
    #ifdef __TEST
        std::cout << "method_call created\n";
    #endif
}

void method_call::set_method_call(location *l, param_list *p) {
    loc = l;
    p_list = p;
    return;
}