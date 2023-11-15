# Projektplan

Grupp nr: 5
Namn: Erling Blomberg, Christopher Jernberg, Olle Thor

**Document Overview:**
- [Problemformulering](#problemformulering)
- [Högnivådesign](#högnivådesign)
- [Hårdvarubeskrivning](#hårdvarubeskrivning)
- [Beteendebeskrivning](#beteendebeskrivning)
- [Kommunicationsbeskrivning](#Kommunicationsbeskrivning)
- [Deluppgifter](#deluppgifter)
- [Tidsplan](#tidsplan)

## Problemformulering

Målet med projektet är att skapa en robot byggd i lego (och 3d printade delar) som ska kunna kartlägga en stad, representerad av legovägar med en röd mittlinje. Roboten kommer inte veta hur staden ser ut i förväg och inte heller storleken på staden.

## Högnivådesign

För en robot som ska kunna lösa problemet innefattar högnivådesignen: rörelse, linjeigenkänning, kommunikation mellan dessa system, kartläggning och presentation av kartan.

## Hårdvarubeskrivning

Roboten kommer byggas i lego och kompletteras med 3d printade bitar. För att driva roboten kommer en DC motor användas, och miniservo för att styra roboten. Motorn och servon kommer styras av en ESP8266 nodemcu mikrodator som kommer att vara kopplad till en ESP motorshield. Till linjeigenkänning kommer en maix dock m1 användas som kameramodul. Mikrodatorn kommer kommunicera med kommunikationsprotokollet UART och drivas av en powerbank.

### Enkelt blockdiagram över hårdvara:

(Insert block diagram here)

## Beteendebeskrivning

- Roboten ska alltid sträva att köra så att den har linjen under sin mitt.
- Roboten ska alltid sträva att köra den kortaste distansen för att fullborda kartläggningen.
- Om roboten kommer till en korsning ska den markera de sträckor som den inte har kartlagt.
  
Om tid finns över innan deadline kan två lägen implementeras:
- Ett snabbt då roboten inte ska åka längs hela linjen utan dra slutsatser hur kartan ser ut utefter vilka områden som den har markerat men inte utforskat. Robotens beteende ska då ha detta i åtanke så att den åker de sträckor som ger mest information.
- Ett med precision i focus då roboten ska utforska hela sträckan.

## Kommunikationsbeskrivning

- Kommunikationen från roboten ska ske i realtid
  
## Deluppgifter

### Konstruktion och tester :

- Motor | få motorn att köra
- Servo | få servon att svänga
- Fjärrstyrning | få roboten att kunna köra och styra

### Kamera och linje-detektion :

- Kamera | visa input från kameran när kabel är inkopplad
- Linje detektion | få mikrodatorn att visa kameradata med detekterade linjer över fönstret

### Trådlös kommunikation :

- Trådlös kommunikation | få data från kamera att visas i program på datorn
- Kartläggning | få programmet att rita en karta av färden utifrån sensor data från roboten

## Tidsplan

| Planering | vecka: | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 | 51 | 2  | 3  | 4  | 5  | 6  | 7  |
|------------|--------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Motor, servo och fjärrstyrning | x | x | x | x |   |   |   | H |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Kamera och linje-detektion     |   | x | x | x | x | x | x | Ö |   |   |   |   |   |   |   |   |   |   |   |   |   |
| Trådlös kommunikation         |   |   | x | x | x | x | x | S | x |   |   |   |   |   |   |   |   |   |   |   |   |
| Milestone 1                   | - | - | - | - | - | - | - | T | x | - | - | - | - | - | - | - | - | - | - | - | - |
| Beteende på mikrodator        |   |   |   |   | x | x | x  | L | x | x | x | x | x | x |   |   |   |   |   |   |   |
| Kartläggning                  |   |   |   |   |   |   |   | O | x | x | x | x | x | x | x |   |   |   |   |   |   |
| Milestone 2                   | - | - | - | - | - | - | - | V | - | - | - | - | - | - | x | - | - | - | - | - | - |
| Projektrapport                |   |   |   |   |   |   |   |   |   |   |   |   |   | x | x | x | x | x | x | x |   |
| Praktisk examination           |           |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   | x |   |   |
