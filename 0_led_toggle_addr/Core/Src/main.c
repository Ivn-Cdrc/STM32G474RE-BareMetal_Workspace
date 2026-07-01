//Where is the LED connected?
// Port: A (GPIOA)
// Pin: 5
// Bus: AHB2

// Defining the beginning or the starting point of the peripheral memory block (ref. to reference manual)
// NOTE: BASE simply means starting point when referring to memory addresses
#define PERIPH_BASE         (0x40000000UL)
#define AHB2PERIPH_OFFSET   (0x08000000UL)

// GPIOA starts at 0x48000000. To arrive at this memory address with can add an offset to the PERIPH_BASE
// 0x40000000 + 0x08000000 = 0x48000000
#define AHB2PERIPH_BASE     (PERIPH_BASE + AHB2PERIPH_OFFSET)

// While the address of AHB2 AND GPIOA are identical, I am declaring GPIO_BASE below for clarity
#define GPIOA_OFFSET        (0x0000UL) // We don't have to type 8 zeros here, even a single zero is sufficient
#define GPIOA_BASE          (AHB2PERIPH_BASE + GPIOA_OFFSET)

// RCC (Resetting Clock Control) is not in AHB2, but in AHB1. RCC will enable clock access for GPIOA
// Therefore we will have to define AHB1PERIPH_BASE to delineate RCC_BASE
#define AHB1PERIPH_OFFSET   (0x00020000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define RCC_OFFSET          (0x1000UL)
#define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)

// Enable AHB2 clock access with RCC
#define AHB2EN_R_OFFSET     (0x4CUL)
// Typecase tells compiler to stop treating the address as a regular number and treat it as a memory pointer
// Dereferencing then allows us to interact with the value associated with the memory address
#define RCC_AHB2EN_R        (*(volatile unsigned int *) (RCC_BASE + AHB2EN_R_OFFSET))

// MODER register defines if GPIO PIN is set to either an input or output PIN
#define MODE_R_OFFSET       (0x00UL)
#define GPIOA_MODER         (*(volatile unsigned int *) (GPIOA_BASE + MODE_R_OFFSET))

// ODR (Output Data Register)
#define OD_R_OFFSET         (0x14UL)
#define GPIOA_ODR           (*(volatile unsigned int *) (GPIOA_BASE + OD_R_OFFSET))

// 0b 0000 0000 0000 0000 0000 0000 0000 0001 - In other words, shift 1 at the position of zero
// We can think of the above as the state of the register
// (1U<<4) means 0b 0000 0000 0000 0000 0000 0000 0001 0000
#define GPIOAEN             (1U<<0) 

// Change the value of Bit-5 in GPIOA_ODR to light up LED in PIN 5
#define PIN5                (1U<<5)
#define LED_PIN             PIN5

// Reset value: 0xABFF FFFF (for port A), so we will have to set the value of bit 10 & 11 to 1 & 0 respectively
// (1U<<10) Set bit 10 to 1
//  &=~(1U<<11) Set bit 11 to 0 by inverting 1 (NOT 1) using tilde operator
