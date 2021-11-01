//-----------------------------------------------------
// Filename: Music.cpp
// Purpose:  The implementation of the Music class
//-----------------------------------------------------

#include <iostream>
#include "Music.h"
using namespace std;

//----------- Constructors and Destructors ----------

// Default Constructor
Music::Music()
{
  cout << "\nIn Default Constructor\n";

  songName = "";
  year = 2018;
  albumName = "";
  artistName = "";
  labelName = "";
}
// Non-default Constructor
Music::Music(const string song, const int release, const string album, const string artist, const string label)
{
  cout << "\nIn Non-default Constructor\n";

  songName = song;
  year = release;
  albumName = album;
  artistName = artist;
  labelName = label;
}

// Copy Constructor
Music::Music(const Music &otherMusic)
{
  cout << "\nIn Copy Constructor\n";

  songName = otherMusic.songName;
  year = otherMusic.year;
  albumName = otherMusic.albumName;
  artistName = otherMusic.artistName;
  labelName = otherMusic.labelName;
}

// Destructor
Music::~Music(){ cout << "\nIn Destructor\n"; }

// Setters
void Music::setSongName(const string song)
{
  cout << "\nIn setSongName method\n";
  songName = song;
}
void Music::setYear(const int release)
{
  cout << "\nIn setYear method\n";
  year = release;
}
void Music::setAlbumName(const string album)
{
  cout << "\nIn setAlbumName method\n";
  albumName = album;
}
void Music::setArtistName(const string artist)
{
  cout << "\nIn setArtistName method\n";
  artistName = artist;
}
void Music::setLabelName(const string label)
{
  cout << "\nIn setLabelName method\n";
  labelName = label;
}

// Getters
string Music::getSongName() const
{
  cout << "\nIn getSongName method\n";
  return(songName);
}
int Music::getYear() const
{
  cout << "\nIn getYear method\n";
  return(year);
}
string Music::getAlbumName() const
{
  cout << "\nIn getAlbumName method\n";
  return(albumName);
}
string Music::getArtistName() const
{
  cout << "\nIn getArtistName method\n";
  return(artistName);
}
string Music::getLabelName() const
{
  cout << "\nIn getLabelName method\n";
  return (labelName);
}

// Others
void Music::Print() const
{
  cout << "\nIn Print Method\n";
  cout << "Song: " << songName << endl;
  cout << "Artist: " << artistName << endl;
  cout << "Album: " << albumName << endl;
  cout << "Release: " << year << endl;
  cout << "Label: " << labelName << endl;
}

void Music::PrintSubset() const
{
  cout << "\nIn PrintSubset Method\n";
  cout << "Song: " << songName << endl;
  cout << "Artist: " << artistName << endl;
  cout << "Album: " << albumName << endl;
}