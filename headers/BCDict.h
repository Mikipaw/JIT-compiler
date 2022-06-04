//
// Created by mikhalinho on 02.05.22.
//

#ifndef JIT_COMPILER_BCDICT_H
#define JIT_COMPILER_BCDICT_H

#include <unistd.h>

enum class bc {
    //ret
        Ret = 0xc3,

    //nop
        Nop = 0x90,

    //mov
        //eax
            MovEaxEax = 0x89c0,
            MovEaxEbx = 0x89d8,
            MovEaxEcx = 0x89c8,
            MovEaxEdx = 0x89d0,
            MovEaxEsp = 0x89e0,
            MovEaxEbp = 0x89e8,
            MovEaxEsi = 0x89f0,
            MovEaxEdi = 0x89f8,

        //ebx
            MovEbxEax = 0x89c3,
            MovEbxEbx = 0x89db,
            MovEbxEcx = 0x89cb,
            MovEbxEdx = 0x89d3,
            MovEbxEsp = 0x89e3,
            MovEbxEbp = 0x89eb,
            MovEbxEsi = 0x89f3,
            MovEbxEdi = 0x89fb,

        //ecx
            MovEcxEax = 0x89c1,
            MovEcxEbx = 0x89d9,
            MovEcxEcx = 0x89c9,
            MovEcxEdx = 0x89d1,
            MovEcxEsp = 0x89e1,
            MovEcxEbp = 0x89e9,
            MovEcxEsi = 0x89f1,
            MovEcxEdi = 0x89f9,

        //edx
            MovEdxEax = 0x89c2,
            MovEdxEbx = 0x89da,
            MovEdxEcx = 0x89ca,
            MovEdxEdx = 0x89d2,
            MovEdxEsp = 0x89e2,
            MovEdxEbp = 0x89ea,
            MovEdxEsi = 0x89f2,
            MovEdxEdi = 0x89fa,

        //edi
            MovEdiEax = 0x89c7,
            MovEdiEbx = 0x89df,
            MovEdiEcx = 0x89cf,
            MovEdiEdx = 0x89d7,
            MovEdiEsp = 0x89e7,
            MovEdiEbp = 0x89ef,
            MovEdiEsi = 0x89f7,
            MovEdiEdi = 0x89ff,


        //esi
            MovEsiEax = 0x89c6,
            MovEsiEdx = 0x89d6,
            MovEsiEsp = 0x89e6,
            MovEsiEsi = 0x89f6,
            MovEsiEbx = 0x89de,
            MovEsiEcx = 0x89ce,
            MovEsiEbp = 0x89ee,
            MovEsiEdi = 0x89fe,

        //esp
            MovEspEax = 0x89c4,
            MovEspEdx = 0x89d4,
            MovEspEsp = 0x89e4,
            MovEspEsi = 0x89f4,
            MovEspEbx = 0x89dc,
            MovEspEcx = 0x89cc,
            MovEspEbp = 0x89ec,
            MovEspEdi = 0x89fc,


        //ebp
            MovEbpEax = 0x89c5,
            MovEbpEdx = 0x89d5,
            MovEbpEsp = 0x89e5,
            MovEbpEsi = 0x89f5,
            MovEbpEbx = 0x89dd,
            MovEbpEcx = 0x89cd,
            MovEbpEbp = 0x89ed,
            MovEbpEdi = 0x89fd,

        //reg <- num
            MovEaxNum = 0xb8,
            MovEspNum = 0xbc,
            MovEdxNum = 0xba,
            MovEsiNum = 0xbe,
            MovEbxNum = 0xbb,
            MovEcxNum = 0xb9,
            MovEbpNum = 0xbd,
            MovEdiNum = 0xbf,

        //reg <- dword[rax]
            MovEaxRamRax = 0x8b00,
            MovEdxRamRax = 0x8b10,
            MovEspRamRax = 0x8b20,
            MovEsiRamRax = 0x8b30,
            MovEcxRamRax = 0x8b08,
            MovEbxRamRax = 0x8b18,
            MovEbpRamRax = 0x8b28,
            MovEdiRamRax = 0x8b38,

