/*
 * Names: Ramiz Alhaddad, Sanshit Sagar
 * Date: May 18th 2017
 * Description: This file will be used to read the bits from
 * the buffer to decode later.
 * PA3
 */

#include "BitInputStream.h" 
#define EMPTY 8
#define ONE 0x11111111
/*
 * read bits from buffer.
 */ 
int BitInputStream::readBit() {
if(count== 0) { 
	input >> buffer; 
	std::cout << buffer << std::endl; 
	count = 0; 
	if(!(input.good())) {return -1;}
}
if(input.good()){
  	int returner;
	if(((buffer >> (7-count)) & 1)== 1){
    returner = 1;  
  }
  else if (((buffer >> (7-count)) & 1)== 0) {
    returner = 0;
  }
  count ++;
  return returner; }
else{
  return -1;
    }
}	 
