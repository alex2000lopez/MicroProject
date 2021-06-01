/**
* @file floor.c
* @Author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 16/05/2021
* @brief Floor handler
*/

#include "floor.h"

uint32_t cfloor;
/** //Set the floor as ground
* @brief Initialize floor hardware
* @param void
* @return void
*/
void floor_Init(void){

	cfloor=0;
}

/**
* @brief Set floor
* @param current floor
* @return void
*/
void floorSet(uint32_t floor){
	cfloor=floor;
}
