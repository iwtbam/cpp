#ifndef IWTBAM_CHUNK_H
#define IWTBAM_CHUNK_H

#include <cstddef>

namespace iwtbam
{


struct Chunk
{
    void Init(std::size_t blockSize, unsigned char blocks);
    void Release();
    void* Allocate(std::size_t blockSize);
    void Deallocate(void* p, std::size_t blockSize);
    unsigned char* pData;
    unsigned char firstAvailableBlock, blocksAvaiable;
};


};

#endif //IWTBAM_CHUNCK_H