#ifndef ENCODER_H
#define ENCODER_H
#include "EngToMorse.h"
class encoder
{
   private:
      EngToMorse etm;  
      vector<EngToMorse> vecETM;  
      vector<EngToMorse>::iterator itrFind;     
   public:
      encoder();
      ~encoder();
      bool Encode(const char* in_file, const char* out_file);
      
};
encoder::encoder(){}
encoder::~encoder(){}

// encoding function
bool encoder::Encode(const char* in_file, const char* out_file)  
{
   //read the morsecode file
   ifstream readFile(MORSECODE_FILE);
   if(readFile.fail()) return false;
   while(!readFile.eof())
   {
      readFile >> etm.english >> etm.morsecode;
      //save vector
      vecETM.push_back(etm);
   }
   readFile.close();
   ifstream inFile(in_file);
   ofstream outFile(out_file);
   if(!inFile)
   {
      cout << "ERROR: File name " << in_file << " is not exist" << endl;
   }

   if(inFile.fail() || outFile.fail()) return false;

   while(!inFile.eof())
   {
      etm.english = inFile.get();
            
      if(inFile.fail()) break;
      if(etm.english == -1) break;
      if(etm.english == 13) continue;
      itrFind = find(vecETM.begin(), vecETM.end(), etm);
      //If it finds the string to convert, store a converted character.      
      if(itrFind != vecETM.end())
      {      
         outFile << (*itrFind).morsecode << " ";
      }
      //If not, store the string as it is.     
      else 
      {      
         outFile << etm.english;
      }
   }
   inFile.close();
   outFile.close();
   return true;
}  
#endif
