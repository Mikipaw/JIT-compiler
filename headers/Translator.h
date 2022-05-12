//
// Created by mikhalinho on 03.05.22.
//

#ifndef JIT_COMPILER_TRANSLATOR_H
#define JIT_COMPILER_TRANSLATOR_H

#include <vector>
#include <cstdio>
#include <cassert>

#include "List_of_mistakes.h"
#include "Paths.h"

#include "headers/simple_string.h"

using std::vector;

#define CREATE_TRANSLATOR(name, number_of_commands, id) Translator name(number_of_commands, id, #name);

class Translator{
private:
    vector<double> trans_vector = vector<double>(1);
    size_t number_of_commands = 0;
    const char* name = "Unnamed Translator";

    int* mark       = nullptr;
    double *array      = nullptr;

    int ret = 0;
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

    Translator& operator=(const Translator& cpu) = delete;
    Translator(const Translator&)                = delete;


    void Change_ret(int pointer){ ret = pointer; }

    [[nodiscard]] const char* Get_name()    const { return name; };
    [[nodiscard]] double      Get_version() const { return version; };
    [[nodiscard]] int         Get_NOC()     const { return number_of_commands; };
    [[nodiscard]] int         Get_ret()     const { return ret; };


    [[nodiscard]] vector<double> Get_vector() const { return trans_vector; };

    ~Translator(){
        free(array);
        free(mark);
    }

};







#endif //JIT_COMPILER_TRANSLATOR_H
