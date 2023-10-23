#include "GESTOR_PLANTAS.h"

GESTOR_PLANTAS::GESTOR_PLANTAS()
{
    //ctor
}

GESTOR_PLANTAS::~GESTOR_PLANTAS()
{
    //dtor
}

void GESTOR_PLANTAS::agregarPlanta(Planta* p)
{
    _array_plantas.push_back(p);
}

