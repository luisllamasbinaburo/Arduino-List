# Librería Arduino List
Librería para Arduino que implementa un array de tamaño dinámico, es decir, una colección en la que es posible añadir o eliminar elementos, y la colección aumenta o disminuye su capacidad en función del número de elementos almacenados. 

Más información https://www.luisllamas.es/libreria-arduino-list/

## Instrucciones de uso
El funcionamiento de la clase List es similar a la clase Vector de C++, pero en una implementación sencilla que puede ser empleada en un procesador como Arduino. Sin embargo, los nombres de los métodos y variables se asemejan a la clase genérica List disponible en C#, más modernos y actualizados. 

La clase List se inicializa a una determinada capacidad, que por defecto es 4 elementos. Internamente la clase implementa un array del tamaño de la capacidad de la lista. La variable Count contabiliza el número de elementos ocupados en la lista. La lista está llena cuando el número de elementos es igual a la capacidad de la lista.  

En caso de añadir un elemento cuando la lista está llena, el array interno se copia a un nuevo array del doble de capacidad del array inicial. El proceso de expansión requiere la creación de un nuevo array y la copia de los elementos, lo que supone un tiempo adicional a una inserción simple.  

El acceso a los elementos de la lista se realiza mediante el indexador [], como en el caso de un array normal. Adicionalmente se disponen de métodos para añadir, insertar, reemplazar o eliminar elementos o series de elementos.

Los métodos Trim permiten ajustar la capacidad de la lista al número de elementos realmente ocupados, con objeto de reducir la memoria ocupada por la lista. Al igual que el proceso de expansión, la contracción requiere un tiempo adicional.

También se disponen de métodos para buscar elementos dentro de la lista, invertir los elementos, y para copiar los elementos desde y hacia un array externo.

Finalmente, se dispone de métodos especiales para insertar o eliminar elementos en la primera y última posición, que permiten implementar de forma sencilla estructuras de tipo LIFO (Pila) y FIFO (Cola).


### Constructor
La clase List se instancia a través de su constructor.
```c++
// Crea una nueva lista con capacidad 4
List();

// Crea una nueva lista con capacidad capacity
List(size_t capacity);
```

### Métodos generales
```c++
// Devuelve la capacidad de la lista
size_t Capacity() const;

// Devuelve el numero de elementos guardados en la lista
size_t Count() const;

// Devuelve true si la lista esta vacia
// false en caso contrario
bool IsEmpty();

// Devuelve true si la lista esta llena
// false en caso contrario
bool IsFull();

// Invierte los elementos de la lista
void Reverse();
```


### Acceder elementos
```c++
// Indexador de la lista permite acceder a un elemento usando list[index]
T& operator[](const size_t index);

// Devuelve el primer elemento de la lista
void First();

// Devuelve el ultimo elemento de la lista
void Last();
```


### Añadir elementos
```c++
// Añade un elemento al final de la lista
void Add(T item);

// Añade una serie de elementos al final de la lista
void AddRange(T* items, size_t numItems);
```

### Insertar elementos
```c++
// Inserta un elemento al principio de la lista
void Insert(T item);

// Inserta un elemento en la posicion indicada
void Insert(size_t index, T item);

// Inserta una serie de elementos al principio de la lista
void InsertRange(T* items, size_t numItems);

// Inserta una serie de elementos en la posicion indicada
void InsertRange(size_t index, T* items, size_t numItems);
```

### Reemplazar elementos
```c++
// Remplaza el elemento de la posicion indicada
void Replace(size_t index, T item);

// Reemplaza una serie de elementos en la posicion indicada
void ReplaceRange(size_t index, T* items, size_t numItems);
```

### Eliminar elementos
```c++
// Elimina todos los elementos de la lista
void Clear();

// Elimina el primer elemento de la lista
void RemoveFirst();

// Elimina el ultimo elemento de la lista
void RemoveLast();

// Elementa el elemento de la posicion indicada
void Remove(size_t index);

// Elimina una serie de elementos de la posicion indicada
void RemoveRange(size_t index, size_t numItems);
```

### Reducir capacidad
```c++
// Reduce la capacidad de la lista al numero de elementos para reducir la memoria empleada
void Trim();

// Reduce la capacidad de la lista al numero de elementos
// mas una cierta capacidad de reserva
void Trim(size_t reserve);	
```

### Buscar elementos
```c++
// Devuelve true si la lista contiene un elemento, false en caso contrario
bool Contains(T item);

// Devuelve el indice de la primera ocurencia de un elemento en la lista
size_t IndexOf(T item);
```

### Conversión desde/hacia arrays
```c++
// Devuelve todos los elementos de la lista en un nuevo array
T* ToArray();

// Devuelve una serie de elementos de la lista en un nuevo array
T* ToArray(size_t index, size_t numItems);

// Inicia una lista copiando los elementos desde un array existente
void FromArray(T* items, size_t numItems);

// Copia todos los elementos a un array existente
void CopyTo(T* items);

// Copia una serie de elementos a un array existente
void CopyTo(T* items, size_t index, size_t numItems);
```


## Ejemplos
La librería List incluye los siguientes ejemplos para ilustrar su uso.
* List: Ejemplo general de uso de la clase List.
```c++
#include "ListLib.h"

void setup() {
	Serial.begin(9600);
	
	// Crear una nueva lista
	List<int> list;
	
	// Añadir elementos de 0 a 10
	for (int i = 0; i <= 10; i++)
	{
		list.Add(i);
	}

	// Array para ejemplos con rangos
	int test[] = {100, 200, 300, 400, 500 };

	// Ejemplo añadir
	list.Add(1000);
	list.AddRange(test, 5);

	// Ejemplo insertar
	list.Insert(2, 2000);
	list.InsertRange(5, test, 5);

	// Ejemplo reemplazar
	list.Replace(2, 5000);
	list.ReplaceRange(3, test, 5);

	// Ejemplo de eliminar
	list.Remove(17);
	list.RemoveRange(2, 8);
	
	// Mostrar resultado por pantalla
	// y ejemplo acceso con indexador[]
	for (int i = 0; i < list.Count(); i++)
	{
		Serial.println(list[i]);
	}

	// Ejemplo IndexOf
	Serial.print("IndexOf: ");
	Serial.println(list.IndexOf(23));

	// Ejemplo Trim
	list.Trim();
	Serial.print("Capacity: ");
	Serial.println(list.Capacity());
}

void loop() {
  
}
```
