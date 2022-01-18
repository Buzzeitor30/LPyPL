// Ejemplo de funciones y variables globales y locales
// Lee dos numeros (0 <= (x, y) < 10) y obtiene (x+y/2)
//-----------------------------------------------------
int a[10];

bool inicializa (int x)
{ int i;
  i = 0;
<<<<<<< HEAD
  while (i < x) { a[i] = i; i = i+1;}
=======
  while (i < x) { a[i] = i; i = i+1;print(a[i-1]);}
>>>>>>> origin/main

  return true;
}

int suma(int x, int y)
{ int a;
  
  a = x+y;
  
  return a;
}

int division(int x, int y)
{
  return x/y;
}

int x; int y;

int main()
{ int i; bool ok;
  
  ok = !inicializa(10);
  while (! ok ) {
    read(x); read(y);
    if (((x>=0) && (x<10)) && ((y>=0) && (y<10))) ok = true;
    else {}
  }

  print( division(suma(a[x], y), 2));
  
  return 0;
}
