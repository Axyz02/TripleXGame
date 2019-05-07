#include <iostream>
#include <cstdlib>

void MensajeInicial(int);
void Juego();
int Jugar(int);

void MensajeInicial(int Dificultad)
{
    std::cout<<"Estas en el papel de un agente secreto, el cual esta intentantdo irrumpir en una sala de servidores con un nivel de seguridad ";
    std::cout<<Dificultad<<" \nIngresa el codigo correcto para continuar.\n";
}

void Juego()
{
    int NivelDificultad=1;
    int MaxDif=10;
    while (NivelDificultad<=MaxDif)
    {
        MensajeInicial(NivelDificultad);
        if (Jugar(NivelDificultad)==1)
        {
            ++NivelDificultad;
            std::cout<<"Siguiente nivel.\n";
            system("pause");
            system("cls");
        }
        else
        {
            char PlayAgain;
            std::cout<<"GAME OVER\n";
            std::cout<<"Volver a intentarlo? (S/N)\n";
            std::cin>>PlayAgain;
            if (PlayAgain=='S')
            {
                system("cls");
            }
            else
            {
                std::cout<<"Gracias por jugar.\n";
                system("pause");
                break;
            }
            
        }
    }
}

int Jugar(int Dificultad)
{
    //--------------Codigos correctos-------
    const int Codigo1=rand() % Dificultad+1;
    const int Codigo2=rand() % Dificultad+1;
    const int Codigo3=rand() % Dificultad+1;
    const int SumaCod=Codigo1+Codigo2+Codigo3;
    const int ProdCod=Codigo1*Codigo2*Codigo3;
    //-----------Codigos User-----------------
    int Intento1,Intento2,Intento3;
    int SumaInt;
    int ProdInt;
    //--------------Juego-------------------
    std::cout<<"El codigo esta compuesto de tres numeros los cuales:\n";
    std::cout<<"La suma de los tres da un resultado de: "<<SumaCod<<std::endl;
    std::cout<<"El producto de los tres da un resultado de: "<<ProdCod<<std::endl;
    std::cout<<"-----Ingrese el codigo-----\n";
    std::cin>>Intento1>>Intento2>>Intento3;
    SumaInt=Intento1+Intento2+Intento3;
    ProdInt=Intento1*Intento2*Intento3;
    //--------------Comprobaciones-----------
    if (SumaInt==SumaCod && ProdInt==ProdCod)
    {
        std::cout<<"Felicitaciones, agente, lograste irrumpir en los servidores y obtener el archivo correctamente.\n";
        return 1;
    }
    else
    {
        std::cout<<"\"**ERROR** **ERROR** **SISTEMAS DE SEGURIDAD ACTIVADOS**\"\n";
        std::cout<<"\n\n El codigo no era el correcto y la alarma fue activado, fuiste evacuado a tiempo.\n";
        return -1;
    }
}

int main(){
    Juego();
return 0;
}