# Esquema general de conexion

## Resumen de la modificacion

El tapete original necesita `+5V` para energizar su electronica. En este mod se comparte alimentacion y tierra con un `Arduino Micro`, mientras que las lineas de los pads y pedales se leen desde entradas digitales del microcontrolador para convertir cada activacion en un mensaje USB MIDI.

## Diagrama de bloques

```mermaid
flowchart LR
    HOST&POWER["PC / DAW / Host USB / 5V + GND"] --> | MICRO["Arduino Micro"]
    MICRO --> |"USB MIDI"|
    PADS["Pads y pedales del tapete"] -->|"Senales de trigger"| INPUTS["D2 a D10"]
    INPUTS --> MICRO
    GND["Tierra comun"] --- MICRO
    GND --- PADS
```

## Conexion sugerida

| Funcion | Conexion |
| --- | --- |
| Alimentacion del tapete | `5V` del Arduino hacia la entrada de alimentacion del tapete |
| Tierra comun | `GND` del Arduino unido al `GND` del tapete |
| Trigger 1 | Salida de pad/pedal a `D2` |
| Trigger 2 | Salida de pad/pedal a `D3` |
| Trigger 3 | Salida de pad/pedal a `D4` |
| Trigger 4 | Salida de pad/pedal a `D5` |
| Trigger 5 | Salida de pad/pedal a `D6` |
| Trigger 6 | Salida de pad/pedal a `D7` |
| Trigger 7 | Salida de pad/pedal a `D8` |
| Trigger 8 | Salida de pad/pedal a `D9` |
| Trigger 9 | Salida de pad/pedal a `D10` |

## Validaciones recomendadas

- Medir con multimetro antes de soldar para confirmar donde esta el `+5V`.
- Confirmar si cada trigger entra al Arduino como `HIGH` o como `LOW`.
- Verificar que ninguna linea de senal reciba `5V` directos si el tapete trabaja internamente a `3.3V`.
- Comprobar que el `Arduino Micro` sigue enumerando correctamente por USB despues del mod.
