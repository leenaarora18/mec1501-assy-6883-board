/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

// /* 1000 msec = 1 sec */
// #define SLEEP_TIME_MS   1000

// /* The devicetree node identifier for the "led0" alias. */
// #define LED0_NODE DT_ALIAS(led0)

// /*
//  * A build error on this line means your board is unsupported.
//  * See the sample documentation for information on how to fix this.
//  */
// static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

// int main(void)
// {
// 	int ret;
// 	bool led_state = true;

// 	if (!gpio_is_ready_dt(&led)) {
// 		return 0;
// 	}

// 	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
// 	if (ret < 0) {
// 		return 0;
// 	}

// 	while (1) {
// 		ret = gpio_pin_toggle_dt(&led);
// 		if (ret < 0) {
// 			return 0;
// 		}

// 		led_state = !led_state;
// 		printf("LED state: %s\n", led_state ? "ON" : "OFF");
// 		k_msleep(SLEEP_TIME_MS);
// 	}
// 	return 0;
// }



/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS 1000

/* The devicetree node identifiers for the "led0", "led1", and "led2" aliases. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)

/*
 * A build error on these lines means your board is unsupported.
 */
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);

int main(void)
{
    int ret;
    bool led_state = true;

    /* Initialize all LEDs */
    if (!gpio_is_ready_dt(&led0) || !gpio_is_ready_dt(&led1) || !gpio_is_ready_dt(&led2)) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    while (1) {
        /* Toggle each LED */
        gpio_pin_toggle_dt(&led0);
        gpio_pin_toggle_dt(&led1);
        gpio_pin_toggle_dt(&led2);
			

        led_state = !led_state;
        printf("LED state: %s\n", led_state ? "ON" : "OFF");

        k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}
