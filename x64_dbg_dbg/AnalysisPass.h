#pragma once

#include "_global.h"
#include "BasicBlock.h"

class AnalysisPass
{
public:
    AnalysisPass(uint VirtualStart, uint VirtualEnd, BBlockArray & MainBlocks);
    virtual ~AnalysisPass();

    virtual const char* GetName() = 0;
    virtual bool Analyse() = 0;

protected:
    uint m_VirtualStart;
    uint m_VirtualEnd;
    uint m_DataSize;
    unsigned char* m_Data;
    BBlockArray & m_MainBlocks;

    inline unsigned char* AnalysisPass::TranslateAddress(uint Address)
    {
        assert(ValidateAddress(Address));

        return &m_Data[Address - m_VirtualStart];
    }

    inline bool AnalysisPass::ValidateAddress(uint Address)
    {
        return (Address >= m_VirtualStart && Address < m_VirtualEnd);
    }

    BasicBlock* FindBBlockInRange(uint Address);
    uint FindBBlockIndex(BasicBlock* Block);
    uint IdealThreadCount();
    void SetIdealThreadCount(uint Count);

private:
    BYTE m_InternalMaxThreads;
};