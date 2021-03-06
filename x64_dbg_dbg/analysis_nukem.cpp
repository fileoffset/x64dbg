#include "analysis_nukem.h"
#include "BasicBlock.h"
#include "LinearPass.h"
#include "FunctionPass.h"
#include "console.h"

void Analyse_nukem(uint base, uint size)
{
    dputs("Starting analysis (Nukem)...");
    DWORD ticks = GetTickCount();

    uint end = base + size;

    BBlockArray blocks;

    LinearPass* pass1 = new LinearPass(base, end, blocks);
    pass1->Analyse();

    FunctionPass* pass2 = new FunctionPass(base, end, blocks);
    pass2->Analyse();

    dprintf("Analysis finished in %ums!\n", GetTickCount() - ticks);
}