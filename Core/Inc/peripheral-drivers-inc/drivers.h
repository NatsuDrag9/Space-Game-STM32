/*
 * peripheral_drivers.h
 *
 */

#ifndef INC_PERIPHERAL_DRIVERS_INC_DRIVERS_H_
#define INC_PERIPHERAL_DRIVERS_INC_DRIVERS_H_

#include "stm32f4xx_hal.h"

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
SPI_HandleTypeDef hspi1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim4;
RNG_HandleTypeDef hrng;

#define USER_Btn_Pin GPIO_PIN_13
#define USER_Btn_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define LD1_Green_Pin GPIO_PIN_0
#define LD1_Green_GPIO_Port GPIOB
#define OLED_RES_Pin GPIO_PIN_12
#define OLED_RES_GPIO_Port GPIOF
#define GPIO_Input_B1_Pin GPIO_PIN_13
#define GPIO_Input_B1_GPIO_Port GPIOF
#define GPIO_Input_B2_Pin GPIO_PIN_14
#define GPIO_Input_B2_GPIO_Port GPIOF
#define LD3_Red_Pin GPIO_PIN_14
#define LD3_Red_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define OLED_CS_Pin GPIO_PIN_14
#define OLED_CS_GPIO_Port GPIOD
#define OLED_DC_Pin GPIO_PIN_15
#define OLED_DC_GPIO_Port GPIOD
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define LD2_Blue_Pin GPIO_PIN_7
#define LD2_Blue_GPIO_Port GPIOB

/* Driver functions prototype */
void Error_Handler(void);
void drivers_init(void);
void generate_randomNumber(uint32_t*);
uint8_t button_readPin(GPIO_TypeDef*, uint16_t);

#endif /* INC_PERIPHERAL_DRIVERS_INC_DRIVERS_H_ */