        //reg <- dword[rcx]
            MovEaxRamRcx = 0x8b01,
            MovEdxRamRcx = 0x8b11,
            MovEspRamRcx = 0x8b21,
            MovEsiRamRcx = 0x8b31,
            MovEcxRamRcx = 0x8b09,
            MovEbxRamRcx = 0x8b19,
            MovEbpRamRcx = 0x8b29,
            MovEdiRamRcx = 0x8b39,

        //reg <- dword[rdx]
            MovEaxRamRdx = 0x8b02,
            MovEdxRamRdx = 0x8b12,
            MovEspRamRdx = 0x8b22,
            MovEsiRamRdx = 0x8b32,
            MovEcxRamRdx = 0x8b0a,
            MovEbxRamRdx = 0x8b1a,
            MovEbpRamRdx = 0x8b2a,
            MovEdiRamRdx = 0x8b3a,

        //reg <- dword[rbx]
            MovEaxRamRbx = 0x8b03,
            MovEdxRamRbx = 0x8b13,
            MovEspRamRbx = 0x8b23,
            MovEsiRamRbx = 0x8b33,
            MovEcxRamRbx = 0x8b0b,
            MovEbxRamRbx = 0x8b1b,
            MovEbpRamRbx = 0x8b2b,
            MovEdiRamRbx = 0x8b3b,

        //reg <- dword[rsp]
            MovEaxRamRsp = 0x8b0424,
            MovEdxRamRsp = 0x8b1424,
            MovEspRamRsp = 0x8b2424,
            MovEsiRamRsp = 0x8b3424,
            MovEcxRamRsp = 0x8b0c24,
            MovEbxRamRsp = 0x8b1c24,
            MovEbpRamRsp = 0x8b2c24,
            MovEdiRamRsp = 0x8b3c24,

        //reg <- dword[rbp]
            MovEaxRamRbp = 0x8b0500,
            MovEdxRamRbp = 0x8b1500,
            MovEspRamRbp = 0x8b2500,
            MovEsiRamRbp = 0x8b3500,
            MovEcxRamRbp = 0x8b0d00,
            MovEbxRamRbp = 0x8b1d00,
            MovEbpRamRbp = 0x8b2d00,
            MovEdiRamRbp = 0x8b3d00,
    
        //reg <- dword[rsi]
            MovEaxRamRsi = 0x8b06,
            MovEdxRamRsi = 0x8b16,
            MovEspRamRsi = 0x8b26,
            MovEsiRamRsi = 0x8b36,
            MovEcxRamRsi = 0x8b0e,
            MovEbxRamRsi = 0x8b1e,
            MovEbpRamRsi = 0x8b2e,
            MovEdiRamRsi = 0x8b3e,

        //reg <- dword[rdi]
            MovEaxRamRdi = 0x8b07,
            MovEdxRamRdi = 0x8b17,
            MovEspRamRdi = 0x8b27,
            MovEsiRamRdi = 0x8b37,
            MovEcxRamRdi = 0x8b0f,
            MovEbxRamRdi = 0x8b1f,
            MovEbpRamRdi = 0x8b2f,
            MovEdiRamRdi = 0x8b3f,

    //push
        //reg
            PushEax = 0x50,
            PushEdx = 0x52,
            PushEsp = 0x54,
            PushEsi = 0x56,
            PushEcx = 0x51,
            PushEbx = 0x53,
            PushEbp = 0x55,
            PushEdi = 0x57,

        SaveReg  = 0x41,
        SavePush = 0x50,
        SavePop  = 0x58,

        //number
            PushSmallNum = 0x6a,
            PushNum      = 0x68,

    //pop
        //reg
            PopEax = 0x58,
            PopEcx = 0x59,
            PopEdx = 0x5a,
            PopEbx = 0x5b,
            PopEsp = 0x5c,
            PopEbp = 0x5d,
            PopEsi = 0x5e,
            PopEdi = 0x5f,

    //add
        //reg + reg
            // eax
                AddEaxEax = 0x01c0,
                AddEaxEdx = 0x01d0,
                AddEaxEsp = 0x01e0,
                AddEaxEsi = 0x01f0,
                AddEaxEcx = 0x01c8,
                AddEaxEbx = 0x01d8,
                AddEaxEbp = 0x01e8,
                AddEaxEdi = 0x01f8,

