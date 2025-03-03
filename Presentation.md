# Präsentation 04.03.2025

## Übersicht Aufbau
1. Einleitung
2. Grobe Überlick Architektur
2. Überlick Spiel
4. Nennenswerte Aspekte in Code
5. Compile time Optionen
6. Building/Running
7. Ausblick

## Einleitung > Simon

- TikTakToe Projekt

## Architektur > Paul
![Ansicht](https://github.com/user-attachments/assets/ac9f3c44-f19c-4fc7-9869-ddfb3f9d6aef)
__ANSICHT 1: Dateisystem (Yazi?)
### Schichten
- Schichten Architektur zur entkoppelung von Komponenten
- (Anmerken, dass wir nicht 100% streng hier sind?)
#### Hardware Abstraction Layer
- Direkte Kommunikation mit Hardware Componenten
- Insb. Module aus Vorlesung, aber auch bspw. memset oder __WFI() implementation

#### Logic
- Spiele Logik
- Input Verarbeitung, Zeitmanagement, "bot", ...

#### Presentation
- Im Prinzip alles was der Nutzer zu Gesicht bekommt
- Menüs, Spiel UI, SpielFeld/Zellen, ASCII Art, Styles...

#### Sonstiges
##### utils
- Hilfsfunktionen die nirgends zu 100% gepasst haben

##### entry
- Einstieg aus der Vorlesung, aktuell (fast) unverändert, nur Verhalten von Default_Handler und HardFault_Handler angepasst

### Basic Flow
1. entry
2. hardware init
3. game menu
4. (on game start) game init

## Überblick Spiel > Max oder Ben
![Ansicht 2 (nach Command)](https://github.com/user-attachments/assets/d39ecbd4-a50f-4ada-a90f-785c7575cd6c)
__ANSICHT 2: Terminal
1. Spiel starten (3x3 Modus)
__COMMAND 1: `make run` | vorher bauen mit `make ROWS=3 COLS=3`
2. Hauptmenü zeigen
3. Kurz auf Punkte eingehen
4. Spiel starten
5. 1/2 Züge spielen
6. Funktionen während Spiel zeigen
    - Vergrößern/Verkleinern (+/-)
    - Controlview anzeigen (?)
    - Pausieren
7. Zu Ende Spielen
9. Statistiken

8. ! Aber wir sollten ja 4x4 machen :O **> Ben oder Max**
__COMMAND 2: `make ROWS=4 COLS=4 run`

9. Compile-Option für FeldGröße zeigen und anwenden
10. Spiel neu starte und 4x4 kurz zeigen
    - Anmerken, dass das der Standard ist

## Nennenswerte Aspekte in Code > Simon
### Input Buffer
![Ansicht 3](https://github.com/user-attachments/assets/81c768e4-9a55-4dc6-b9ba-6c49737d4c8e)

__ANSICHT 3: input_buf.h SPLIT input_buf.c
- Keine dynamische Memory allocation
- Verwendung von RingBuffer
- Head/Tail Pointer

### Zellen Neumalen ohne alles zu refreshen
![Ansicht 4](https://github.com/user-attachments/assets/b5082a71-1cc1-4ac8-9c3d-c77e437d55df)
__ANSICHT 4: cell.c -> cell_select(), redrawCell() - alles andere folden
- Nur Inhalt der aktuellen und letzten Zellen werden bei Bedarf neugemalt
- erst cell_select zeigen, dann redrawCell (am besten anmerkden, dass bisschen tief genestet ist...)

### Vergrößern/Verkleinern > Paul
![Ansicht 5](https://github.com/user-attachments/assets/955efb78-c715-4db2-a573-dfee62834321)
__ANSICHT 5: cell.h -> Size + CellSize, cell.c -> ARRAYS
- 3 Größen verfügbar
- Möglich durch entkoppelung von Logik (welche Zellen sind markiert) und Präsentation
- Malen mit 2D Array statt string um alle Zellen in einer Schleife malen zu können

### __WFI()
![Ansicht 6](https://github.com/user-attachments/assets/8eefa502-3e72-44d7-bc14-799ebcd7061d)
_\_ANSICHT 6: menu.c -> menu_showMainMenu() waiting loop, nvic.h -> definition von __WFI()
- Hohe CPU Nutzung während Warteschleifen für Input aufgefallen
    - Permanentes checken ob input verfügbar
- Implementation von `wfi` Befehl um Prozessor in LowPowerMode bis nächsten Interrupt zu setzen

## Compile Time Optionen > Simon
![Ansicht 7](https://github.com/user-attachments/assets/1c1423d9-410f-4132-9b4c-136bc33f1651)
__ANSICHT 7: Makefile
- Größe bereits gezeigt (theoretisch beliebig möglich, aber Memory Limitationen)
__COMMAND 3: `make ROWS=3 COLS=7 TICK_SPEED=11 TICKS_PER_TURN=30 UNICODE=OFF ASCII_ART=OFF run`
- Außerdem zeit anpassen, unicode deaktivieren, und ascii art deaktieren
    - Recompile mit schnellen Ticks, vielen Ticks per Turn, ohne unicode, ohne ascii art

## Running und Building 
![Ansicht 8](https://github.com/user-attachments/assets/565c9722-1b3d-41c6-8d23-6d90bee9638a)
__ANSICHT 8: CMakeLists.txt, Dockerfile
- Standartmäßig bauen über CMake
__COMMAND 4: `docker run -it ghcr.io/softwareengineeringone/tiktaktoe:latest`
- direktes laufen ohne dependencies über docker image möglich
    - ganz kurz zeigen

## Ausblick (TODO) > Ben oder Max
![Ansicht 9](https://github.com/user-attachments/assets/16375cd7-6677-4ad8-8105-bad665308c07)
__ANSICHT 9: Main Menu
- Bereits feature complete
- Optimierung von entry code und modulen aus Vorlesung für unseren Anwendungszweck
- Dokumentation


