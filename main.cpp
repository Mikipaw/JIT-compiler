#include <cstdio>

#include "headers/Assembler.h"
#include "headers/Translator.h"

//TODO: compare with cpu from 1st sem

using std::vector;

int main() {
    int number_of_commands = 0;
    FILE* noc = fopen (f_number_of_commands, "rb");
    CREATE_TRANSLATOR(trans, number_of_commands, 1.0);
    fclose(noc);

    trans.Work();
    trans.Run();

    return 0;
}
