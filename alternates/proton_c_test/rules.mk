# MCU name
MCU = STM32F303
CONSOLE_ENABLE = yes

RGBLIGHT_ENABLE = no
#WS2812_DRIVER = pwm

BACKLIGHT_ENABLE = no
#BACKLIGHT_DRIVER = pwm

AUDIO_ENABLE = no
#AUDIO_DRIVER = dac

EEPROM_DRIVER = spi

SRC += proton_c.c
