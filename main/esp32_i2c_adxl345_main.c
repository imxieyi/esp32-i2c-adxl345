#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "adxl345.h"

#define SCL_PIN GPIO_NUM_5
#define SDA_PIN GPIO_NUM_4
static const char *TAG = "sensor";

static void sensorTask(void *pvParameters) {
	ESP_LOGI(TAG,"sensor task started\n");

	initAcc(SCL_PIN,SDA_PIN);
	ESP_LOGI(TAG,"accelerometer started");

	int acc[3];
	while (1) {
		getAccelerometerData(acc);
		ESP_LOGI(TAG,"X=%d,Y=%d,Z=%d\n",(int8_t)acc[0],(int8_t)acc[1],(int8_t)acc[2]);
		vTaskDelay(1000 / portTICK_RATE_MS);
	}

}

void app_main() {
	ESP_ERROR_CHECK(nvs_flash_init());
	system_init();
	ESP_LOGI("system","system inited");

	xTaskCreate(&sensorTask,	//pvTaskCode
			"sensorTask",//pcName
			4096,//usStackDepth
			NULL,//pvParameters
			4,//uxPriority
			NULL//pxCreatedTask
			);

}

