
#### getMonth();
Retorna un valor numerico de tipo entero que es el numero del mes de la fecha en forma de string. El valor numerico esta en el rango de 1 a 12. Donde:  
Enero .......... 1  
Febrero ........ 2  
etc ...  
Diciembre ...... 3
```CPP
    cout << setw(80) << setfill('.') << left;
    cout << "fecha.getMonth(); "                            << fecha.getMonth() << endl;
```
Salida
```
fecha.getMonth(); ..............................................................11
```

#### getDayOfMonth();
El dia del mes es un valor numerico de tipo entero que representa el numero del dia del mes, el valor devuelto por este metodo esta en un rango de 1 a 31.
```CPP
    cout << setw(80) << setfill('.') << left;
    cout << "fecha.getDayOfMonth(); "                       << fecha.getDayOfMonth() << endl;
```
Salida
```
fecha.getDayOfMonth(); .........................................................13
```

#### getDayOfWeek();
El dia de la semana es un valor numerico de tipo entero que usamos para identifcar cada dia, los dias estan catalogados de la siguiente manera:
Lunes .......... 1  
Martes ......... 2  
Miercoles ...... 3  
Jueves ......... 4  
Viernes ........ 5  
Sabado ......... 6  
Domingo ........ 7  
```CPP
    cout << setw(80) << setfill('.') << left;
    cout << "fecha.getDayOfWeek(); "                        << fecha.getDayOfWeek() << endl;
```
Salida
```
fecha.getDayOfWeek(); ..........................................................7
```
