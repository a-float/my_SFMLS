Sortujemy tablicę rosnąco O(nlogn) (potencjalnie O(n))
Następnie przechodzimy w pętli po kazdym jej elemencie i wywołujemy funkcję check(x,arr, to_avoid),
która sprawdzi czy istnieją dwa takie elementy tablicy arr, które dają sumę x = danegmu elementowi.
to_avoid jest indeksem elementu który jest docelową sumą.
Funkcja rozpoczyna zaczyna z licznikiem i ustawionym na początek tablicy oraz j na jej koniec.

jezeli i == to_avoid i=+1 - poszuiwana suma nie moze być składnikiem swojej sumy (x+0 = x) z poelcnia mają być inne
jezeli j == to_avoid j=-1
dopóki i < j
	Sprawdza czy suma elementów pod tymi indeksami jest równa x
		jeżeli tak zwraca True
		jeżeli nie 
			to jeżeli suma jest mniejsza od x
				i +=1 
				jezeli i == to_avoid to i+=1
			jezeli większa to 
				j -= 1
				jezeli j == to_avoid to j-=1  
jezli nie znaleziono takiej sumy zwracamy False

Jeżeli dla każdej iteracji pętli funkcja check() zwróci True - to zwracamy prawdę
Jeżeli dla dla jednej z iteracji check() zwróci False przerywamy pętle i zwracamy False

Złożoność jednego sprawdzania O(logn) razy ilość iteracji w petli n to O(nlogn)
Złożoność algorytmu O(nlogn), gdzie n to długość tablicy.