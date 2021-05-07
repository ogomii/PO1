#pragma once
#include "shapes.h"

void draw(const Drawable* obj){ obj->draw();}

/**
Drawable i Transformable to klasy które określaja akcje
możliwe do wykonania na obiektach, nie dziedziczą wiec po 
innych klasach. Point to klasa której głównym zadaniem jest
bycie kontenerem na dane, nie ma wiec pokrewienstwa z klasami
odpowiadajacymi za kształty. Klasy odpowiadajce za ksztalty 
dziela sie na dwa typy, zamkniete i inne, stworzona klasa 
ClosedShape odroznia te typy od siebie. Klasy kształtów 
,oprócz rozróżniania typów, dziedzicza po Drawable i Transformable
aby móc wykonywać na nich akcje określane przez te dwie klasy.
Klasa Point potrzebuje jedynie Transformable, klassa ClosedShape
służy jako rozróżnienie i dodanie funkcjonalności, dla ulatwienia
dziedziczy po Drawable i Transformable aby nie trzeba było tych klas
ponownie dołączać. 
*/ 