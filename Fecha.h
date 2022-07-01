#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <ctime>
#include <map>

using namespace std;

class Fecha
{
private:
    // BUFFER PARA ALMACENAR EL STRING DE KA FECHA EN ESTILO C, ESTO ES POR FUNCIONES DE CODIGO HEREDADO (LEGACY CODE)
    // DEBIDO A QUE LAS FUNCIONES PARA OBTENER LA FECHA CON UN FORMATO ESPECIFICO USAN UN ARRAY DE CARACTERES EN LUGAR
    // DE UN STRING.
    char buffer[50];

    // VALOR DE TIPO ENTERO QUE REPRESENTA LOS SEGUNDOS TRANSCURRIDOS DESDE 00:00 HORAS, Jan 1, 1970 UTC
    time_t unixTimestamp;

    // ESTA ESTRUCTURA ALMACENA LOS DATOS DE LA FECHA SEPARADOS EN CAMPOS. BUSCA ACERCA DE struct tm FROM time.h
    tm *timeinfo;
public:
    Fecha();

    bool setDayOfMonth(int iDayNumber);

    int getDayOfWeek();
    int getDayOfMonth();
    int getDayOfYear();

    bool setMonth(int iMonthNumber);
    int getMonth();

    bool setYear(int iYearNumber);
    int getYear();

    string toString();
    string toString(string format);
    string toString(string format, string separator);
};

#endif // FECHA_H
