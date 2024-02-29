#include "Ranking.h"

Ranking::Ranking()
{
    //ctor
}

Ranking::~Ranking()
{
    //dtor
}

void Ranking::setRanking()
{

    Partida reg;
    Partida auxOrdenar;

    for(int i=0;i<10;i++)
    {
        _partidas[i].setName("Player");
        _partidas[i].setPuntos(0);
    }


    int cantReg = reg.contarPartidas();
    Partida *vec = new Partida[cantReg];
        if (vec == NULL) {std::cout << "No hay memoria suficiente.";}

    //std::cout<<cantReg<<std::endl;
    FILE *p=fopen("Partidas.dat", "rb");
    if(p==NULL) std::cout<<"no se pudo abrir"<<std::endl;
    int x =0;
    /*for(x=0;x<cantReg;x++)
    {
        fread(&reg,sizeof(Partida), 1, p);
      std::cout<<reg.getName()<<std::endl;
      std::cout<<reg.getPuntos()<<std::endl;

    }*/
    while(fread(&reg, sizeof(Partida), 1, p)==1)
    {
     // std::cout<<reg.getName()<<std::endl;
     // std::cout<<reg.getPuntos()<<std::endl;
      vec[x].setName(reg.getName());
      vec[x].setPuntos(reg.getPuntos());
      x++;

    }
    fclose(p);
    ///aca se ordena
    for(int i =0; i<cantReg-1;i++)
    {
        for(int j =0; j<cantReg-i-1;j++)
        {
           /* if(i==0)
            {
                auxOrdenar = vec[i];
            }
            else*/ if (vec[j].getPuntos()< vec[j+1].getPuntos())
            {
                auxOrdenar = vec[j];
                vec[j] = vec[j+1];
                vec[j+1]= auxOrdenar;
            }
        }
    }///cargo vector de jugadores con puntos
    ///desde aca
    //int y=56;
    ///

    for(int i=0;i<cantReg;i++)   ///Cargamos vector de partidas, que se compone de nombre y puntos
    {
        _partidas[i]=vec[i];
        if(i>9)
            break;  ///salis del for
        //std::cout<<_partidas[i].getName();
        //std::cout<<_partidas[i].getPuntos();
    }

    /*
    {
       // std::cout<< "Puesto: "<<i+1<<" "<<vec[i].getName()<< " Con "<<vec[i].getPuntos()<<" Puntos"<<std::endl;
       // std::cout<<"Nombre: "<<vec[i].getName()<<std;
       // std::cout<<"puntos: "<<vec[i].getPuntos()<<std::endl;
        //std::cout<<"puntos: "<<vec[i].getPuntos)<<std::endl;
    }

    sf::Font font;

    if (!font.loadFromFile("font/TT Interphases Pro Trial Black.ttf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setColor(sf::Color::Magenta);

    for (int i=0;i<cantReg;i++)
    {
        text.setString("Puesto: "+ std::to_string(i+1)+ " " +vec[i].getName()+ " Con " +std::to_string(vec[i].getPuntos())+ " Puntos");
        text.setPosition(100, 100 + i* 60);
        window.draw(text);
        if(i==9)
        {
            i= cantReg;
        }
    }
    */
    delete[] vec;

    //return jugadores;
}

Partida* Ranking::getRanking()
{
    return _partidas;
}
