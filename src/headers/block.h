#ifndef __BLOCK__
#define __BLOCK__

#include <bits/stdc++.h>
#include "executables.h"

class executables;

class block {
private:
    executables *exec;
public:
    block(executables*);
    ~ block();
};

#endif