#include "music.h"

int main()
{
  Music song1;

  song1.setSongName("Boogie Nights");
  song1.setArtistName("Heatwave");
  song1.setMusicLabel("GTO Records");
  song1.setSongDuration(302);
  song1.setReleaseYear(1977);

  Music song2(song1);

  song2.getSongName();
  song2.getArtistName();
  song2.getMusicLabel();
  song2.getSongDuration();
  song2.getReleaseYear();

  song1.print();
  song2.printSubset();
}
