#ifndef __NB_NRFTEMPERATURE
#define __NB_NRFTEMPERATURE

#include "nworkbench.h"

class nBlock_nRFTemperature: public nBlockSimpleNode<1> {
public:
    nBlock_nRFTemperature();
    void triggerInput(nBlocks_Message message);
    void endFrame(void);
};

#endif
