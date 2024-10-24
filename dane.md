# Kroki do wykonania zadania: Gra w wisielca

## Krok 1: Przygotowanie projektu
1. **Utwórz projekt C++**: Rozpocznij nowy projekt w C++ w swoim IDE lub edytorze (np. Visual Studio Code). Upewnij się, że środowisko kompilacji działa poprawnie (np. używasz `g++`).
2. **Podziel projekt na pliki**: Stwórz pliki źródłowe. Przykładowo:
   - `main.cpp`: Główna funkcja programu.
   - `game.cpp`: Logika gry.
   - `game.hpp`: Plik nagłówkowy z deklaracjami funkcji.

## Krok 2: Wczytanie słów z pliku
1. **Stwórz plik `words.txt`**: W pliku tym umieść listę słów, które będą używane w grze.
2. **Wczytaj słowa**: Zaimplementuj funkcję, która otworzy plik `words.txt` i wczyta słowa do tablicy lub wektora. Następnie losuj jedno słowo na potrzeby gry.

## Krok 3: Interfejs użytkownika
1. **Wyświetl menu**: Po uruchomieniu programu wyświetl użytkownikowi menu z opcjami (np. wybór poziomu trudności, rozpoczęcie gry, wyjście).
2. **Wybór poziomu trudności**: Zapewnij możliwość wyboru poziomu trudności, który ustala liczbę prób. Przykładowo:
   - Łatwy: 10 prób.
   - Trudny: 5 prób.

## Krok 4: Rozpoczęcie gry
1. **Ukryj słowo**: Po wylosowaniu słowa, wyświetl tyle podkreślników, ile liter ma to słowo. Na przykład, jeśli wylosowane słowo to „kot”, wyświetl: `_ _ _`.
2. **Wczytaj literę od użytkownika**: W pętli pobieraj litery od użytkownika i sprawdzaj, czy litera znajduje się w słowie.

## Krok 5: Sprawdzanie i aktualizacja gry
1. **Aktualizuj stan gry**: Jeśli użytkownik odgadnie literę, pokaż ją w odpowiednich miejscach w słowie. Jeśli nie, zmniejsz liczbę dostępnych prób.
2. **Wyświetl postęp**: Po każdej próbie wyczyść ekran i wyświetl aktualny stan słowa (np. `K _ T`).
3. **Obsłuż błędy**: Jeśli użytkownik poda coś innego niż literę, wyświetl stosowny komunikat i poproś o poprawne dane.

## Krok 6: Zakończenie gry
1. **Warunki zakończenia**: Gra kończy się, gdy:
   - Użytkownik odgadnie całe słowo.
   - Skończą się próby.
2. **Wyświetl wynik**: Po zakończeniu gry wyświetl, czy użytkownik wygrał, czy przegrał, oraz jakie było poprawne słowo.

## Krok 7: Zapis wyników
1. **Zapytaj o imię**: Po zakończeniu gry zapytaj użytkownika o jego imię.
2. **Zapisz wynik do pliku `scores.txt`**: Zapisz imię użytkownika oraz wynik (np. liczba prób, które pozostały) do pliku `scores.txt`.

## Krok 8: Wyświetlanie rankingu
1. **Opcja wyświetlania rankingu**: Dodaj do menu opcję, która pozwoli użytkownikowi wyświetlić ranking najlepszych wyników (np. trzy najlepsze wyniki).
2. **Odczytaj plik `scores.txt`**: Stwórz funkcję, która odczyta dane z pliku `scores.txt`, posortuje wyniki według liczby pozostałych prób i wyświetli najlepsze.

## Krok 9: Dodanie logiki warunkowej i pętli
1. **Warunki i pętle**: Zastosuj instrukcje warunkowe (`if`, `else`, `switch`) do obsługi menu, zakończenia gry, oraz wyboru poziomu trudności.
2. **Operacje arytmetyczne i logiczne**: Użyj operatorów arytmetycznych do zliczania prób i logicznych do sprawdzania poprawności liter.

## Krok 10: Ostateczne poprawki
1. **Stałe**: Dodaj chociaż jedną stałą do projektu (np. stała dla maksymalnej liczby prób).
2. **Optymalizacje**: Sprawdź, czy kod jest czytelny, zoptymalizowany i dobrze podzielony na funkcje.

## Krok 11: Testowanie
1. **Testuj grę**: Uruchom program kilka razy, aby upewnić się, że działa poprawnie na różnych poziomach trudności oraz że wszystkie funkcje (wczytywanie słów, zapisywanie wyników, obsługa błędów) działają zgodnie z oczekiwaniami.
