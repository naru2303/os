/*< Sets entry point address */
ENTRY(Reset_Handler)

/**
*   @brief Defining flash/ram sections
*           page 76 of RM to find their locations in memory
*/
MEMORY
{
    FLASH(rx)   : ORIGIN =0x8000000, LENGTH =1024K 
    SRAM(xrw)   : ORIGIN =0x20000000, LENGTH =320K  
}

/*< Symbol declarations for heap and stack size */
__max_heap_size = 0x400; 
__max_stack_size = 0x200;

/**
*
*/
SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(8);
        _etext = .; /*< storing value of location counter in symbol etext */
    } >FLASH

    .data :
    {
        _sdata = .; /*< Storing start of data section location  */
        *(.data)
        . = ALIGN(8);
        _edata = .; /*< Storing end of data section location */
    } >SRAM AT> FLASH /*< Take from SRAM to FLASH */

    .bss :
    {
        _sbss = .; /*< Storing start of bss section location */
        *(.bss)
        *(COMMON)
        . = ALIGN(8);
        _ebss = .; /*< Storing end of bss section location */
    } >SRAM
}