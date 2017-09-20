/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
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
