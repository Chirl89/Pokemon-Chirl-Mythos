import re

path = "src/pokemon_storage_system.c"
with open(path, "r", encoding="utf-8") as f:
    c = f.read()

replacements = {
    'COMPOUND_STRING("CANCEL")': 'COMPOUND_STRING("SALIR")',
    'COMPOUND_STRING("STORE")': 'COMPOUND_STRING("DEPOSITAR")',
    'COMPOUND_STRING("WITHDRAW")': 'COMPOUND_STRING("SACAR")',
    'COMPOUND_STRING("MOVE")': 'COMPOUND_STRING("MOVER")',
    'COMPOUND_STRING("SHIFT")': 'COMPOUND_STRING("CAMBIO")',
    'COMPOUND_STRING("PLACE")': 'COMPOUND_STRING("DEJAR")',
    'COMPOUND_STRING("SUMMARY")': 'COMPOUND_STRING("DATOS")',
    'COMPOUND_STRING("RELEASE")': 'COMPOUND_STRING("SOLTAR")',
    'COMPOUND_STRING("MARK")': 'COMPOUND_STRING("MARCAS")',
    'COMPOUND_STRING("JUMP")': 'COMPOUND_STRING("SALTAR")',
    'COMPOUND_STRING("WALLPAPER")': 'COMPOUND_STRING("FONDO")',
    'COMPOUND_STRING("NAME")': 'COMPOUND_STRING("NOMBRE")',
    'COMPOUND_STRING("TAKE")': 'COMPOUND_STRING("QUITAR")',
    '_("GIVE")': '_("DAR")',
    'COMPOUND_STRING("SWITCH")': 'COMPOUND_STRING("CAMBIAR")',
    'COMPOUND_STRING("BAG")': 'COMPOUND_STRING("MOCHILA")',
    'COMPOUND_STRING("INFO")': 'COMPOUND_STRING("INFO")',
    'COMPOUND_STRING("SCENERY 1")': 'COMPOUND_STRING("PAISAJE 1")',
    'COMPOUND_STRING("SCENERY 2")': 'COMPOUND_STRING("PAISAJE 2")',
    'COMPOUND_STRING("SCENERY 3")': 'COMPOUND_STRING("PAISAJE 3")',
    'COMPOUND_STRING("ETCETERA")': 'COMPOUND_STRING("OTROS")',
    'COMPOUND_STRING("FRIENDS")': 'COMPOUND_STRING("AMIGOS")',
    'COMPOUND_STRING("FOREST")': 'COMPOUND_STRING("BOSQUE")',
    'COMPOUND_STRING("CITY")': 'COMPOUND_STRING("CIUDAD")',
    'COMPOUND_STRING("DESERT")': 'COMPOUND_STRING("DESIERTO")',
    'COMPOUND_STRING("SAVANNA")': 'COMPOUND_STRING("SABANA")',
    'COMPOUND_STRING("CRAG")': 'COMPOUND_STRING("RISCO")',
    'COMPOUND_STRING("VOLCANO")': 'COMPOUND_STRING("VOLCÁN")',
    'COMPOUND_STRING("SNOW")': 'COMPOUND_STRING("NIEVE")',
    'COMPOUND_STRING("CAVE")': 'COMPOUND_STRING("CUEVA")',
    'COMPOUND_STRING("BEACH")': 'COMPOUND_STRING("PLAYA")',
    'COMPOUND_STRING("SEAFLOOR")': 'COMPOUND_STRING("FONDO MARINO")',
    'COMPOUND_STRING("RIVER")': 'COMPOUND_STRING("RÍO")',
    'COMPOUND_STRING("SKY")': 'COMPOUND_STRING("CIELO")',
    'COMPOUND_STRING("POLKA-DOT")': 'COMPOUND_STRING("LUNARES")',
    'COMPOUND_STRING("POKéCENTER")': 'COMPOUND_STRING("CENTRO POKé.")',
    'COMPOUND_STRING("MACHINE")': 'COMPOUND_STRING("MÁQUINA")',
    'COMPOUND_STRING("SIMPLE")': 'COMPOUND_STRING("SENCILLO")',
    'COMPOUND_STRING("SELECT")': 'COMPOUND_STRING("ELEGIR")',

    '_("There is just one POKéMON with you.")': '_("¡Es tu único POKéMON!")',
    '_("Your party is full!")': '_("¡Tu equipo está lleno!")',
    '_("BOX")': '_("CAJA")',
    'COMPOUND_STRING("WITHDRAW POKéMON")': 'COMPOUND_STRING("SACAR POKéMON")',
    'COMPOUND_STRING("Move POKéMON stored in BOXES to\\nyour party.")': 'COMPOUND_STRING("Pasa POKéMON de las CAJAS a\\ntu equipo.")',
    'COMPOUND_STRING("DEPOSIT POKéMON")': 'COMPOUND_STRING("DEPOSITAR POKéMON")',
    'COMPOUND_STRING("Store POKéMON in your party in BOXES.")': 'COMPOUND_STRING("Guarda POKéMON de tu equipo en\\nlas CAJAS.")',
    'COMPOUND_STRING("MOVE POKéMON")': 'COMPOUND_STRING("MOVER POKéMON")',
    'COMPOUND_STRING("Organize the POKéMON in BOXES and\\nin your party.")': 'COMPOUND_STRING("Organiza los POKéMON de las CAJAS y\\nde tu equipo.")',
    'COMPOUND_STRING("MOVE ITEMS")': 'COMPOUND_STRING("MOVER OBJETOS")',
    'COMPOUND_STRING("Move items held by any POKéMON\\nin a BOX or your party.")': 'COMPOUND_STRING("Mueve objetos que lleven POKéMON en\\nlas CAJAS o en tu equipo.")',
    'COMPOUND_STRING("SEE YA!")': 'COMPOUND_STRING("SALIR")',
    'COMPOUND_STRING("Return to the previous menu.")': 'COMPOUND_STRING("Vuelve al menú anterior.")',
    '_("{DYNAMIC 0} is selected.")': '_("{DYNAMIC 0} seleccionado.")',
    '_("Exit from the BOX?")': '_("¿Salir de las CAJAS?")',
    '_("What do you want to do?")': '_("¿Qué deseas hacer?")',
    '_("Please pick a theme.")': '_("Elige un tema.")',
    '_("Pick the wallpaper.")': '_("Elige un fondo.")',
    '_("Jump to which BOX?")': '_("¿A qué CAJA vas?")',
    '_("Deposit in which BOX?")': '_("¿En qué CAJA depositas?")',
    '_("{DYNAMIC 0} was deposited.")': '_("{DYNAMIC 0} fue depositado.")',
    '_("The BOX is full.")': '_("La CAJA está llena.")',
    '_("Release this POKéMON?")': '_("¿Quieres soltar este POKéMON?")',
    '_("{DYNAMIC 0} was released.")': '_("{DYNAMIC 0} fue liberado.")',
    '_("Bye-bye, {DYNAMIC 0}!")': '_("¡Adiós, {DYNAMIC 0}!")',
    '_("Can\'t release an EGG.")': '_("No puedes soltar un HUEVO.")',
    '_("Which one will you take?")': '_("¿Cuál vas a sacar?")',
    '_("You\'re holding a POKéMON!")': '_("¡Llevas un POKéMON cogido!")',
}

for old, new in replacements.items():
    c = c.replace(old, new)

with open(path, "w", encoding="utf-8") as f:
    f.write(c)

print("[OK] Pokemon storage system strings updated!")
