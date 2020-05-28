#ifndef Material_h
#define Material_h
#include <string.h>
using namespace std;

class Material{
  protected:
  int idMaterial;
  string titulo;
  
  public:
  
  Material();
  Material(int idMaterial, string titulo);
  int getidMaterial();
  string gettitulo();
  void setidMaterial(int getidMaterial);
  void settitulo(string titulo);

  virtual void muestraDatos() = 0;
  virtual int cantidadDiasPrestamo() = 0;
  
};

Material::Material(){
  idMaterial = 0;
  titulo = "";
}

Material::Material(int idMaterial, string titulo){
  this->idMaterial = idMaterial;
  this->titulo = titulo;
}

void Material::setidMaterial(int idMaterial){
  this->idMaterial=idMaterial;
}

void Material::settitulo(string titulo){
  this->titulo = titulo;
}

int Material::getidMaterial(){
  return idMaterial;
}

string Material::gettitulo(){
  return titulo;
}

#endif