/* 
    Written by Jozo132 <jozo132@gmail.com>, June 2018

     This is a program written in Arduino IDE.

     This program was designed for STM32duino hardware in mind,
     specifficaly Maple Mini and generic STM32F103C

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

   This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


float massOfWater = 7500.0;     // [g]    - This is the mass of the water that is being heated by the fuel in grams 
float massOfBurnedFuel = 5.0;   // [g]    - This is the mass which was lost by combustion/burning and heating the water in grams
float deltaT = 5.0;             // [deg C]- This is the temperature difference, for how much the water heated up in degrees celsius or Kelvin

float energyOfFuel_Cal_g;
float energyOfFuel_Cal_kg;
float energyOfFuel_J_kg;
float energyOfFuel_MJ_kg;
float energyOfFuel_kWh_kg;

long time_to_calculate;

/*  Or a short version for direct  Wh/kg calculation:
 *      float  Wh_kg = (4.184 * deltaT * massOfWater) / (3.6 * massOfBurnedFuel);
 *  Or a short version for direct kWh/kg calculation:
 *      float kWh_kg = (4.184 * deltaT * massOfWater) / (3600 * massOfBurnedFuel);
 */

void setup() {  // Run once on startup

  Serial.begin(250000);   // Begin serial with 250k baudrate
  while (!(Serial.isConnected() && (Serial.getDTR() )));  // Wait for serial monitor (needed for native USB serial)

  time_to_calculate = micros();   // Take note of the starting time before calculation and data transmission

  energyOfFuel_Cal_g   =  (deltaT * massOfWater) / (massOfBurnedFuel);  // Calories per g of fuel             (the whole function is a standard formula)
  energyOfFuel_Cal_kg  =  energyOfFuel_Cal_g * 1000;                    // Calories per g to calories per kg
  energyOfFuel_J_kg    =  4.184 * energyOfFuel_Cal_kg;                  // Joules per kg of fuel              (4.184 is the conversion constant)
  energyOfFuel_MJ_kg   =  energyOfFuel_J_kg * 0.000001;                 // Mega Joules per kg of fuel
  energyOfFuel_kWh_kg  =  energyOfFuel_MJ_kg / 3.6;                     // kilo-watt hours per kg of fuel

  char msg[250];  // Prepare an array of characters to store the serial output data -- WARNING, this character array uses A LOT of RAM
  sprintf(msg,    // Store calculated data in formatted character array -- WARNING, floating point conversion in 'sprintf' function doesn't work on 8-bit Atmel controllers as of writing this
          ("Energy of fuel calculation ...\n\tMass of water = %.1f [gram]\n\tMass of burned fuel = %.2f [gram]\n\tDifference in temperature = %.1f [deg C]\n\n\tEnergy of fuel [MJ] per kg = %.3f [MJ/kg]\n\tEnergy of fuel [kWh] per kg = %.3f [kWh/kg]"),
          massOfWater, massOfBurnedFuel, deltaT, energyOfFuel_MJ_kg, energyOfFuel_kWh_kg);
  Serial.println(msg);  // Print the computed data to the serial monitor

  Serial.print((float)(micros() - time_to_calculate) / 1000000.0, 6);   // Print out the time it took to calculate AND transmit the data over USB in seconds
  Serial.println(" seconds to calculate AND transmit the data over USB");
}

void loop() {
  // After 'setup()' do nothing
}

