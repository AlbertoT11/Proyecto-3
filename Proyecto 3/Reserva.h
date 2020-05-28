#ifndef Reserva_h
#define Reserva_h
#include "Fecha.h"
#include "Material.h"
using namespace std;

class Reserva{
  private:
  int idMaterial;
  int idCliente;
  Fecha fechaReservacion;
  
  public:
  
  Reserva();
  Reserva(int idMaterial, int idCliente, Fecha fechaReservacion);
  int getidMaterial();
  int getidCliente();
  Fecha getfechaReservacion();
  void setidMaterial(int getidMaterial);
  void setidCliente(int getidCliente);
  void setfechaReservacion(Fecha fechaReservacion);

  Fecha calculaFechaFinReserva(int cantDias);
  
};

Reserva::Reserva(){
  idMaterial = 0;
  idCliente = 0;
  Fecha f;
  fechaReservacion = f;
}

Reserva::Reserva(int idMaterial, int idCliente, Fecha fechaReservacion){
  this->idMaterial = idMaterial;
  this->idCliente = idCliente;
  this->fechaReservacion = fechaReservacion;
}

void Reserva::setidMaterial(int idMaterial){
  this->idMaterial=idMaterial;
}

void Reserva::setidCliente(int idCliente){
  this->idCliente=idCliente;
}

void Reserva::setfechaReservacion(Fecha fechaReservacion){
  this->fechaReservacion = fechaReservacion;
}

int Reserva::getidMaterial(){
  return idMaterial;
}

int Reserva::getidCliente(){
  return idCliente;
}

Fecha Reserva::getfechaReservacion(){
  return fechaReservacion;
}

Fecha Reserva::calculaFechaFinReserva(int cantDias){
  Fecha fec(fechaReservacion.getdd()+cantDias, fechaReservacion.getmm(), fechaReservacion.getaa());
  return fec;
}

#endif