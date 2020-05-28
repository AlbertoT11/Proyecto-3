#ifndef Software_h
#define Software_h
#include <string.h>
#include "Material.h"
#include <iostream>
using namespace std;

class Software : public Material{
  private:
  int Version;
  string SO;
  int id;
  string tit;
  
  public:
  
  Software();
  Software(int idMaterial, string titulo, int Version, string SO);
  int getVersion();
  string getSO();
  void setVersion(int getVersion);
  void setSO(string SO);

  void muestraDatos();
  int cantidadDiasPrestamo();
  
};

Software::Software() : Material(){
  Version = 0;
  SO = "";
}

Software::Software(int idMaterial, string titulo, int Version, string SO) : Material( idMaterial, titulo){
  this->Version = Version;
  this->SO = SO;
  tit=titulo;
  id=idMaterial;
}

void Software::setVersion(int Version){
  this->Version=Version;
}

void Software::setSO(string SO){
  this->SO = SO;
}

int Software::getVersion(){
  return Version;
}

string Software::getSO(){
  return SO;
}

int Software::cantidadDiasPrestamo(){
  return 1;
}

void Software::muestraDatos(){
  cout << id << " " << tit << " Software " << Version << " " << SO;
}

#endif