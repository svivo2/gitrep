#include <iostream>
using namespace std;

class Music
{
public:
  // Constructors and Destructors
  Music();
  Music(const Music &otherMusic);
  ~Music();

  //Getters
  string getSongName();
  string getArtistName();
  string getMusicLabel();
  int getSongDuration();
  int getReleaseYear();

  //Setters
  void setSongName(const string song);
  void setArtistName(const string artist);
  void setMusicLabel(const string label);
  void setSongDuration(const int duration);
  void setReleaseYear(const int year);

  //Print
  void print();
  void printSubset();

private:
  string songName;
  string artistName;
  string musicLabel;
  int songDuration;
  int releaseYear;
};
