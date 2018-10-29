#ifndef MORSETOENG_H
#define MORSETOENG_H
struct MorseToEng
{
   char english;
   string morsecode;

   bool operator == (const MorseToEng& e) const {return (morsecode == e.morsecode);}
   bool operator != (const MorseToEng& e) const {return (morsecode != e.morsecode);}
   bool operator < (const MorseToEng& e) const {return (morsecode < e.morsecode);}
   bool operator > (const MorseToEng& e) const {return (morsecode > e.morsecode);}
   bool operator >= (const MorseToEng& e) const {return (morsecode >= e.morsecode);}
   bool operator <= (const MorseToEng& e) const {return (morsecode <= e.morsecode);}
};
#endif
