#ifndef DECODER_H
#define DECODER_H
#include "MorseToEng.h"
class decoder
{
   private:
      MorseToEng mte;
      bintree<MorseToEng> bintreeMTE;
      const_iterator<MorseToEng> citrFind;
   public:
      decoder();
      ~decoder();
      bool Decode(const char* in_file, const char* out_file);
      void printTreeStats(const bintree<MorseToEng> &treeRoot);
};
decoder::decoder(){}
decoder::~decoder(){}
// decoding function  
bool decoder::Decode(const char* in_file, const char* out_file)  
{  
   ifstream readFile(MORSECODE_FILE);
   if(readFile.fail()) return false;
   while(readFile >> mte.english >> mte.morsecode) 
   { 
      bintreeMTE.insert(mte);
      citrFind = bintreeMTE.find(mte);
   }
   readFile.close();
   ifstream inFile(in_file);
   ofstream outFile(out_file);
   if(!inFile)
   {
      cout << "ERROR: File name " << in_file << " is not exist" << endl;
   }
   
   if(inFile.fail() || outFile.fail()) return false;
   
   char ch;
   string str;
   string fstr; 
   MorseToEng mteee;
   int i = 0;

   while(inFile.get(ch))
   {
      if(ch==10)
      {
         fstr += 10;
         continue;
      }
      if(ch==32)
      {
         if(i==1)
         {
            fstr += 32;
         }
         else
         {
            i++;
            mteee.morsecode = str;
            citrFind = bintreeMTE.find(mteee);
            fstr += citrFind->english;
            str = "";
         }
      }
      else
      {
         i = 0;
         str += ch;
      }        
   }
   outFile << fstr;
   printTreeStats(bintreeMTE);
   cout << "Rebalance the tree." << endl;
   bintreeMTE.rebalance();
   printTreeStats(bintreeMTE);
   inFile.close();
   outFile.close();
   return true;
}

void decoder::printTreeStats(const bintree<MorseToEng> &treeRoot)
{
   cout << "Tree balance   = " << treeRoot.balance() << endl;
}
#endif
