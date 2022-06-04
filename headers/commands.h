//
// Created by mikipaw on 16.10.2020.
//

#define DO_PUSH {                                                   \
integ = (int64_t) array[++i];                                       \
if(integ == 0) {                                                    \
    second = array[++i];                                            \
    if (second < 4) {bytecode[ind++] = PushSmallNum; bytecode[ind++] = second;}\
    else {                                                          \
    bytecode[ind++] = (PushNum); bytecode[ind++] = second;          \
    bytecode[ind++] = 0; bytecode[ind++] = 0; bytecode[ind++] = 0;  \
    }                                                               \
    }                                                               \
    else if (integ < 10 && integ != 5){                             \
        bytecode[ind++] = (SaveReg);                                \
        bytecode[ind++] = (SavePush + integ - 1);                   \
    }                                                               \
    else {                                                          \
        second = array[++i];                                        \
        if (second == 0) second = array[++i];                       \
        bytecode[ind++] = (MovEspNum);  bytecode[ind++] = second;   \
        bytecode[ind++] = (PushEsp);                                \
    }                                                               \
    stk_size++;                                                     \
};                                                                  \


#define DO_POP {                                        \
integ = (int64_t) array[++i];                           \
if (integ == 5) bytecode[ind++] = (PopEsp);             \
else { bytecode[ind++] = (SaveReg);                     \
bytecode[ind++] = (SavePop + integ - 1);                \
}                                                       \
stk_size--;                                             \
};                                                      \

//pop rax pop rbx add rax rbx push rax
#define DO_ADD {                    \
if(stk_size < 1)                    \
{                                   \
    return EMPTY_STACK;             \
}                                   \
bytecode[ind++] = (PopEax);         \
bytecode[ind++] = (PopEcx);         \
bytecode[ind++] = (0x01);           \
bytecode[ind++] = (0xc8);           \
bytecode[ind++] = (PushEax);        \
stk_size--;                         \
};                                  \


#define DO_SUB {                    \
if(stk_size < 2) {                  \
    return EMPTY_STACK;             \
}                                   \
bytecode[ind++] = (PopEax);         \
bytecode[ind++] = (PopEcx);         \
bytecode[ind++] = (0x29);           \
bytecode[ind++] = (0xc1);           \
bytecode[ind++] = (PushEcx);        \
stk_size--;                         \
};                                  \


#define DO_MUL {                    \
if(stk_size < 2)                    \
{                                   \
    return EMPTY_STACK;             \
}                                   \
bytecode[ind++] = (PopEax);         \
bytecode[ind++] = (PopEcx);         \
bytecode[ind++] = (Mul);            \
bytecode[ind++] = 0xe1;             \
bytecode[ind++] = (PushEax);        \
stk_size--;                         \
};                                  \


#define DO_DIV {                    \
if(stk_size < 2)                    \
{                                   \
return EMPTY_STACK;                 \
}                                   \
bytecode[ind++] = (PopEax);         \
bytecode[ind++] = (PopEcx);         \
bytecode[ind++] = (Div);            \
bytecode[ind++] = 0xf1;             \
bytecode[ind++] = (PushEax);        \
stk_size--;                         \
};                                  \


#define DO_NEG {                    \
bytecode[ind++] = (PopEax);         \
bytecode[ind++] = (Neg);            \
bytecode[ind++] = (0xd8);           \
bytecode[ind++] = (PushEax);        \
};                                  \


#define DO_SINUS {                  \
bytecode[ind++] = (Nop);            \
};                                  \


#define DO_COS {                    \
bytecode[ind++] = (Nop);            \
};                                  \

#define DO_SQRT {                   \
bytecode[ind++] = 0xd9;             \
bytecode[ind++] = 0xfa;             \
};                                  \

#define DO_POW {                    \
bytecode[ind++] = (Nop);            \
};                                  \


#define DO_IN { \
first = 5;                          \
bytecode[ind++] = (PushSmallNum);   \
bytecode[ind++] = first;            \
stk_size++;                         \
};                                  \

