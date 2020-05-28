#ifndef Disco_h
#define Disco_h
#include <string.h>
#include "Material.h"
#include <iostream>
using namespace std;

class Disco : public Material{
  private:
  int Duracion;
  string Genero;
  int id;
  string tit;
  
  public:
  
  Disco();
  Disco(int idMaterial, string titulo, int duracion, string Genero);
  int getDuracion();
  string getGenero();
  void setDuracion(int getDuracion);
  void setGenero(string Genero);

   void muestraDatos();
  int cantidadDiasPrestamo();
  
};

Disco::Disco() : Material(){
  Duracion = 0;
  Genero = "";
}

Disco::Disco(int idMaterial, string titulo, int duracion, string Genero) : Material(idMaterial, titulo){
  this->Duracion = duracion;
  this->Genero = Genero;
  tit=titulo;
  id=idMaterial;
}

void Disco::setDuracion(int getDuracion){
  Duracion = getDuracion;
}

void Disco::setGenero(string Genero){
  this->Genero = Genero;
}

int Disco::getDuracion(){
  return Duracion;
}

string Disco::getGenero(){
  return Genero;
}

int Disco::cantidadDiasPrestamo(){
  return 2;
}

void Disco::muestraDatos(){
  cout << id << " " << tit << " Disco " << Duracion << " " << Genero;
}
#endif