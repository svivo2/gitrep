#include <iostream>
#include "Music.h"
using namespace std;

int main(){
  Music song1;
  Music song2(song1);
  song2.setSongName("Rainbow");
  song2.setArtistName("Romare");
  song2.setAlbumName("Projections");
  song2.setYear(2015);
  song2.setLabelName("Ninja Tune");
  song1.getSongName();
  song1.getArtistName();
  song1.getAlbumName();
  song1.getYear();
  song1.getLabelName();
  song2.Print();
  song2.PrintSubset();

}
