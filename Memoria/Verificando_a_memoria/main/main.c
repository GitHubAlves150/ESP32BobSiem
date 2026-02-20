#include <stdio.h>
#include <sdkconfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_system.h>
#include <esp_heap_caps.h>

// assinatura da função

void MemoryView();


void app_main(void){



    MemoryView();

    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}


void MemoryView(){

    int var;
    int var1=900;
    printf("Verificação de memoria\n");

    int HEAP =( xPortGetFreeHeapSize() )/1024;

    int DRAM =( heap_caps_get_free_size(MALLOC_CAP_8BIT) )/1024;
    int IRAM = (heap_caps_get_free_size(MALLOC_CAP_32BIT) )-(heap_caps_get_free_size(MALLOC_CAP_8BIT) )/1024; 
    int freeBlock = (heap_caps_get_largest_free_block(MALLOC_CAP_8BIT))/1024;

    printf("Heap %d kB\n ", HEAP);
    printf("DRAM %d kB\n ", DRAM);
    printf("IRAM %d kB ", IRAM);
    printf("maximum free Block %d kB\n ", freeBlock);

}