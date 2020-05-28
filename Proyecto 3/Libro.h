#ifndef Libro_h
#define Libro_h
#include <string.h>
#include "Material.h"
#include <iostream>
using namespace std;

class Libro : public Material{
  private:
  int numPag;
  string Autor;
  int id;
  string tit;
  
  public:
  
  Libro();
  Libro(int idMaterial, string titulo, int numPag, string Autor);
  int getPag();
  string getAutor();
  void setPag(int getPag);
  void serAutor(string Autor);

  void muestraDatos();
  int cantidadDiasPrestamo();
  
};

Libro::Libro() : Material(){
  numPag = 0;
  Autor = "";
}

Libro::Libro(int idMaterial, string titulo, int numPag, string Autor) : Material(idMaterial, titulo){
  this->numPag = numPag;
  this->Autor = Autor;
  tit=titulo;
  id=idMaterial;
}

void Libro::setPag(int numPag){
  this->numPag=numPag;
}

void Libro::serAutor(string Autor){
  this->Autor = Autor;
}

int Libro::getPag(){
  return numPag;
}

string Libro::getAutor(){
  return Autor;
}

int Libro::cantidadDiasPrestamo(){
  return 7;
}

void Libro::muestraDatos(){
  cout << id << " " << tit << " Libro " << numPag << " " << Autor;
}

#endif