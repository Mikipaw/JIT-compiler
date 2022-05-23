//
// Created by mikhalinho on 03.05.22.
//

#ifndef JIT_COMPILER_TRANSLATOR_H
#define JIT_COMPILER_TRANSLATOR_H

#include <vector>
#include <cstdio>
#include <cassert>
#include <sys/mman.h>
#include <iostream>

#include "List_of_mistakes.h"
#include "Paths.h"
#include "BCDict.h"

#include "headers/simple_string.h"

using std::vector;

#define CREATE_TRANSLATOR(name, number_of_commands, id) Translator name(number_of_commands, id, #name);

extern "C" void cprintf(const char*, ...);

inline void prints(int number) { cprintf("&d $", number); }


class Translator{
private:
    int bcc[20];

    size_t number_of_commands = 0;
    const char* name = "Unnamed Translator";

    int*     mark       = nullptr;
    double  *array      = nullptr;
    u_char bytecode[300];

    u_char outputt      = 0;
    int ind = 0;
    int ret = 0;
    int stk_size = 0;
    const double version = 0.1;

public:
    explicit
    Translator(size_t num_of_coms, int my_id, const char* new_name);

    [[nodiscard]] double Get_command (int index) const { return array[index]; };

    /*!
    *  @method int Work().
    *  @brief  Translate commands to nasm lang from given file.
    *
    *  @return an integer - error code.
    */
    int Work();

    int Run() const;

    int compute_dist(int src, int dest);

    Translator& operator=(const Translator& cpu) = delete;
    Translator(const Translator&)                = delete;


    void Change_ret(int pointer){ ret = pointer; }

    [[nodiscard]] const char* Get_name()    const { return name; };
    [[nodiscard]] double      Get_version() const { return version; };
    [[nodiscard]] int         Get_NOC()     const { return number_of_commands; };
    [[nodiscard]] int         Get_ret()     const { return ret; };


    ~Translator() {
        //free(RAM);
        free(array);
        //free(bytecode);
        free(mark);
    }

};


#endif //JIT_COMPILER_TRANSLATOR_H
