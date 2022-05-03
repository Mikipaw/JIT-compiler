//
// Created by mikhalinho on 25.04.22.
//

#ifndef JIT_COMPILER_BUILDER_H
#define JIT_COMPILER_BUILDER_H

#include <vector>
#include <cstdint>
#include <bits/confname.h>
#include <unistd.h>


#include "simple_string.h"
#include "Paths.h"

class Builder;

size_t estimate_memory_size(size_t machine_code_size);


class Builder {
public:
    int Build();





};


#endif //JIT_COMPILER_BUILDER_H