            // ecx
                AddEcxEax = 0x01c1,
                AddEcxEdx = 0x01d1,
                AddEcxEsp = 0x01e1,
                AddEcxEsi = 0x01f1,
                AddEcxEcx = 0x01c9,
                AddEcxEbx = 0x01d9,
                AddEcxEbp = 0x01e9,
                AddEcxEdi = 0x01f9,


            // edx
                AddEdxEax = 0x01c2,
                AddEdxEdx = 0x01d2,
                AddEdxEsp = 0x01e2,
                AddEdxEsi = 0x01f2,
                AddEdxEcx = 0x01ca,
                AddEdxEbx = 0x01da,
                AddEdxEbp = 0x01ea,
                AddEdxEdi = 0x01fa,


            // ebx
                AddEbxEax = 0x01c3,
                AddEbxEdx = 0x01d3,
                AddEbxEsp = 0x01e3,
                AddEbxEsi = 0x01f3,
                AddEbxEcx = 0x01cb,
                AddEbxEbx = 0x01db,
                AddEbxEbp = 0x01eb,
                AddEbxEdi = 0x01fb,

            // esp
                AddEspEax = 0x01c4,
                AddEspEdx = 0x01d4,
                AddEspEsp = 0x01e4,
                AddEspEsi = 0x01f4,
                AddEspEcx = 0x01cc,
                AddEspEbx = 0x01dc,
                AddEspEbp = 0x01ec,
                AddEspEdi = 0x01fc,

            // ebp
                AddEbpEax = 0x01c5,
                AddEbpEdx = 0x01d5,
                AddEbpEsp = 0x01e5,
                AddEbpEsi = 0x01f5,
                AddEbpEcx = 0x01cd,
                AddEbpEbx = 0x01dd,
                AddEbpEbp = 0x01ed,
                AddEbpEdi = 0x01fd,

            // esi
                AddEsiEax = 0x01c6,
                AddEsiEdx = 0x01d6,
                AddEsiEsp = 0x01e6,
                AddEsiEsi = 0x01f6,
                AddEsiEcx = 0x01ce,
                AddEsiEbx = 0x01de,
                AddEsiEbp = 0x01ee,
                AddEsiEdi = 0x01fe,

            // edi
                AddEdiEax = 0x01c7,
                AddEdiEdx = 0x01d7,
                AddEdiEsp = 0x01e7,
                AddEdiEsi = 0x01f7,
                AddEdiEcx = 0x01cf,
                AddEdiEbx = 0x01df,
                AddEdiEbp = 0x01ef,
                AddEdiEdi = 0x01ff,


        //reg + num
            AddEax = 0x83c0,
            AddEcx = 0x83c1,
            AddEdx = 0x83c2,
            AddEbx = 0x83c3,
            AddEsp = 0x83c4,
            AddEbp = 0x83c5,
            AddEsi = 0x83c6,
            AddEdi = 0x83c7,


    //sub
        //reg - reg
             // eax
                SubEaxEax = 0x29c0,
                SubEaxEdx = 0x29d0,
                SubEaxEsp = 0x29e0,
                SubEaxEsi = 0x29f0,
                SubEaxEcx = 0x29c8,
                SubEaxEbx = 0x29d8,
                SubEaxEbp = 0x29e8,
                SubEaxEdi = 0x29f8,

            // ecx
                SubEcxEax = 0x29c1,
                SubEcxEdx = 0x29d1,
                SubEcxEsp = 0x29e1,
                SubEcxEsi = 0x29f1,
                SubEcxEcx = 0x29c9,
                SubEcxEbx = 0x29d9,
                SubEcxEbp = 0x29e9,
                SubEcxEdi = 0x29f9,


            // edx
                SubEdxEax = 0x29c2,
                SubEdxEdx = 0x29d2,
                SubEdxEsp = 0x29e2,
                SubEdxEsi = 0x29f2,
                SubEdxEcx = 0x29ca,
                SubEdxEbx = 0x29da,
                SubEdxEbp = 0x29ea,
                SubEdxEdi = 0x29fa,


            // ebx
                SubEbxEax = 0x29c3,
                SubEbxEdx = 0x29d3,
                SubEbxEsp = 0x29e3,
                SubEbxEsi = 0x29f3,
                SubEbxEcx = 0x29cb,
                SubEbxEbx = 0x29db,
                SubEbxEbp = 0x29eb,
                SubEbxEdi = 0x29fb,

