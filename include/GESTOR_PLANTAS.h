#ifndef GESTOR_PLANTAS_H
#define GESTOR_PLANTAS_H
#include"PLANTA.h"
#include<vector>

class GESTOR_PLANTAS
{
    public:
        GESTOR_PLANTAS();
        virtual ~GESTOR_PLANTAS();

        void agregarPlanta(Planta* p);

        std::vector<Planta*>  _array_plantas;

};

#endif // GESTOR_PLANTAS_H
