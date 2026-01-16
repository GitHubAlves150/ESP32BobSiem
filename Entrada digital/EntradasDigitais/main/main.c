#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"


#define PIN 14    //Pino de saida
#define BT_PIN 25 //Pino digital de entrada

void app_main(void)
{
    gpio_reset_pin(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

    gpio_reset_pin(BT_PIN);
    gpio_set_direction(BT_PIN, GPIO_MODE_OUTPUT);


    bool status=0;

    while (1)
    {
        status=gpio_get_level(BT_PIN); //pega o status do btn_pin
        gpio_set_level(PIN, status);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}
