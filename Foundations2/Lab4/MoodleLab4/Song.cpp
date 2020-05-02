#include "Song.h"

Song::Song()
{
  title = "Viva la Vida";
  composer = "Coldplay";
  artist = "Coldplay";
  path = "/home/music/song101";
  album = "Viva la Vida or Death and All His Friends";
  year = 2008;
  genre = ROCK;
  format = WMA;
}

Song::Song(const string& title, const string& composer, const string& artist, const string& path,const string& album,const unsigned int year, const Genre genre, const Format format)
{
  title = title;
  composer = composer;
  artist = artist;
  path = path;
  album = album;
  year = year;
  genre = genre;
  format = format;
}

string Song::getTitle()const
{
 return title;
}

string Song::getComposer() const
{
  return composer;
}

string Song::getArtist() const
{
  return artist;
}

string Song::getPath() const
{
  return path;
}

string Song::getAlbum() const
{
  return album;
}

unsigned int Song::getYear() const
{
  return year;
}

Genre Song::getGenre() const
{
  return genre;
}
Format Song::getFormat() const
{
  return format;
}

void Song::setTitle(const string& title)
{
  title = title;
}

void Song::setComposer(const string& composer)
{
  composer = composer;
}

void Song::setArtist(const string& artist)
{
  atrist = artist;
}

void Song::setPath(const string& path)
{
  path = path;
}

void Song::setAlbum(const string& album)
{
  album = album;
}

void Song::setYear(const unsigned int year)
{
  year = year;
}

void Song::setGenre(const Genre genre)
{
  genre = genre;
}

void Song::setFormat(const Format format)
{
  format = format;
}
