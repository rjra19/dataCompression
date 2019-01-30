/*
 * Names: Ramiz Alhaddad, Sanshit Sagar
 * Date: May 18th 2017
 * Description: This file will write the bits into the buffer
 * and will flush the buffer when needed.
 * PA3
 */ 

#include "BitOutputStream.h"
#define EMPTY 8
#define ONE 0x00000001
/*
 * write bits into the buffer.
 */
void BitOutputStream::writeBit(int bit) {

if(output.good()) {
buffer = buffer |(bit << (7-count)); 
count++;

if(count==8) 
	{ 
	flush(); 
	}
  }
}
/*
 * flush the buffer when full.
 */ 
void BitOutputStream::flush() {
output.put(buffer); 
output.flush(); 
buffer = 0; 
count = 0; 
}
