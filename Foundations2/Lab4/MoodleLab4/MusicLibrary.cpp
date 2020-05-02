#include "MusicLibrary.h"
#include <vector>

MusicLibrary::MusicLibrary()
{
  mOwner = "nobody";
  mFilename = "\0";
}

MusicLibrary::MusicLibrary(const string& filename){}

bool MusicLibrary::add(Song s)
{
  while(!mLibrary.empty())
  {
    if (mLibrary.back() == s)
      return false;
    mLibrary.pop_back();
  }
  mLibrary.push_back(s);
  return true;
}
bool MusicLibrary::remove(Song s)
{
  return false;
}
bool MusicLibrary::remove(int index)
{

}
void MusicLibrary::print() const;
{

}
bool MusicLibrary::save() const
{
  return false;
}
