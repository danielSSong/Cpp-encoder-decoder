#ifndef ENGTOMORSE_H
#define ENGTOMORSE_H

struct EngToMorse
{
   char english;
   string morsecode;
   bool operator == (const EngToMorse& e) const {return (english == e.english);}
   bool operator != (const EngToMorse& e) const {return (english != e.english);}
};
#endif
