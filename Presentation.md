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
1. Spiel starten (3x3 Modus)
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

9. Compile-Option für FeldGröße zeigen und anwenden
10. Spiel neu starte und 4x4 kurz zeigen

## Nennenswerte Aspekte in Code > Simon
### Input Buffer
- Keine dynamische Memory allocation
- Verwendung von RingBuffer
- Head/Tail Pointer

### Zellen Neumalen ohne alles zu refreshen
- Nur Inhalt der aktuellen und letzten Zellen werden bei Bedarf neugemalt

### Vergrößern/Verkleinern > Paul
- 3 Größen verfügbar
- Möglich durch entkoppelung von Logik (welche Zellen sind markiert) und Präsentation
- Malen mit 2D Array statt string um alle Zellen in einer Schleife malen zu können

### __WFI()
- Hohe CPU Nutzung während Warteschleifen für Input aufgefallen
    - Permanentes checken ob input verfügbar
- Implementation von `wfi` Befehl um Prozessor in LowPowerMode bis nächsten Interrupt zu setzen

## Compile Time Optionen > Simon
- Größe bereits gezeigt (theoretisch beliebig möglich, aber Memory Limitationen)
- Außerdem zeit anpassen, unicode deaktivieren, und ascii art deaktieren
    - Recompile mit schnellen Ticks, vielen Ticks per Turn, ohne unicode, ohne ascii art

## Running und Building 
- Standartmäßig bauen über CMake
- direktes laufen ohne dependencies über docker image möglich
    - ganz kurz zeigen

## Ausblick (TODO) > Ben oder Max
- Bereits feature complete
- Optimierung von entry code und modulen aus Vorlesung für unseren Anwendungszweck
- Dokumentation


