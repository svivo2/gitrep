#include "music.h"

// Default Constructor
Music::Music()
{
  cout << "\nIn default Constructor\n";

  songName = "\0";
  artistName = "\0";
  musicLabel = "\0";
  songDuration = 0;
  releaseYear = 0;
}

// Copy Constructor
Music::Music(const Music & otherMusic)
{
  cout << "\nIn copy Constructor\n";

  songName = otherMusic.songName;
  artistName = otherMusic.artistName;
  musicLabel = otherMusic.musicLabel;
  songDuration = otherMusic.songDuration;
  releaseYear = otherMusic.releaseYear;

}

// Destructor
Music::~Music()
{
  cout << "\nIn Destructor\n";
}

// Getters
string Music::getSongName()
{
  cout << "\nIn getSongName method\n";

  return songName;
}

string Music::getArtistName()
{
  cout << "\nIn getArtistName method\n";

  return artistName;
}

string Music::getMusicLabel()
{
  cout << "\nIn getMusicLabel method\n";

  return musicLabel;
}

int Music::getSongDuration()
{
  cout << "\nIn getSongDuration method\n";

  return songDuration;
}

int Music::getReleaseYear()
{
  cout << "\nIn getReleaseYear method\n";

  return releaseYear;
}

void Music::setSongName(const string song)
{
  cout << "\nIn setSongName method\n";

  songName = song;
}

//Setters
void Music::setArtistName(const string artist)
{
  cout << "\nIn setArtistName method\n";

  artistName = artist;
}

void Music::setMusicLabel(const string label)
{
  cout << "\nIn setMusicLabel method\n";

  musicLabel = label;
}

void Music::setSongDuration(const int duration)
{
  cout << "\nIn setSongDuration method\n";

  songDuration = duration;
}

void Music::setReleaseYear(const int year)
{
  cout << "\nIn setReleaseYear method\n";

  releaseYear = year;
}

//Print
void Music::print()
{
  cout << "\nIn print method\n";

  cout << "\nSong Name: " << songName;
  cout << "\nArtist Name: " << artistName;
  cout << "\nMusic Label: " << musicLabel;
  cout << "\nSong Duration: " << songDuration / 60
      << " minutes " << songDuration % 60 << " seconds";
  cout << "\nRelease Year: " << releaseYear << endl;
}

void Music::printSubset()
{
  cout << "\nIn printSubset method\n";

  cout << "\nSong Name: " << songName;
  cout << "\nArtist Name: " << artistName;
  cout << "\nSong Duration: " << songDuration / 60
      << " minutes " << songDuration % 60 << " seconds";
}
