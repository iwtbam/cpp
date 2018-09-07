#include "chunk.hpp"
#include <cassert>

namespace iwtbam
{


    void Chunk::Init(std::size_t blockSize, unsigned char blocks)
    {
        pData = new unsigned char[blockSize * blocks];
        firstAvailableBlock = 0;
        blocksAvaiable = blocks;
        unsigned char i = 0;
        unsigned char* p = pData;
        for(;i!=blocks;p+=blockSize)
            *p = ++i;
    }

    void* Chunk::Allocate(std::size_t blockSize)
    {
        if(!blocksAvaiable)
            return 0;
        unsigned char* pResult = pData + (firstAvailableBlock * blockSize);
        firstAvailableBlock = *pResult;
        --blocksAvaiable;
        return pResult;
    }

    void Chunk::Deallocate(void* p, std::size_t blockSize)
    {
        assert(p > pData);
        unsigned char* toRelease = static_cast<unsigned char*>(p);
        assert((toRelease-pData) % blockSize == 0);
        *toRelease = firstAvailableBlock;
        firstAvailableBlock = static_cast<unsigned char>((toRelease-pData)%blockSize);
        assert( firstAvailableBlock == (toRelease - pData)/blockSize);
        ++blocksAvaiable;
    }






}