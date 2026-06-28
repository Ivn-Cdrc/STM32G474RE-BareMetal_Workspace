//Where is the LED connected?
// Port: A (GPIOA)
// Pin: 5

// Defining the beginning or the starting point of the peripheral memory block (ref. to reference manual)
// NOTE: BASE simply means starting point when referring to memory addresses
#define PERIPH_BASE         (0x40000000UL)
#define AHB2PERIPH_OFFSET   (0x08000000UL)

// GPIOA starts at 0x48000000. To arrive at this memory address with can add an offset to the PERIPH_BASE
// 0x40000000 + 0x08000000 = 0x48000000
#define AHB2PERIPH_BASE     (PERIPH_BASE + AHB2PERIPH_OFFSET)

// While the address of AHB2 AND GPIOA are identical, I am declaring GPIO_BASE below for clarity
#define GPIOA_OFFSET        (0x0000U) // We don't have to type 8 zeros here, even a single zero is sufficient
#define GPIOA_BASE          (AHB2PERIPH_BASE + GPIOA_OFFSET)

// RCC (Resetting Clock Control) is not in AHB2, but in AHB1. RCC will enable clock access for GPIOA
// Therefore we will have to define AHB1PERIPH_BASE to delineate RCC_BASE
#define AHB1PERIPH_OFFSET   (0x00020000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define RCC_OFFSET          (0x1000U)
#define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)