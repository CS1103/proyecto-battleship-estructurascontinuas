<a href="Utec"><img src="https://camo.githubusercontent.com/9809861efbc42f59a67d8a622b79b0a71722d35c/687474703a2f2f312e62702e626c6f6773706f742e636f6d2f5f7644585969424b4e4855302f5230512d434d6f654c55492f414141414141414142726b2f6d5457315258367a314b412f733430302f426174746c65736869705f4c6f676f2e6a7067" title="Utec" alt="Utec"></a>

# Battleship

> Resumen del juego
- Battleship es un juego compuesto por dos tableros conformados por un conjunto de posiciones o celdas, descritas a partir de coordenadas específicas. Cada jugador inicia con un conjunto de naves conformadas por un Aircraft Carrier, dos Battlecruisers, tres Submarines y cuatro Torpedo boats. Las naves se ubican aleatoriamente en el tablero de cada jugador y el espacio que ocupan se determina de acuerdo a su tamaño y orientación. Después de la ubicación de todas las naves, uno de los jugadores envía, a través de una coordenada, la posición en el tablero de su oponente en el que pretende atacar sus naves. El objetivo del juego es descubrir la ubicación de todas las naves del oponente y hundir a toda su flota, el primer jugador que lo consiga, es el ganador.

> Resumen del programa
- El programa consta de un servidor que devolverá un archivo .out (respuesta) a partir de los archivos .in que envían los jugadores por cada acción. Las acciones desarrolladas hasta el momento corresponden a la primera parte del desarrollo juego en el que se inscribe al equipo a partir de un nombre y se espera la respuesta de aceptación que además incluirá un Token y los límites del Scope (tablero del jugador). Posteriormente, para agregar a las naves se sigue el mismo procedimiento, generando un .in para cada nave, en el que se envía el Token (para identificar a qué jugador corresponde), y un segundo parámetro que indica el modelo de nave, las coordenadas en las que se posicionará y la orientación, siguiendo el formato (Nave-Coordenada-Orientación).
Para el proceso de comunicación entre el servidor y los jugadores se contará con un observer que permitirá reconocer el momento en el que el jugador recibe la respuesta del servidor y poder continuar con el siguiente paso.


> Indicaciones
- Para esta versión preliminar del proyecto se seguirán las siguientes indicaciones para su ejecución:
1. Inicialmente las carpetas /in y /out deben encontrarse vacías. El programa generará el primer archivo .in que corresponde a la acción Handshake. Dado que aún no se realiza la conexión con el servidor, de manera manual agregaremos el archivo .out (creado en la carpeta /manual/1) a la carpeta /out (simulando la respuesta del servidor).

2. Después de la aceptación del Handshake, el programa nos indicará que nos encontramos en el paso 2 que corresponde a colocar las naves en el tablero. Después de que el programa nos genere el primer .in en la carpeta /in, de manera manual copiaremos el archivo .out de la carpeta /manual/2 en la carpeta /out simulando la respuesta del servidor, que nos indicará si la posición ingresada es aceptada y se actualizará el tablero en un caso favorable. El proceso se repite hasta agregar a todas las naves en el tablero.

## Equipo

> Contribuyentes

| <a target="_blank">**Luis Berrospi**</a> | <a target="_blank">**Mario Rios**</a> | <a target="_blank">**Daniela Cauti**</a> |<a target="_blank">**Milagros Yupanqui**</a> |
| :---: | :---:| :---:| :---:|
| ![Luis](https://avatars2.githubusercontent.com/u/52045791?v=3&s=150) | ![Mario](https://avatars2.githubusercontent.com/u/57011629?v=3&s=150) | ![Daniela](https://avatars2.githubusercontent.com/u/52045791?v=3&s=150) | ![Milagros](https://avatars2.githubusercontent.com/u/55298493?v=3&s=150) |
| <a href="https://github.com/lender512" target="_blank">`github.com/lender512`</a> | <a href="https://github.com/morphisjustfun" target="_blank">`github.com/morphisjustfun`</a> | <a href="https://github.com/daniela08" target="_blank">`github.com/daniela08`</a> |<a href="https://github.com/miyulo139" target="_blank">`github.com/miyulo139`</a> |
