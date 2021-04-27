# DoorsOS Kernel Library

## What Is DoorsOS?
DoorsOS Is a Linux / Unix Based OS with a basic interface and
easy server setup.

## How to Compile
To Compile the Kernel (RECOMMENDED)

```
$ make all
```

Advanced Compilations (DEVELOPERS)

```
$ make assembly
$ make code
$ make dev
```

## DC (Door C)

```c

#include <doors/lib.h>

Bool Cache_Redir(DoorsObjectStr * stream)
{
    stream->write("Hello, World!");
}

void DoorsMain()
{
    Cache_Redir();
}

```

```c

#include <doors/processor.h> /* gives us Int, Hex, String, And Such. */

#include <doors/output.h> /* Gives us DoorsPrintln() and ClearScreen() */


#include <doors/mathematics.h> /* __null, HEX(Int), StringLength(Str), Implements binaries for Integer And Binary Values.*/

unsigned int process(Hex T, Int C)
{
    if (T.binary == HEX(C)) return 1;
    else return 2;
}

void DoorsMain() {
    Int Streak = 1;
    Hex Bottle = 0x002; // give our bottle a nice id
    
    if (process(Bottle, Streak))
    {
        setLine(DOORS_RLINE); //set our line to the most recent line assuming that 
        // Doors is extracting this using the Modified GCC Assembly.
        
        DoorsPrintln("Wait.. IMPOSSIBLE");
    }
    else 
    {
        DoorsPrintln("Makes sense");
    }
}



```