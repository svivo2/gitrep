//-----------------------------------------------------
// Filename: MusicVivo.h
// Purpose:  The header file for the MusicVivo class
//-----------------------------------------------------

#include <iostream>
using namespace std;

class Music
{

public:
  // Constructors
  Music();
  Music(const string song, const int release, const string album, const string artist, const string label);
  Music(const Music &otherMusic);

  // Destructor
  ~Music();

  // Setters
  void setSongName(const string song);
  void setYear(const int release);
  void setAlbumName(const string album);
  void setArtistName(const string artist);
  void setLabelName(const string label);

  // Getters
  string getSongName() const;
  int getYear() const;
  string getAlbumName() const;
  string getArtistName() const;
  string getLabelName() const;

  // Others
  void Print() const;
  void PrintSubset() const;


private:
  string songName;
  int year;
  string albumName;
  string artistName;
  string labelName;

};