#include <stdio.h>
#include "pico/stdlib.h"

#define MOTOR_A_IN1 0
#define MOTOR_A_IN2 1
#define MOTOR_B_IN1 2
#define MOTOR_B_IN2 3
#define LED_RED 12
#define LED_GREEN 11
#define LED_BLUE 10
#define RGB_COMMON_ANODE 1

static void output_init(uint pin, bool initial)
{
    gpio_init(pin);
    gpio_put(pin, initial);
    gpio_set_dir(pin, GPIO_OUT);
}

static void rgb(bool red, bool green, bool blue)
{
    gpio_put(LED_RED, RGB_COMMON_ANODE ? !red : red);
    gpio_put(LED_GREEN, RGB_COMMON_ANODE ? !green : green);
    gpio_put(LED_BLUE, RGB_COMMON_ANODE ? !blue : blue);
}

static void stop_motors(void)
{
    gpio_put(MOTOR_A_IN1, 0);
    gpio_put(MOTOR_A_IN2, 0);
    gpio_put(MOTOR_B_IN1, 0);
    gpio_put(MOTOR_B_IN2, 0);
}

static void test_motor(uint in1, uint in2, const char *name)
{
    for (int direction = 0; direction < 2; ++direction)
    {
        stop_motors();
        sleep_ms(1000);
        printf("Motor %s: sentido %d\n", name, direction + 1);
        gpio_put(in1, direction == 0);
        gpio_put(in2, direction != 0);
        sleep_ms(1500);
        stop_motors();
    }
}

int main(void)
{
    output_init(MOTOR_A_IN1, false);
    output_init(MOTOR_A_IN2, false);
    output_init(MOTOR_B_IN1, false);
    output_init(MOTOR_B_IN2, false);
    output_init(LED_RED, RGB_COMMON_ANODE);
    output_init(LED_GREEN, RGB_COMMON_ANODE);
    output_init(LED_BLUE, RGB_COMMON_ANODE);
    stdio_init_all();
    sleep_ms(5000);
    const bool colors[][3] = {
        {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    const char *names[] = {
        "vermelho", "verde", "azul", "amarelo", "ciano", "magenta", "branco"};
    for (uint i = 0; i < sizeof(colors) / sizeof(colors[0]); ++i)
    {
        printf("RGB: %s\n", names[i]);
        rgb(colors[i][0], colors[i][1], colors[i][2]);
        sleep_ms(1000);
        rgb(false, false, false);
        sleep_ms(250);
    }
    test_motor(MOTOR_A_IN1, MOTOR_A_IN2, "A");
    test_motor(MOTOR_B_IN1, MOTOR_B_IN2, "B");
    stop_motors();
    rgb(false, false, false);
    printf("Teste concluido. Reinicie o Pico para repetir.\n");
    while (true)
        tight_loop_contents();
}
