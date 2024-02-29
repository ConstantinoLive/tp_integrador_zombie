#ifndef GESTOR_PLANTAS_H
#define GESTOR_PLANTAS_H

#include <vector>

#include "PLANTA.h"

class Gestor_plantas
{
    public:
        Gestor_plantas();
        virtual ~Gestor_plantas();

        void agregarPlanta(Planta* p);

        std::vector<Planta*>  _array_plantas;

};

#endif // GESTOR_PLANTAS_H
