#include "Fecha.h"

Fecha::Fecha()
{
    // La variable unixTimestamp es  un  numero de tipo entero que contiene el numero de segundos transcurridos desde 1970-01-01. Esto es
    // asi por razones historicas. Cuando llamamos a  la  funcion  'time(nullptr)'  basicamente estamos almacenando la fecha actual de la
    // computadora, es decir, la fecha en el instante que se llama a la funcion (NOW).
    this->unixTimestamp = time( nullptr );

    // El puntero a la estructura de tipo tm *timeinfo es con la  que  mas  trabajamos  en la clase, ya que esta tiene como atributos las
    // partes de la fecha separados, es decir,  el dia,  el mes, el año, la hora, etc. Utilizamos esta estructura para poder manipular la
    // fecha de una manera mas simple a diferencia de unixTimestamp que son segundos.  En  la  siguiente linea de codigo inicializamos la
    // estructura con la variable unixTimestamp la cual contiene la fecha de la maquina local.
    this->timeinfo = localtime(&this->unixTimestamp);
}

/// <summary>
/// Este metodo asigna el dia del mes que se desea  asignar  a  la  fecha, el rango de numero validos que acepta este metodo es de 1 a 31
/// debido a que el mes puede tener minimo 1 dia y maximo 31 dias. si se intenta asignar un numero fuera de este rango la funcion retorna
/// false, en caso de que el numero este dentro del rango retorna true. Existe una excepcion en algunos meses que tienen menos de 31 dias
/// como es el caso de febrero, si por alguna razon se asigna el dia 31 a un mes que no tiene esa cantidad de dias lo que hace la funcion
/// es restar la diferencia de dias (calcular el sobrante de dias) y con ese sobrante pasar al siguiente mes.
/// </summary>
///
/// <param name="iDayNumber">
/// el numero del dia del mes que se desea asignar a a fecha que esta en el rango de 1 a 31
/// </param>
///
/// <returns>
/// verdadero si el rango esta bien, falso en caso de error.
/// </returns>
bool Fecha::setDayOfMonth(int iDayNumber)
{
    // Si el numero esta en el rango de 1 a 31
    if ( iDayNumber >= 1 && iDayNumber <= 31 )
    {
        // Indicamos en la estructura el dia del mes para que cuando el usuario llame a la funcion toString() obtenga  la  fecha  con  el
        // nuevo dia
        this->timeinfo->tm_mday = iDayNumber;

        // Actualizamos la fecha (los datos de la estructura time_t * timeinfo)
        mktime(this->timeinfo);
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Este metodo retorna el dia del mes de la fecha actual especificada en la estructura time_t * timeinfo.
/// </summary>
///
/// <returns>
/// El dia del mes que esta en un rango de 1 a 31
/// </returns>
int Fecha::getDayOfMonth()
{
    return this->timeinfo->tm_mday;
}

/// <summary>
/// Devuelve el dia de la semana, un numero entero que esta en el rango de 1 a 7 donde 1 es lunes y 7 es domingo.
/// </summary>
///
/// <returns>
/// un numero entero entre el rango de 1 a 7.
/// </returns>
int Fecha::getDayOfWeek()
{
    return this->timeinfo->tm_wday + 1;
}

/// <summary>
    //===================================================================================================================================
///
/// </summary>
///
/// <param name="iMonthNumber">
/// </param>
///
/// <returns>
/// </returns>
bool Fecha::setMonth(int iMonthNumber)
{
    // SI ESTA EN EL INTERVALO CERRADO DE [1,12]
    if ( iMonthNumber >= 1 && iMonthNumber <= 12)
    {
        // LA ESTRUCTURA tm ALMACENA LOS VALORES DE LOS MESES EN EL INTERVALO CERRADO DE [0,11]
        this->timeinfo->tm_mon = iMonthNumber - 1;
        return true;
    }
    else
    {
        return false;
    }
}

int Fecha::getDayOfYear()
{
    return this->timeinfo->tm_yday;
}

int Fecha::getMonth()
{
    return this->timeinfo->tm_mon + 1;
}

bool Fecha::setYear(int iYearNumber)
{
    // SI ESTA EN EL INTERVALO CERRADO DE
    if ( iYearNumber > 1900 && iYearNumber < 3000 )
    {
        this->timeinfo->tm_year = iYearNumber - 1900;
        return true;
    }
    else
    {
        return false;
    }
}

int Fecha::getYear()
{
    return this->timeinfo->tm_year + 1900;
}

string Fecha::toString()
{
    return this->toString("MM-DD-YY","-");
}

string Fecha::toString(string format)
{
    return this->toString(format, "-");
}

string Fecha::toString( string fomratoDeseado, string separator )
{
    string formato = string();
    bool elFormatoFueModificado = false;

    if (fomratoDeseado == "MM-DD-YYYY")
    {
        formato = "%m" + separator + "%d" + separator + "%Y";
        elFormatoFueModificado = true;
    }

    if (fomratoDeseado == "MM-DD-YYYY HH:MM:SS")
    {
        formato = "%m" + separator + "%d" + separator + "%Y" +
                  " %H" + separator + "%M" + separator + "%S";
        elFormatoFueModificado = true;
    }

    if (fomratoDeseado == "MM-DD-YY HH:MM:SS" )
    {
        formato =	"%m" + separator + "%d" + separator + "%y" +
                    " %H" + separator + "%M" + separator + "%S";
        elFormatoFueModificado = true;
    }

    // SI EL FORMATO NO FUE MODIFCADO
    if (!elFormatoFueModificado)
    {
        // ASIGNAMOS EL FORMATO POR DEFAULT
        formato = "%m" + separator + "%d" + separator + "%y";
    }

    // GUARDAMOS LA FECHA CON EL FORMATO ESPECIFICADO EN EL BUFFER DE ESTA CLASE
    strftime(this->buffer, 50, formato.c_str(), this->timeinfo);

    // CONVERTIMOS EL ARRAY DE CHAR (BUFFER) A STRING Y RETORNAMOS EL STRING CON EL FORMATO ESPECIFICADO
    return string(this->buffer);
}