#define DO_INN { \
first = input_numbers[input_index++];\
bytecode[ind++] = (PushSmallNum);   \
bytecode[ind++] = first;            \
stk_size++;                         \
};


#define DO_OUT {                    \
bytecode[ind++] = PopEdi;           \
bytecode[ind++] = 0x48;             \
bytecode[ind++] = 0xba;             \
*(unsigned long long*)(bytecode + ind++) = (unsigned long long)prints; \
ind += 7;                           \
bytecode[ind++] = 0xb0;             \
bytecode[ind++] = 0x02;             \
bytecode[ind++] = 0xff;             \
bytecode[ind++] = 0xd2;             \
stk_size--;                         \
};                                  \


#define DO_DUMP { \
bytecode[ind++] = (Nop);            \
};                                  \


#define DO_HLT {                    \
bytecode[ind++] = (Ret);            \
};                                  \


#define DO_JMP {                    \
integ = (int64_t) (array[++i]);     \
second = compute_dist(i, integ);    \
if (second < 0) {bytecode[ind++] = (Jmp); bytecode[ind++] = 0xff + second + 6;}    \
else {bytecode[ind++] = (Jmp); bytecode[ind++] = -second + 6;}                     \
};                                  \

#define DO_CALL {                    \
integ = (int64_t) (array[++i]);     \
second = compute_dist(i, integ);    \
if (second < 0) {bytecode[ind++] = (Call); bytecode[ind++] = 0xff + second + 7;} \
else {bytecode[ind++] = (Call); bytecode[ind++] = second + 12; bytecode[ind++] = 0x0; bytecode[ind++] = 0x0;bytecode[ind++] = 0x0; } \
};                                  \


#define DO_JA {                                                     \
integ = (int64_t) array[++i];                                       \
if(stk_size < 2)                                                    \
    return EMPTY_STACK;                                             \
bytecode[ind++] = (PopEax);                                         \
bytecode[ind++] = (PopEbx);                                         \
bytecode[ind++] = (Cmp);                                            \
bytecode[ind++] = 0xc3;                                             \
second = compute_dist(i, integ);                                    \
if (second < 0) {bytecode[ind++] = (Ja); bytecode[ind++] = 0xff + second;} \
else {bytecode[ind++] = (Ja); bytecode[ind++] = second; }           \
stk_size -= 2;                                                      \
};                                                                  \


#define DO_JAE {                                                    \
integ = (int64_t) array[++i];                                       \
if(stk_size < 2)                                                    \
    return EMPTY_STACK;                                             \
bytecode[ind++] = (PopEax);                                         \
bytecode[ind++] = (PopEbx);                                         \
bytecode[ind++] = (Cmp);                                            \
bytecode[ind++] = 0xc3;                                             \
second = compute_dist(i, integ);                                    \
if (second < 0) {bytecode[ind++] = (Jae); bytecode[ind++] = 0xff + second + 6;} \
else {bytecode[ind++] = (Jae); bytecode[ind++] = second - 6; }      \
stk_size -= 2;                                                      \
};                                                                  \


#define DO_JB {                                                     \
integ = (int64_t) array[++i];                                       \
if(stk_size < 2)                                                    \
    return EMPTY_STACK;                                             \
bytecode[ind++] = (PopEax);                                         \
bytecode[ind++] = (PopEbx);                                         \
bytecode[ind++] = (Cmp);                                            \
bytecode[ind++] = 0xc3;                                             \
second = compute_dist(i, integ);                                    \
if (second < 0) {bytecode[ind++] = (Jb); bytecode[ind++] = 0xff + second + 1;} \
else {bytecode[ind++] = (Jb); bytecode[ind++] = -second - 1; }      \
stk_size -= 2;                                                      \
};                                                                  \


#define DO_JBE {                                                    \
integ = (int64_t) array[++i];                                       \
if(stk_size < 2)                                                    \
    return EMPTY_STACK;                                             \
bytecode[ind++] = (PopEax);                                         \
bytecode[ind++] = (PopEbx);                                         \
bytecode[ind++] = (Cmp);                                            \
bytecode[ind++] = 0xc3;                                             \
second = compute_dist(i, integ);                                    \
if (second < 0) {bytecode[ind++] = (Jbe); bytecode[ind++] = 0xff + second;} \
else {bytecode[ind++] = (Jbe); bytecode[ind++] = second; }          \
stk_size -= 2;                                                      \
};                                                                  \


