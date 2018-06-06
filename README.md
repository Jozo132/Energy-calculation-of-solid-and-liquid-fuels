# Energy calculation of solid and liquid fuels
Programmed and compiled in Arduino IDE

Compiled code ran on a Maple Mini (STM32F103CBT6)

This is an example of a standard way to calculate the energy of a liquid or solid fuel.

We calculate how much energy was needed by the difference 
in temperature of the water by burning our fuel for any amount of time.
What's important is proper measurements of the weight of water [grams], 
the weight of the fuel [grams] which was lost during the process and the
amount of temperature increase [deg C].

The results of the example program are in MJ/kg and kWh/kg.

Used MCU specs: 32-bit, 72MHz, 120kb flash, 20kb ram, Bootloader 2.0
    
     Beware! 
      Some functions need to be changed to work right with classic 8-bit MCUs
     This is an example I wrote to calculate fuel energy from
     the heating of water.
    
   ######################################################################### 
   ###                                                                   ###
   ###  Energy of fuel calculation ...                                   ###
   ###          Mass of water = 7500.0 [gram]                            ###
   ###          Mass of burned fuel = 5.00 [gram]                        ###
   ###          Difference in temperature = 5.0 [deg C]                  ###
   ###                                                                   ###
   ###          Energy of fuel [MJ] per kg = 31.380 [MJ/kg]              ###
   ###          Energy of fuel [kWh] per kg = 8.717 [kWh/kg]             ###
   ###  0.000624 seconds to calculate AND transmit the data over USB     ###
   ###                                                                   ###
   #########################################################################

Hopefully this helps someone who has problems with the implementation of the functions.