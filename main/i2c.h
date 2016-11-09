#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

// Init bitbanging I2C driver on given pins
void i2c_init(uint8_t scl_pin, uint8_t sda_pin);

// Write a byte to I2C bus. Return true if slave acked.
bool i2c_write(uint8_t byte);

// Read a byte from I2C bus. Return true if slave acked.
uint8_t i2c_read(bool ack);

// Write 'len' bytes from 'buf' to slave. Return true if slave acked.
bool i2c_slave_write(uint8_t slave_addr, uint8_t *buf, uint8_t len);
bool i2c_slave_write_with_reg(uint8_t slave_addr,uint8_t reg_addr, uint8_t data);
// Issue a read operation and send 'data', followed by reading 'len' bytes
// from slave into 'buf'. Return true if slave acked.
bool i2c_slave_read(uint8_t slave_addr, uint8_t data, uint8_t *buf, uint32_t len);

// Send start and stop conditions. Only needed when implementing protocols for
// devices where the i2c_slave_[read|write] functions above are of no use.
void i2c_start(void);
void i2c_stop(void);

#ifdef	__cplusplus
}
#endif

#endif /* __I2C_H__ */
