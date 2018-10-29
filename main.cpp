#include <vector> 
#include <iostream>
#include <fstream> 
#include <algorithm>
using namespace std;
#include "bintree.h"  
using namespace treespc;
#define MORSECODE_FILE  "morsecodes.txt" 

#include "encoder.h"
#include "decoder.h"

int main(int argc, char* argv[]) 
{
   encoder *en = new encoder();
   decoder *de = new decoder(); 
   if(argc != 4 ) 
   { 
      cout << "ERROR: You must input this style -> (./a.out e|d filein fileout)" << endl; 
      return false; 
   }
   // check the changing codes 
   switch( argv[1][0] )  
   {
      case 'e':  
      en->Encode( argv[2], argv[3] );  
      break;  
      case 'd':  
      de->Decode( argv[2], argv[3] );  
      break;  
      default:  
      cout << "ERROR: You must input this style -> (./a.out e|d filein fileout)" << endl; 
      return false;  
   }  
   return true;
}  


