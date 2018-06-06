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



Hopefully this helps someone who has problems with the implementation of the functions.