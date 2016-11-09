#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "stdint.h"
#include "stdbool.h"
#include "driver/gpio.h"
#include "adxl345.h"
#include "i2c.h"

#define ACC (0x53)//(0xA7>>1)
#define A_TO_READ (6)
static const char *TAG = "adxl345";

// Write val to address register on ACC
void writeTo(uint8_t DEVICE, uint8_t address, uint8_t val) {
	if (!i2c_slave_write_with_reg(DEVICE, address, val)) {
		ESP_LOGE(TAG, "I2C write error");
	}
}

// Read num bytes starting from address register on ACC in to buff array
void readFrom(uint8_t DEVICE, uint8_t address, uint8_t num, uint8_t buff[]) {
	if (!i2c_slave_read(DEVICE, address, buff, num)) {
		ESP_LOGE(TAG, "I2C read error");
	}
}

void initAcc(uint8_t scl_pin, uint8_t sda_pin) {
	// Turning on ADXL345
	i2c_init(scl_pin, sda_pin);
	writeTo(ACC, 0x2D, 1 << 3);
	writeTo(ACC, 0x31, 0x0B);
	writeTo(ACC, 0x2C, 0x09);
}

void getAccelerometerData(int *result) {
	uint8_t regAddress = 0x32;
	uint8_t buff[A_TO_READ];
	readFrom(ACC, regAddress, A_TO_READ, buff);
	result[0] = (((int) buff[1]) << 8) | buff[0];
	result[1] = (((int) buff[3]) << 8) | buff[2];
	result[2] = (((int) buff[5]) << 8) | buff[4];
}
