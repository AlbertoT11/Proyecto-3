#ifndef Fecha_h
#define Fecha_h
#include <string>
#include <iostream>
using namespace std;

class Fecha{
  private:
  int dd;
  int mm;
  int aa;
  
  public:
  
  Fecha();
  Fecha(int dd, int mm, int aa);
  int getdd();
  int getmm();
  int getaa();
  void setdd(int getdd);
  void setmm(int getmm);
  void setaa(int aa);

  void setFecha(int dd, int mm, int aa);
  string nombreMes();

  //operadores
  


  bool esBisiesto()
    {
        if (aa % 4 == 0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
  friend Fecha operator+(Fecha f1, int iDias)
    {
        int iParcial;

        if (f1.getmm()==1||f1.getmm()==3||f1.getmm()==5||f1.getmm()==7||f1.getmm()==8||f1.getmm()==10||f1.getmm()==12)
        {
            if ((f1.getdd() + iDias) > 31)
            {
                iParcial = (f1.getdd() + iDias) - 31;

                f1.setmm(f1.getmm()+1);
                f1.setdd(iParcial);

                if (f1.getmm() > 12)
                {
                    f1.setmm(1);
                    f1.setaa(f1.getaa()+1);
                }
            }

            else
            {
                f1.setdd(f1.getdd() + iDias);
            }

            return f1;
        }

        else if (f1.getmm()==4||f1.getmm()==6||f1.getmm()==9||f1.getmm()==11)
        {
            if ((f1.getdd() + iDias) > 30)
            {
                iParcial = (f1.getdd() + iDias) - 30;

                f1.setmm(f1.getmm()+1);
                f1.setdd(iParcial);

                if (f1.getmm() > 12)
                {
                    f1.setmm(1);
                    f1.setaa(f1.getaa()+1);
                }
            }

            else
            {
                f1.setdd(f1.getdd() + iDias);
            }

            return f1;
        }

        else if (f1.getmm() == 2)
        {
            if (f1.esBisiesto())
            {
                if (f1.getdd() + iDias > 29)
                {
                    iParcial = (f1.getdd() + iDias) - 29;

                    f1.setmm(f1.getmm()+1);
                    f1.setdd(iParcial);

                    if (f1.getmm() > 12)
                    {
                        f1.setmm(1);
                        f1.setaa(f1.getaa()+1);
                    }
                }

                else
                {
                    f1.setdd(f1.getdd() + iDias);
                }
            }

            else
            {
                if (f1.getdd() + iDias > 28)
                {
                    iParcial = (f1.getdd() + iDias) - 28;

                    f1.setmm(f1.getmm()+1);
                    f1.setdd(iParcial);

                    if (f1.getmm() > 12)
                    {
                        f1.setmm(1);
                        f1.setaa(f1.getaa()+1);
                    }
                }

                else
                {
                    f1.setdd(f1.getdd() + iDias);
                }
            }

            return f1;
        }
        Fecha d;
        return d;
    }
  
    friend bool operator>(Fecha f1, Fecha f2)
    {
       
        if (f1.getaa() > f2.getaa())
        {
            return true;
        }

        else if (f1.getaa() == f2.getaa())
        {
           
            if (f1.getmm() > f2.getmm())
            {
                return true;
            }

            else if (f1.getmm() == f2.getmm())
            {
              
                if (f1.getdd() > f2.getdd())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    friend bool operator>=(Fecha f1, Fecha f2)
    {
        if (f1.getaa() > f2.getaa())
        {
            return true;
        }

        else if (f1.getaa() == f2.getaa())
        {
            if (f1.getmm() > f2.getmm())
            {
                return true;
            }

            else if (f1.getmm() == f2.getmm())
            {
                if (f1.getdd() >= f2.getdd())
                {
                    return true;
                }

                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }

    }
    friend bool operator<(Fecha f1, Fecha f2)
    {
        if (f1.getaa() < f2.getaa())
        {
            return true;
        }

        else if (f1.getaa() == f2.getaa())
        {
            if (f1.getmm() < f2.getmm())
            {
                return true;
            }

            else if (f1.getmm() == f2.getmm())
            {
                if (f1.getdd() < f2.getdd())
                {
                    return true;
                }

                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

    }
    friend bool operator<=(Fecha f1, Fecha f2)
    {
        if (f1.getaa() < f2.getaa())
        {
            return true;
        }

        else if (f1.getaa() == f2.getaa())
        {
            if (f1.getmm() < f2.getmm())
            {
                return true;
            }

            else if (f1.getmm() == f2.getmm())
            {
                if (f1.getdd() <= f2.getdd())
                {
                    return true;
                }

                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }

    }

    friend bool operator==(Fecha f1, Fecha f2)
    {
        if (f1.getaa() == f2.getaa())
        {
            if (f1.getmm() == f2.getmm())
            {
                if (f1.getdd() == f2.getdd())
                {
                    return true;
                }

                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
        
    }
    


};

Fecha::Fecha(){
  dd = 0;
  mm = 0;
  aa = 0;
}

Fecha::Fecha(int dd, int mm, int aa){
  this->dd = dd;
  this->mm = mm;
  this->aa = aa;
}

void Fecha::setdd(int dd){
  this->dd=dd;
}

void Fecha::setmm(int mm){
  this->mm=mm;
}

void Fecha::setaa(int aa){
  this->aa = aa;
}

int Fecha::getdd(){
  return dd;
}

int Fecha::getmm(){
  return mm;
}

int Fecha::getaa(){
  return aa;
}

void Fecha::setFecha(int dd, int mm, int aa){
  this->dd = dd;
  this->mm = mm;
  this->aa = aa;
}

string Fecha::nombreMes(){
  if(mm==1) {
    return "Ene";
  }
  if(mm==2) {
    return "Feb";
  }
  if(mm==3) {
    return "Mar";
  }
  if(mm==4) {
    return "Abr";
  }
  if(mm==5) {
    return "May";
  }
  if(mm==6) {
    return "Jun";
  }
  if(mm==7) {
    return "Jul";
  }
  if(mm==8) {
    return "Ago";
  }
  if(mm==9) {
    return "Sep";
  }
  if(mm==10) {
    return "Oct";
  }
  if(mm==11) {
    return "Nov";
  }
  if(mm==12) {
    return "Dic";
  }
  return "";
}


#endif