/**
 * Eduardo Diaz
 * 
 * Demonstration of a 4-bit R2R DAC.
 *
 * HARDWARE CONNECTIONS
 * - GPIO 0 ---> LSB input in R2R DAC
 * - GPIO 1 ---> BIT 1 input in R2R DAC
 * - GPIO 2 ---> BIT 2 input in R2R DAC
 * - GPIO 3 ---> MSB input in R2R DAC
 * - RP2040 GND ---> 4-bit DAC GND
 *
 */

 // Include standard libraries
 #include <stdio.h>
// Include PICO libraries
#include "pico/stdio.h"
#include "pico/stdlib.h"
// Include hardware libraries
#include "hardware/gpio.h"

#define BIT_0 0
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3

#define BITS 4

#define DELAY 10

int val = 0;
int added = 1;
int result = 0;

int main() {

    // Initialize stdio
    stdio_init_all();

    ////////////////////////////////////////////////////////////////////////
    ///////////////////////// GPIO CONFIGURATION ///////////////////////////
    ////////////////////////////////////////////////////////////////////////
    gpio_init(BIT_0);
    gpio_set_dir(BIT_0, GPIO_OUT);
    gpio_init(BIT_1);
    gpio_set_dir(BIT_1, GPIO_OUT);
    gpio_init(BIT_2);
    gpio_set_dir(BIT_2, GPIO_OUT);
    gpio_init(BIT_3);
    gpio_set_dir(BIT_3, GPIO_OUT);


    while (1) {
        // If LSB is set in val, set BIT_0 high
        if (val & 1) {
            gpio_put(BIT_0, 1);
        } else {
            gpio_put(BIT_0 , 0);
        }
        // If bit 1 is set in val, set BIT_1 HIGH
        if (val & 2) {
            gpio_put(BIT_1, 1);
        } else {
            gpio_put(BIT_1, 0);
        } // If bit 2 is set in val, set BIT_2 HIGH
        if (val & 4) {
            gpio_put(BIT_2, 1);
        } else {
            gpio_put(BIT_2, 0);
        }
        // If bit 3 is set in val, set BIT_3 HIGH
        if (val & 8) {
            gpio_put(BIT_3, 1);
        } else {
            gpio_put(BIT_3, 0);
        }

        if (BITS == 3) {
            // Range of values for 3 bit DAC is 0-7
            if (val == 7) {
                added = -1;
            }
        }

        if (BITS == 4) {
            // Range of values for 4 bit DAC is 0 - 15
            if (val == 15) {
                added = -1;
            }
        }

        if (val == 0) {
            added = 1;
        }

        val = val + added;
        // val = 4;

        // sleep_ms(DELAY);
        // sleep_us(1);

    }



}