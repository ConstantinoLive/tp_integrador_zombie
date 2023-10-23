#ifndef GESTOR_DISPAROS_H
#define GESTOR_DISPAROS_H
#include"DISPARO.h"
#include<vector>

class GESTOR_DISPAROS
{
    public:
        GESTOR_DISPAROS();
        virtual ~GESTOR_DISPAROS();

        void agregarDisparo(Disparo* disp);



        //esto deberia de ser privado y tener un getter porque para el setter ya se hizo el agregar disparo
        std::vector<Disparo*> _array_disparos;

};

#endif // GESTOR_DISPAROS_H
