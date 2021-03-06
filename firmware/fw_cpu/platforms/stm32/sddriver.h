#ifndef SDDRIVER_H
#define SDDRIVER_H

#include "stm32_inc.h"
#include "fatfs.h"

#define SD_PRESENT      0x01
#define SD_NOT_PRESENT  0x00
#define SD_DATATIMEOUT  ((uint32_t)100000000)

class SDDriver
{
public:
    void init_gpio();

    static bool is_card_present();

    uint8_t init(uint8_t);
    uint8_t status(uint8_t);
    uint8_t read(uint8_t lun, uint8_t*buf, uint32_t sector, uint32_t count);
    #if _USE_WRITE == 1
    uint8_t write(uint8_t, uint8_t*, uint32_t, uint32_t);
    #endif
    #if _USE_IOCTL == 1
    uint8_t ioctl(uint8_t, uint8_t, void*);
    #endif
private:
    uint8_t m_state;
};

extern SDDriver sd_driver;

#endif // SDDRIVER_H