            // esp
                SubEspEax = 0x29c4,
                SubEspEdx = 0x29d4,
                SubEspEsp = 0x29e4,
                SubEspEsi = 0x29f4,
                SubEspEcx = 0x29cc,
                SubEspEbx = 0x29dc,
                SubEspEbp = 0x29ec,
                SubEspEdi = 0x29fc,

            // ebp
                SubEbpEax = 0x29c5,
                SubEbpEdx = 0x29d5,
                SubEbpEsp = 0x29e5,
                SubEbpEsi = 0x29f5,
                SubEbpEcx = 0x29cd,
                SubEbpEbx = 0x29dd,
                SubEbpEbp = 0x29ed,
                SubEbpEdi = 0x29fd,

            // esi
                SubEsiEax = 0x29c6,
                SubEsiEdx = 0x29d6,
                SubEsiEsp = 0x29e6,
                SubEsiEsi = 0x29f6,
                SubEsiEcx = 0x29ce,
                SubEsiEbx = 0x29de,
                SubEsiEbp = 0x29ee,
                SubEsiEdi = 0x29fe,

            // edi
                SubEdiEax = 0x29c7,
                SubEdiEdx = 0x29d7,
                SubEdiEsp = 0x29e7,
                SubEdiEsi = 0x29f7,
                SubEdiEcx = 0x29cf,
                SubEdiEbx = 0x29df,
                SubEdiEbp = 0x29ef,
                SubEdiEdi = 0x29ff,


    //mul
        Mul = 0xf7,
        //reg
            MulEax = 0xf7e0,
            MulEdx = 0xf7e1,
            MulEsp = 0xf7e2,
            MulEsi = 0xf7e3,
            MulEcx = 0xf7e4,
            MulEbx = 0xf7e5,
            MulEbp = 0xf7e6,
            MulEdi = 0xf7e7,

    //div
        Div = 0xf7,
        //reg
            DivEax = 0xf7f0,
            DivEdx = 0xf7f1,
            DivEsp = 0xf7f2,
            DivEsi = 0xf7f3,
            DivEcx = 0xf7f4,
            DivEbx = 0xf7f5,
            DivEbp = 0xf7f6,
            DivEdi = 0xf7f7,


    //jmp (ja, jae...)
        Jb  = 0x72,
        Jae = 0x73,
        Je  = 0x74,
        Jne = 0x75,
        Jbe = 0x76,
        Ja  = 0x77,
        Jmp = 0xeb,

    //call
        Call = 0xe8,         //0xe8e2ffffff

    //cmp
        Cmp = 0x39,
        //reg
            // eax
                CmpEaxEax = 0x39c0,
                CmpEaxEdx = 0x39c8,
                CmpEaxEsp = 0x39d0,
                CmpEaxEsi = 0x39d8,
                CmpEaxEcx = 0x39e0,
                CmpEaxEbx = 0x39e8,
                CmpEaxEbp = 0x39f0,
                CmpEaxEdi = 0x39f8,

            // ecx
                CmpEcxEax = 0x39c1,
                CmpEcxEdx = 0x39c9,
                CmpEcxEsp = 0x39d1,
                CmpEcxEsi = 0x39d9,
                CmpEcxEcx = 0x39e1,
                CmpEcxEbx = 0x39e9,
                CmpEcxEbp = 0x39f1,
                CmpEcxEdi = 0x39f9,


            // edx
                CmpEdxEax = 0x39c2,
                CmpEdxEdx = 0x39ca,
                CmpEdxEsp = 0x39d2,
                CmpEdxEsi = 0x39da,
                CmpEdxEcx = 0x39e2,
                CmpEdxEbx = 0x39ea,
                CmpEdxEbp = 0x39f2,
                CmpEdxEdi = 0x39fa,


            // ebx
                CmpEbxEax = 0x39c3,
                CmpEbxEdx = 0x39cb,
                CmpEbxEsp = 0x39d3,
                CmpEbxEsi = 0x39db,
                CmpEbxEcx = 0x39e3,
                CmpEbxEbx = 0x39eb,
                CmpEbxEbp = 0x39f3,
                CmpEbxEdi = 0x39fb,

