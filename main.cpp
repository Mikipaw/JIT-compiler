#include <cstdio>
#include <ctime>

#include "headers/Assembler.h"
#include "headers/Translator.h"

//TODO: compare with cpu from 1st sem

int main() {
    int number_of_cmds = 250;

    long time = clock();
    CREATE_TRANSLATOR(trans, number_of_cmds, 1.0);

    trans.Work();
    trans.Run();
    printf("\nProgramm time = %.6f sec\n", float(clock() - time) / CLOCKS_PER_SEC);

    return 0;
}
