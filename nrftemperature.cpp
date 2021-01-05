#include "nrftemperature.h"


nBlock_nRFTemperature::nBlock_nRFTemperature() {
    outputType[0] = OUTPUT_TYPE_FLOAT;
}

void nBlock_nRFTemperature::triggerInput(nBlocks_Message message) {
    // There is only one input and it works as trigger
    // message data is not relevant
    
    NRF_TEMP->EVENTS_DATARDY = 0; // Clear DATARDY flag to be safe
    NRF_TEMP->TASKS_START = 1;    // Fire measurement task
}
void nBlock_nRFTemperature::endFrame(void) {
    // If we have data available
    if (NRF_TEMP->EVENTS_DATARDY) {
        NRF_TEMP->EVENTS_DATARDY = 0; // Clear DATARDY flag
        
        available[0] = 1;
        output[0] = PackFloat(NRF_TEMP->TEMP*0.25);
    }
}