            // esp
                CmpEspEax = 0x01c4,
                CmpEspEdx = 0x01cc,
                CmpEspEsp = 0x01d4,
                CmpEspEsi = 0x01dc,
                CmpEspEcx = 0x01e4,
                CmpEspEbx = 0x01ec,
                CmpEspEbp = 0x01f4,
                CmpEspEdi = 0x01fc,

            // ebp
                CmpEbpEax = 0x39c5,
                CmpEbpEdx = 0x39cd,
                CmpEbpEsp = 0x39d5,
                CmpEbpEsi = 0x39dd,
                CmpEbpEcx = 0x39e5,
                CmpEbpEbx = 0x39ed,
                CmpEbpEbp = 0x39f5,
                CmpEbpEdi = 0x39fd,

            // esi
                CmpEsiEax = 0x39c6,
                CmpEsiEdx = 0x39ce,
                CmpEsiEsp = 0x39d6,
                CmpEsiEsi = 0x39de,
                CmpEsiEcx = 0x39e6,
                CmpEsiEbx = 0x39ee,
                CmpEsiEbp = 0x39f6,
                CmpEsiEdi = 0x39fe,

            // edi
                CmpEdiEax = 0x39c7,
                CmpEdiEdx = 0x39cf,
                CmpEdiEsp = 0x39d7,
                CmpEdiEsi = 0x39df,
                CmpEdiEcx = 0x39e7,
                CmpEdiEbx = 0x39ef,
                CmpEdiEbp = 0x39f7,
                CmpEdiEdi = 0x39ff,
        
        //dword [reg] + num
            CmpRamRax = 0x8138,
            CmpRamRcx = 0x8139,
            CmpRamRdx = 0x813a,
            CmpRamRbx = 0x813b,
            CmpRamRsp = 0x813c,
            CmpRamRbp = 0x813d,
            CmpRamRsi = 0x813e,
            CmpRamRdi = 0x813f,

        //dword [reg + num] + num || minus is equal to + with overflow
            CmpRamRaxPlus = 0x8178,
            CmpRamRcxPlus = 0x8179,
            CmpRamRdxPlus = 0x817a,
            CmpRamRbxPlus = 0x817b,
            CmpRamRspPlus = 0x817c24,
            CmpRamRbpPlus = 0x817d,
            CmpRamRsiPlus = 0x817e,
            CmpRamRdiPlus = 0x817f,

        //reg + qword [reg] ([reg + num], num = 0 in default)
            CmpRaxRam = 0x483b45,
            CmpRcxRam = 0x483b4d,
            CmpRdxRam = 0x483b55,
            CmpRbxRam = 0x483b5d,
            CmpRspRam = 0x483b65,
            CmpRbpRam = 0x483b6d,
            CmpRsiRam = 0x483b75,
            CmpRdiRam = 0x483b7d,

        //reg + num
            CmpEaxNum = 0x83f8,
            CmpEcxNum = 0x83f9,
            CmpEdxNum = 0x83fa,
            CmpEbxNum = 0x83fb,
            CmpEspNum = 0x83fc,
            CmpEbpNum = 0x83fd,
            CmpEsiNum = 0x83fe,
            CmpEdiNum = 0x83ff,

    //xor
        //reg
            XorEaxEax = 0x31c0,
            XorEcxEcx = 0x31c9,
            XorEdxEdx = 0x31d2,
            XorEbxEbx = 0x31db,
            XorEspEsp = 0x31e4,
            XorEbpEbp = 0x31ed,
            XorEsiEsi = 0x31f6,
            XorEdiEdi = 0x31ff,

        //num
            XorEaxNum = 0x83f0,
            XorEcxNum = 0x83f1,
            XorEdxNum = 0x83f2,
            XorEbxNum = 0x83f3,
            XorEspNum = 0x83f4,
            XorEbpNum = 0x83f5,
            XorEsiNum = 0x83f6,
            XorEdiNum = 0x83f7,

    //neg
            Neg = 0xf7,
        //reg
            NegEax = 0xf7d8,
            NegEcx = 0xf7d9,
            NegEdx = 0xf7da,
            NegEbx = 0xf7db,
            NegEsp = 0xf7dc,
            NegEbp = 0xf7dd,
            NegEsi = 0xf7de,
            NegEdi = 0xf7df,
};




#endif //JIT_COMPILER_BCDICT_H