#define DO_JE {                                                     \
integ = (int64_t) array[++i];                                       \
if(stk_size < 2)                                                    \
    return EMPTY_STACK;                                             \
bytecode[ind++] = (PopEax);                                         \
bytecode[ind++] = (PopEbx);                                         \
bytecode[ind++] = (Cmp);                                            \
bytecode[ind++] = 0xc3;                             /*cmp eax, ebx*/                \
second = compute_dist(i, integ);                                    \
if (second < 0) {bytecode[ind++] = (Je); bytecode[ind++] = 0xff + second;} \
else {bytecode[ind++] = (Je); bytecode[ind++] = second; }           \
stk_size -= 2;                                                      \
};                                                                  \


#define DO_JNE {                                                    \
integ = (int64_t) array[++i];                                       \
if(stk_size < 2)                                                    \
    return EMPTY_STACK;                                             \
bytecode[ind++] = (PopEax);                                         \
bytecode[ind++] = (PopEbx);                                         \
bytecode[ind++] = (Cmp);                                            \
bytecode[ind++] = 0xc3;                                             \
second = compute_dist(i, integ);                                    \
if (second < 0) {bytecode[ind++] = (Jne); bytecode[ind++] = 0xff + second + 1;} \
else {bytecode[ind++] = (Jne); bytecode[ind++] = second - 1;}  \
stk_size -= 2;                                                      \
};                                                                  \


#define DO_MOD {                                \
bytecode[ind++] = (Nop);                        \
};                                              \


#define DO_INT {                                \
bytecode[ind++] = (Nop);                        \
};                                              \


#define DO_RET {                                    \
bytecode[ind++] = Ret;                                \
};                                                  \


#define DO_IDIV { \
bytecode[ind++] = (Nop);                    \
};                                          \


#define DO_COMP {                           \
bytecode[ind++] = (Nop);                    \
};                                          \


DEF_CMD( PUSH,  40,   {DO_PUSH}, 320)
DEF_CMD( POP,   20,   {DO_POP},  239)
DEF_CMD( ADD,   0,    {DO_ADD},  201)
DEF_CMD( SUB,   1,    {DO_SUB},  234)
DEF_CMD( MUL,   2,    {DO_MUL},  238)
DEF_CMD( DIV,   3,    {DO_DIV},  227)
DEF_CMD( NEG,   4,    {DO_NEG},  218)
DEF_CMD( SINUS, 5,    {DO_SINUS},402)
DEF_CMD( COS,   6,    {DO_COS},  229)
DEF_CMD( SQRT,  7,    {DO_SQRT}, 330)
DEF_CMD( POW,   8,    {DO_POW},  246)
DEF_CMD( IN,    9,    {DO_IN},   151)
DEF_CMD( OUT,   10,   {DO_OUT},  248)
DEF_CMD( DUMP,  11,   {DO_DUMP}, 310)
DEF_CMD( HLT,   12,   {DO_HLT},  232)
DEF_CMD( JMP,   21,   {DO_JMP},  231)
DEF_CMD( JA ,   22,   {DO_JA},   139)
DEF_CMD( JAE,   23,   {DO_JAE},  208)
DEF_CMD( JB ,   24,   {DO_JB},   140)
DEF_CMD( JBE,   25,   {DO_JBE},  209)
DEF_CMD( JE ,   26,   {DO_JE},   143)
DEF_CMD( JNE,   27,   {DO_JNE},  221)
DEF_CMD( MOD,   13,   {DO_MOD},  224)
DEF_CMD( IDIV,  14,   {DO_IDIV}, 300)
DEF_CMD( TINT,  15,   {DO_INT},  319)
DEF_CMD( RET,   16,   {DO_RET},  235)
DEF_CMD( EQ,    17,   {DO_COMP}, 150)
DEF_CMD( CALL,  29,   {DO_CALL}, 284)
