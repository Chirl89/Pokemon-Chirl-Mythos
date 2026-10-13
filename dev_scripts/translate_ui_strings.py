import re

path = "src/strings.c"
with open(path, "r", encoding="utf-8") as f:
    c = f.read()

replacements = {
    # Bag pockets table
    'COMPOUND_STRING("ITEMS")': 'COMPOUND_STRING("OBJETOS")',
    'COMPOUND_STRING("TMs & HMs")': 'COMPOUND_STRING("MT y MO")',
    'COMPOUND_STRING("BERRIES")': 'COMPOUND_STRING("BAYAS")',
    'COMPOUND_STRING("KEY ITEMS")': 'COMPOUND_STRING("OBJ. CLAVE")',
    'COMPOUND_STRING("MEDICINE")': 'COMPOUND_STRING("BOTIQUÍN")',
    'COMPOUND_STRING("BATTLE")': 'COMPOUND_STRING("COMBATE")',
    'COMPOUND_STRING("TREASURES")': 'COMPOUND_STRING("TESOROS")',

    # Strings
    '_("USE")': '_("USAR")',
    '_("TOSS")': '_("TIRAR")',
    '_("GIVE")': '_("DAR")',
    '_("CLOSE BAG")': '_("CERRAR MOCHILA")',
    '_("What would you like to do?")': '_("¿Qué deseas hacer?")',
    '_("Choose a POKéMON.")': '_("Elige un POKéMON.")',
    '_("Move to where?")': '_("¿A dónde mover?")',
    '_("Teach which POKéMON?")': '_("¿A qué POKéMON enseñar?")',
    '_("Use on which POKéMON?")': '_("¿Con qué POKéMON usar?")',
    '_("Give to which POKéMON?")': '_("¿A qué POKéMON dar?")',
    '_("Do what with this {PKMN}?")': '_("¿Qué hacer con este {PKMN}?")',
    '_("There\'s nothing to CUT.")': '_("No hay nada que CORTAR.")',
    '_("You can\'t SURF here.")': '_("No puedes hacer SURF aquí.")',
    '_("You\'re already SURFING.")': '_("Ya estás haciendo SURF.")',
    '_("Can\'t use that here.")': '_("No puedes usar eso aquí.")',
    '_("Restore which move?")': '_("¿Restaurar qué movimiento?")',
    '_("Boost PP of which move?")': '_("¿Subir PP de qué movimiento?")',
    '_("Do what with an item?")': '_("¿Qué hacer con el objeto?")',
    '_("Let\'s enjoy cycling!")': '_("¡A pedalear se ha dicho!")',
    '_("ABLE")': '_("PUEDE")',
    '_("NOT ABLE")': '_("NO PUEDE")',
    '_("ABLE!")': '_("¡PUEDE!")',
    '_("NOT ABLE!")': '_("¡NO PUEDE!")',
    '_("LEARNED")': '_("APRENDIDO")',
    '_("FLY to where?")': '_("¿A dónde VOLAR?")',
    '_("BOY")': '_("CHICO")',
    '_("GIRL")': '_("CHICA")',
    '_("Do you choose this POKéMON?")': '_("¿Eliges a este POKéMON?")',

    # Shop
    '_("BUY")': '_("COMPRAR")',
    '_("SELL")': '_("VENDER")',
    '_("QUIT")': '_("SALIR")',
    '_("SOLD OUT")': '_("AGOTADO")',
    '_("IN BAG: {STR_VAR_1}")': '_("EN MOCHILA: {STR_VAR_1}")',
    '_("Quit shopping.")': '_("Dejar de comprar.")',
    '_("You don\'t have enough money.{PAUSE_UNTIL_PRESS}")': '_("No tienes suficiente dinero.{PAUSE_UNTIL_PRESS}")',
    '_("I\'ll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}")': '_("Te daré también una HONOR BALL.{PAUSE_UNTIL_PRESS}")',
    '_("I\'ll throw in {STR_VAR_1} PREMIER BALLS, too.{PAUSE_UNTIL_PRESS}")': '_("Te daré también {STR_VAR_1} HONOR BALLS.{PAUSE_UNTIL_PRESS}")',
    '_("The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}")': '_("La saca de {STR_VAR_1} está llena.{PAUSE_UNTIL_PRESS}")',
    '_("You have no more room for this\\nitem.{PAUSE_UNTIL_PRESS}")': '_("No tienes espacio para este\\nobjeto.{PAUSE_UNTIL_PRESS}")',
    '_("Is there anything else I can help\\nyou with?")': '_("¿Puedo ayudarte en algo más?")',
    '_("Can I help you with anything else?")': '_("¿Puedo ayudarte en algo más?")',

    # Summary
    '_("POKéMON INFO")': '_("DATOS POKéMON")',
    '_("POKéMON SKILLS")': '_("HABILIDADES")',
    '_("BATTLE MOVES")': '_("MOVIMIENTOS")',
    '_("CONTEST MOVES")': '_("MOV. CONCURSO")',
    '_("POWER")': '_("POTENCIA")',
    '_("ACCURACY")': '_("PRECISIÓN")',
    '_("APPEAL")': '_("EXHIBICIÓN")',
    '_("JAM")': '_("INHIBICIÓN")',
    '_("STATUS")': '_("ESTADO")',
    '_("EXP. POINTS")': '_("PUNTOS EXP.")',
    '_("NEXT LV.")': '_("SIG. NIVEL")',
    '_("RIBBONS: {STR_VAR_1}")': '_("CINTAS: {STR_VAR_1}")',

    # Day Care
    '_("The two seem to get along\\nvery well.")': '_("Los dos se llevan\\nmuy bien.")',
    '_("The two seem to get along.")': '_("Los dos se llevan bastante bien.")',
    '_("The two don\'t seem to like\\neach other much.")': '_("No se gustan mucho.")',
    '_("The two prefer to play with other\\nPOKéMON than each other.")': '_("Prefieren jugar con otros\\nPOKéMON antes que entre ellos.")',

    # Eggs
    '_("It looks like this EGG will\\ntake a long time to hatch.")': '_("Parece que a este HUEVO aún le falta\\nmucho para abrirse.")',
    '_("What will hatch from this?\\nIt will take some time.")': '_("¿Qué saldrá de él?\\nAún tardará algún tiempo.")',
    '_("It moves occasionally.\\nIt should hatch soon.")': '_("Se mueve de vez en cuando.\\nPronto se abrirá.")',
    '_("It\'s making sounds.\\nIt\'s about to hatch!")': '_("¡Hace ruidos!\\n¡Está a punto de abrirse!")',
    '_("{STR_VAR_1} hatched from the EGG!")': '_("¡Del HUEVO ha nacido {STR_VAR_1}!")',
    '_("Would you like to nickname the newly\\nhatched {STR_VAR_1}?")': '_("¿Quieres ponerle un mote al recién\\nnacido {STR_VAR_1}?")',

    # Stats
    '_("MAX. HP")': '_("PS MÁX.")',
    '_("ATTACK")': '_("ATAQUE")',
    '_("DEFENSE")': '_("DEFENSA")',
    '_("SPEED")': '_("VELOCIDAD")',
    '_("SP. ATK")': '_("AT. ESP.")',
    '_("SP. DEF")': '_("DEF. ESP.")',

    # Days
    '_("SUNDAY")': '_("DOMINGO")',
    '_("MONDAY")': '_("LUNES")',
    '_("TUESDAY")': '_("MARTES")',
    '_("WEDNESDAY")': '_("MIÉRCOLES")',
    '_("THURSDAY")': '_("JUEVES")',
    '_("FRIDAY")': '_("VIERNES")',
    '_("SATURDAY")': '_("SÁBADO")',

    # Badges
    '_("BOULDERBADGE")': '_("MEDALLA ROCA")',
    '_("CASCADEBADGE")': '_("MEDALLA CASCADA")',
    '_("THUNDERBADGE")': '_("MEDALLA TRUENO")',
    '_("RAINBOWBADGE")': '_("MEDALLA ARCOÍRIS")',
    '_("SOULBADGE")': '_("MEDALLA ALMA")',
    '_("MARSHBADGE")': '_("MEDALLA PANTANO")',
    '_("VOLCANOBADGE")': '_("MEDALLA VOLCÁN")',
    '_("EARTHBADGE")': '_("MEDALLA TIERRA")',

    # Move Relearner
    '_("Teach which {STR_VAR_3} to\\n{STR_VAR_1}?")': '_("¿Qué {STR_VAR_3} enseñar a\\n{STR_VAR_1}?")',
    '_("Teach {STR_VAR_2}?")': '_("¿Enseñar {STR_VAR_2}?")',
    '_("{STR_VAR_1} learned\\n{STR_VAR_2}!")': '_("¡{STR_VAR_1} aprendió\\n{STR_VAR_2}!")',
    '_("Give up trying to teach a new\\nmove to {STR_VAR_1}?")': '_("¿Dejar de enseñar un nuevo\\nmovimiento a {STR_VAR_1}?")',
    '_("Which move should be\\nforgotten?\\p")': '_("¿Qué movimiento debe\\nolvidar?\\p")',

    # PC
    '_("SOMEONE\'S PC")': '_("PC DE ALGUIEN")',
    '_("LANETTE\'S PC")': '_("PC DE AREDIA")',
    '_("BILL\'S PC")': '_("PC DE BILL")',
    '_("{PLAYER}\'s PC")': '_("PC DE {PLAYER}")',
    '_("HALL OF FAME")': '_("HALL DE LA FAMA")',
    '_("LOG OFF")': '_("DESCONEXIÓN")',

    # Items in strings
    '_("ITEMS")': '_("OBJETOS")',
    '_("KEY ITEMS")': '_("OBJETOS CLAVE")',
    '_("POKé BALLS")': '_("POKé BALLS")',
    '_("TMs & HMs")': '_("MTs y MOs")',
    '_("BERRIES")': '_("BAYAS")',
    '_("MEDICINE")': '_("BOTIQUÍN")',
    '_("BATTLE ITEMS")': '_("OBJETOS COMBATE")',
    '_("TREASURES")': '_("TESOROS")',
}

for old, new in replacements.items():
    c = c.replace(old, new)

with open(path, "w", encoding="utf-8") as f:
    f.write(c)

print("[OK] UI strings updated in src/strings.c!")
