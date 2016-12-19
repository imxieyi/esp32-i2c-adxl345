#ifndef __ADXL345_H__
#define __ADXL345_H__
#include "stdint.h"
#include "stdbool.h"

void initAcc(uint8_t scl_pin, uint8_t sda_pin);
void getAccelerometerData(int *result);

#endif
