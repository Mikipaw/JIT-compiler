#include <cstdio>

#include "headers/Assembler.h"
#include "headers/Translator.h"

//TODO: compare with cpu from 1st sem

int main() {
    int number_of_cmds = 228;

    CREATE_TRANSLATOR(trans, number_of_cmds, 1.0);

    trans.Work();
    trans.Run();

    return 0;
}
