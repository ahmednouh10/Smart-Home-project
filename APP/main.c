/*
 * main.c
 *
 *  Created on: Aug 1, 2024
 *      Author: sohas
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Config.h"
#include "MCAL/DIO/DIO_Private.h"

#include "MCAL/GLOBAL_INT/GLOB_INT_Interface.h"
#include "MCAL/EXT_INT/EXT_INT_Interface.h"

#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/TIMER/TIMER_Config.h"
#include "MCAL/TIMER/TIMER_Private.h"


#include "HAL/LED/LED_Interface.h"
#include "HAL/LED/LED_Config.h"

#include "MCAL/UART/UART_Config.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/UART/UART_Private.h"

#include "MCAL/EEPROM/EEPROM_Config.h"
#include "MCAL/EEPROM/EEPROM_Interface.h"
#include "MCAL/EEPROM/EEPROM_Private.h"

#include "HAL/SOLENOID/SOL_Interface.h"
#include "HAL/SOLENOID/SOL_Config.h"

#include "HAL/BUZZER/BUZ_Interface.h"
#include "HAL/BUZZER/BUZ_Config.h"
#include "MCAL/ADC/ADC_Interface.h"

#include "HAL/dcmotor/dcmotor_interface.h"

#include <util/delay.h>
#include <stdlib.h>


#define F_CPU 8000000UL
#define PASSWORD_SIZE     4
#define NUMBER_OF_USERS   10
#define TEMP_THRESHOLD    30



/* 2D array for predefined passwords for the 10 users
 * each row corresponds to user password .
 * first dimension number of users
 * second dimension PASSWORD_SIZE represent length of each password the +1 to count null parameter at end of each string
 */
char PASSWORDS_FOR_USER[NUMBER_OF_USERS][PASSWORD_SIZE + 1] = {
    "1111", "2222", "3333", "4444", "5555",
    "6666", "7777", "8888", "9999", "0000"
};
/*function to write password stored in  PASSWORDS_OF_USER array to EEPROM
 * as each user password is written in specific location in EEPROM
 * 1)loops through each user 0 to 9
 * 2)* PASSWORDS_ FOR__USER[i]: This accesses the password of the i user.
*
* (void*) (i * PASSWORD_SIZE):This calculates the EEPROM address where the i user password should be stored.
*  The address is based on the user index i, multiplied by PASSWORD_SIZE to space out each password correctly in EEPROM.
* and addressing in eeprom do notoverlap and eeprom have suufient space to store all passwords
*
* PASSWORD_SIZE: Specifies the number of bytes to write for each password.(4 bytes +1 null terminator=5)
 */
void EEPROM_WriteBlockPasswords(void) {
    for (uint8_t i = 0; i < NUMBER_OF_USERS; i++) {
        EEPROM_WriteBlock(PASSWORDS_FOR_USER[i], (void*)(i * PASSWORD_SIZE), PASSWORD_SIZE);
    }
}
/*function reads a password for a specific user from the EEPROM
 * and stores it in the password provided  buffer
 * 1)function takes ID of the user whose password you want to read.
* and  A pointer to a character array where the retrieved password will be stored.
*/
void EEPROM_ReadBlockPassword(uint8_t user_id, char* password) {
    EEPROM_ReadBlock(password, (const void*)(user_id * PASSWORD_SIZE), PASSWORD_SIZE);
    password[PASSWORD_SIZE] = '\0';
}





int main(void) {
    char received_ID;
    char received_password[PASSWORD_SIZE + 1];
    char stored_password[PASSWORD_SIZE + 1];
    uint8_t attempts = 3;
    uint8_t user_id = 0;
    uint8_t num = 0;

    // Initialize peripherals
    UART_init();
    LED_init();
    Solenoid_init();
    Buzzer_init();
    DC_Motor_Init();

    // Write initial passwords to EEPROM
    EEPROM_WriteBlockPasswords();

    while (1) {
        do {
            UART_SendString("Enter user ID (1-10): ");
            received_ID = UART_RxChar() - '1'; // Convert '1'-'10' to 0-9

            if (received_ID < 0 || received_ID >= NUMBER_OF_USERS) {
                UART_SendString("Invalid User ID.\n");
            }
        } while (received_ID < 0 || received_ID >= NUMBER_OF_USERS);

        user_id = received_ID;

        while (attempts > 0) {
            UART_SendString("Enter password: ");
            UART_ReceiveString(received_password, PASSWORD_SIZE + 1);

            EEPROM_ReadBlockPassword(user_id, stored_password);

            UART_SendString("\nReceived password: ");
            UART_SendString(received_password);
            UART_SendString("\n");

            if (strcmp(received_password, stored_password) == 0) {
                UART_SendString("Access granted.\n");

                UART_SendString("Choose an option:\n");
                UART_SendString("1. Open the door\n");
                UART_SendString("2. Control the light\n");
                UART_SendString("3. Control the fan\n");
                UART_SendString("Enter your choice: ");
                num = UART_RxChar() - '0'; // Convert choice to integer

                switch (num) {
                    case 1:
                        Solenoid_activate();
                        UART_SendString("Solenoid activated.\n");
                        _delay_ms(5000);
                        Solenoid_deactivate();
                        UART_SendString("Solenoid deactivated.\n");
                        break;

                    case 2:
                        UART_SendString("Press 1 to turn on LED, or 0 to turn off LED: ");
                        char led_control = UART_RxChar();

                        if (led_control == '1') {
                            LED_On();
                            UART_SendString("\nLED turned on.\n");
                        } else if (led_control == '0') {
                            LED_Off();
                            UART_SendString("\nLED turned off.\n");
                        } else {
                            UART_SendString("\nInvalid input. No action taken.\n");
                        }
                        break;

                    case 3:
                        UART_SendString("Press 1 to turn on fan, 0 to turn off fan: ");
                        char fan_control = UART_RxChar();

                        if (fan_control == '1') {
                            UART_SendString("Enter fan speed (0-100): ");
                            uint8_t fan_speed = UART_ReadNumber();

                            if (fan_speed <= 100) {
                                DC_Motor_On(fan_speed);
                                UART_SendString("Fan turned on at speed ");
                                UART_SendChar(fan_speed / 10 + '0'); // Display tens digit
                                UART_SendChar(fan_speed % 10 + '0'); // Display units digit
                                UART_SendString("%.\n");
                            } else {
                                UART_SendString("Invalid speed. Fan not controlled.\n");
                            }
                        } else if (fan_control == '0') {
                            DC_Motor_Off();
                            UART_SendString("Fan turned off.\n");
                        } else {
                            UART_SendString("Invalid input. No action taken.\n");
                        }
                        break;

                    default:
                        UART_SendString("Invalid choice.\n");
                        break;
                }
                break;
            } else {
                UART_SendString("Access denied.\n");
                attempts--;
            }
        }

        if (attempts == 0) {
            UART_SendString("Too many attempts. Alarm!\n");
            Buzzer_On();
            _delay_ms(10000);
            Buzzer_Off();
        }

        attempts = 3;
    }

    return 0;
}




