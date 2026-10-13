import re

translations = {
    "NewBarkTown_Lab_Text_ElmAideIsWaiting": [
        "¡{PLAYER}!\\p",
        "¿Qué haces aquí?\\p",
        "¡Mi ayudante te está esperando\\n",
        "en CIUDAD MALVALONA!$"
    ],
    "NewBarkTown_Lab_Text_ShouldntTouch": [
        "¡Será mejor no tocarlo!$"
    ],
    "NewBarkTown_Lab_Text_ElmIntro": [
        "ELM: ¡{PLAYER}! ¡Por fin llegas!\\p",
        "Quería pedirte un favor.\\p",
        "Verás, estoy investigando algo\\n",
        "nuevo sobre los POKéMON. Me\\l",
        "preguntaba si podrías echarme\\l",
        "una mano, {PLAYER}.\\p",
        "Te explico…\\p",
        "Estoy escribiendo un informe que\\n",
        "quiero presentar en una conferencia.\\p",
        "Pero aún hay cosas que se me\\n",
        "escapan.\\p",
        "¡Por eso!\\p",
        "Me gustaría que entrenases a un\\n",
        "POKéMON que capturé hace poco.$"
    ],
    "NewBarkTown_Lab_Text_ElmAccepted": [
        "¡Gracias, {PLAYER}!\\n",
        "¡Eres de gran ayuda!$"
    ],
    "NewBarkTown_Lab_Text_ElmRefused": [
        "Pero… ¡Por favor, necesito tu\\n",
        "ayuda!$"
    ],
    "NewBarkTown_Lab_Text_ElmResearchAmbitions": [
        "Cuando anuncie mis descubrimientos,\\n",
        "¡seguro que desvelaremos aún más\\l",
        "misterios sobre los POKéMON!$"
    ],
    "NewBarkTown_Lab_Text_ElmGotAnEmail": [
        "¡Oh, vaya! ¡He recibido un correo!\\p",
        "… … … … … … … …\\n",
        "Hum… Ya veo…\\p",
        "Entendido…$"
    ],
    "NewBarkTown_Lab_Text_ElmMissionFromMrPokemon": [
        "Oye, escucha.\\p",
        "Tengo un conocido al que todos\\n",
        "llaman SR. POKéMON.\\p",
        "Siempre está encontrando cosas raras\\n",
        "y presumiendo de sus descubrimientos.\\p",
        "Pues bien, me acaba de enviar un correo\\n",
        "diciendo que esta vez va en serio.\\p",
        "Es muy intrigante, pero nosotros estamos\\n",
        "hasta arriba con nuestras investigaciones...\\p",
        "¡Espera!\\n",
        "¡Ya lo tengo!\\p",
        "{PLAYER}, ¿podrías ir tú en\\n",
        "nuestro lugar?$"
    ],
    "NewBarkTown_Lab_Text_ElmChooseAPokemon": [
        "Quiero que entrenes a uno de los\\n",
        "POKéMON que hay en estas BALLS.\\p",
        "¡Serás su primer compañero,\\n",
        "{PLAYER}!\\p",
        "¡Adelante, elige uno!$"
    ],
    "NewBarkTown_Lab_Text_ElmWhereGoing": [
        "ELM: ¡Espera! ¿Adónde vas?$"
    ],
    "NewBarkTown_Lab_Text_ChooseCyndaquil": [
        "ELM: ¿Te quedas con {STR_VAR_1},\\n",
        "el POKéMON de tipo {STR_VAR_2}?$"
    ],
    "NewBarkTown_Lab_Text_ChooseTotodile": [
        "ELM: ¿Quieres a {STR_VAR_1},\\n",
        "el POKéMON de tipo {STR_VAR_2}?$"
    ],
    "NewBarkTown_Lab_Text_ChooseChikorita": [
        "ELM: ¿Así que te gusta {STR_VAR_1},\\n",
        "el POKéMON de tipo {STR_VAR_2}?$"
    ],
    "NewBarkTown_Lab_Text_DidntChooseStarter": [
        "ELM: Piénsatelo con calma.\\p",
        "Elegir compañero es una decisión\\n",
        "muy importante.$"
    ],
    "NewBarkTown_Lab_Text_ChoseStarter": [
        "ELM: ¡A mí también me parece un\\n",
        "POKéMON magnífico!$"
    ],
    "NewBarkTown_Lab_Text_ReceivedStarter": [
        "¡{PLAYER} recibió a {STR_VAR_1}!$"
    ],
    "NewBarkTown_Lab_Text_Nickname": [
        "¿Quieres ponerle un mote a\\n",
        "{STR_VAR_1}?$"
    ],
    "NewBarkTown_Lab_Text_ElmDirections1": [
        "El SR. POKéMON vive un poco más allá\\n",
        "de CIUDAD CEREZO, la ciudad vecina.\\p",
        "Es prácticamente en línea recta,\\n",
        "así que no tiene pérdida.\\p",
        "Pero por si acaso, tienes mi número\\n",
        "de teléfono. ¡Llámame si pasa algo!$"
    ],
    "NewBarkTown_Lab_Text_ElmDirections1_Register": [
        "El SR. POKéMON vive un poco más allá\\n",
        "de CIUDAD CEREZO, la ciudad vecina.\\p",
        "Es prácticamente en línea recta,\\n",
        "así que no tiene pérdida.\\p",
        "Espera, deja que registre mi número\\n",
        "en tu POKéGEAR.$"
    ],
    "NewBarkTown_Lab_Text_RegisteredElm": [
        "Se registró al PROF. ELM en el\\n",
        "POKéGEAR.$"
    ],
    "NewBarkTown_Lab_Text_ElmLetYourMonBattle": [
        "Si aparece un POKéMON salvaje,\\n",
        "¡haz que tu POKéMON luche contra él!$"
    ],
    "NewBarkTown_Lab_Text_ElmDirections2": [
        "El SR. POKéMON vive un poco más allá\\n",
        "de CIUDAD CEREZO, la ciudad vecina.\\p",
        "¡Cuídate mucho!$"
    ],
    "NewBarkTown_Lab_Text_GotElmsNumber": [
        "¡Ya tienes mi número! ¡Llámame\\n",
        "si pasa cualquier cosa!$"
    ],
    "NewBarkTown_Lab_Text_ElmDescribesMrPokemon": [
        "El SR. POKéMON vive un poco más allá\\n",
        "de CIUDAD CEREZO, la siguiente ciudad.\\p",
        "Es casi una ruta directa, no tiene pérdida.\\p",
        "Pero por si acaso, toma mi número de\\n",
        "teléfono. ¡Llámame si surge algo!$"
    ],
    "NewBarkTown_Lab_Text_ElmPokeBall": [
        "Contiene un POKéMON capturado por\\n",
        "el PROF. ELM.$"
    ],
    "NewBarkTown_Lab_Text_ElmAfterTheft1": [
        "ELM: ¡{PLAYER}! ¡Es terrible!\\p",
        "¡Nos han robado un POKéMON!\\p",
        "¿Cómo ha podido pasar esto?$"
    ],
    "NewBarkTown_Lab_Text_ElmAfterTheft2": [
        "ELM: ¿Qué decía el SR. POKéMON?$"
    ],
    "NewBarkTown_Lab_Text_ElmAfterTheft3": [
        "¡{PLAYER} le entregó el HUEVO\\n",
        "MISTERIOSO al PROF. ELM!$"
    ],
    "NewBarkTown_Lab_Text_ElmAfterTheft4": [
        "ELM: ¿Esto es...? ¿Un HUEVO POKéMON?\\p",
        "Si es así, ¡es un descubrimiento\\n",
        "asombroso!\\p",
        "¿Qué? ¿El PROF. OAK te dio una\\n",
        "POKéDEX?\\p",
        "¡{PLAYER}, eso es increíble!\\p",
        "El PROF. OAK tiene un ojo clínico para\\n",
        "ver el potencial de los ENTRENADORES.\\p",
        "¡Tienes madera para llegar a la cima\\n",
        "de la LIGA POKéMON!\\p",
        "Deberías desafiar a los LÍDERES DE\\n",
        "GIMNASIO de JOHTO.\\p",
        "El más cercano está en\\n",
        "CIUDAD MALVALONA.$"
    ],
    "NewBarkTown_Lab_Text_ElmStudyingEgg": [
        "ELM: ¡Sigo investigando el HUEVO!\\n",
        "Te avisaré si descubro algo.$"
    ],
    "NewBarkTown_Lab_Text_ElmAideHasEgg": [
        "ELM: ¡{PLAYER}!\\p",
        "¿Te has cruzado con mi ayudante?\\n",
        "Te estaba buscando con el HUEVO.$"
    ],
    "NewBarkTown_Lab_Text_ElmWaitingEggHatch": [
        "ELM: ¡{PLAYER}!\\n",
        "¿Cómo va ese HUEVO? ¿Ha eclosionado?\\p",
        "¡Trátalo con mucho cariño!$"
    ],
    "NewBarkTown_Lab_Text_ElmThoughtEggHatched": [
        "ELM: ¡{PLAYER}!\\n",
        "¿Ha eclosionado el HUEVO?\\p",
        "¡Quiero ver a ese POKéMON!$"
    ],
    "NewBarkTown_Lab_Text_ShowTogepi1": [
        "ELM: ¡{PLAYER}! ¡Ese POKéMON!\\n",
        "¡Eclosionó del HUEVO!\\p",
        "¡Es fascinante!$"
    ],
    "NewBarkTown_Lab_Text_ShowTogepi2": [
        "¡Sabía que los POKéMON nacían\\n",
        "de HUEVOS!\\p",
        "¡Gracias por ayudarme con mi\\n",
        "investigación, {PLAYER}!$"
    ],
    "NewBarkTown_Lab_Text_ShowTogepi3": [
        "Toma, quiero que tengas esto como\\n",
        "muestra de mi agradecimiento.$"
    ],
    "NewBarkTown_Lab_Text_ElmGiveEverstone1": [
        "Es una PIEDRAETERNA.\\p",
        "Si un POKéMON la lleva equipada,\\n",
        "no evolucionará.$"
    ],
    "NewBarkTown_Lab_Text_ElmGiveEverstone2": [
        "ELM: ¡Sigue con tu viaje, {PLAYER}!\\n",
        "¡Confío en ti!$"
    ],
    "NewBarkTown_Lab_Text_ElmCallYou": [
        "ELM: ¡Te llamaré si descubro algo\\n",
        "más!$"
    ],
    "NewBarkTown_Lab_Text_AideAfterTheft": [
        "¡Fue horrible!\\n",
        "Entró un chico pelirrojo y se llevó\\l",
        "uno de los POKéMON.$"
    ],
    "NewBarkTown_Lab_Text_ElmGiveMasterBall1": [
        "ELM: ¡{PLAYER}! ¡Has ganado las 8\\n",
        "MEDALLAS de GIMNASIO de JOHTO!\\p",
        "¡Es un logro impresionante!\\p",
        "Toma esto, te será muy útil en\\n",
        "la LIGA POKéMON.$"
    ],
    "NewBarkTown_Lab_Text_ElmGiveMasterBall2": [
        "¡Es la MASTER BALL definitiva!\\n",
        "¡Atrapa a cualquier POKéMON sin fallar!$"
    ],
    "NewBarkTown_Lab_Text_KimonoGirls": [
        "ELM: Las CHICAS EN KIMONO te están\\n",
        "buscando en CIUDAD IRIS.$"
    ],
    "NewBarkTown_Lab_Text_KimonoWaiting": [
        "Parece que algo importante está a punto\\n",
        "de suceder en CIUDAD IRIS.$"
    ],
    "NewBarkTown_Lab_Text_League": [
        "ELM: ¡{PLAYER}! ¡Dirígete a la\\n",
        "MESETA AÑIL a través de la RUTA 27!\\p",
        "¡Demuestra todo lo que has aprendido!$"
    ],
    "NewBarkTown_Lab_Text_ElmGiveTicket1": [
        "ELM: ¡{PLAYER}! ¡Felicidades por\\n",
        "convertirte en CAMPEÓN!\\p",
        "Toma, un billete para el S.S. AQUA.$"
    ],
    "NewBarkTown_Lab_Text_ElmGiveTicket2": [
        "El barco zarpa desde el PUERTO de\\n",
        "CIUDAD OLIVO rumbo a KANTO.$"
    ],
    "NewBarkTown_Lab_Text_LabMonEgg": [
        "Es el HUEVO POKéMON que investiga\\n",
        "el PROF. ELM.$"
    ],
    "NewBarkTown_Lab_Text_AideGivePotion": [
        "¡{PLAYER}! ¡Espera un segundo!\\p",
        "El PROF. ELM me pidió que te diera esto\\n",
        "para ayudarte en tu camino.$"
    ],
    "NewBarkTown_Lab_Text_AideAlwaysBusy": [
        "El PROF. ELM siempre está ocupado\\n",
        "con sus investigaciones.$"
    ],
    "NewBarkTown_Lab_Text_AideSave": [
        "No olvides guardar la partida a menudo\\n",
        "desde el menú GUARDAR.$"
    ],
    "NewBarkTown_Lab_Text_AideTheftTestimony": [
        "¡Había alguien sospechoso merodeando\\n",
        "por la ventana antes del robo!$"
    ],
    "NewBarkTown_Lab_Text_AideGiveBalls": [
        "¡{PLAYER}! El PROF. ELM te manda esto.$"
    ],
    "NewBarkTown_Lab_Text_AideExplainBalls": [
        "¡Son POKé BALLS! Úsalas para atrapar\\n",
        "POKéMON salvajes y formar tu equipo.$"
    ],
    "NewBarkTown_Lab_Text_Officer1": [
        "POLICÍA: ¡Alto ahí!\\p",
        "¡Alguien ha robado un POKéMON del\\n",
        "LABORATORIO!\\p",
        "¿Quién eres tú?\\p",
        "Espera... ¿Conoces al ladrón?$"
    ],
    "NewBarkTown_Lab_Text_Officer2_1": [
        "¿Dices que combatiste contra un chico\\n",
        "pelirrojo? ¿Cómo se llamaba?$"
    ],
    "NewBarkTown_Lab_Text_Officer2": [
        "POLICÍA: ¿Se llamaba {RIVAL}?\\n",
        "¡Entendido! ¡Iremos tras él!$"
    ],
    "NewBarkTown_Lab_Text_OfficerNo": [
        "POLICÍA: Si recuerdas algo, ven a\\n",
        "contárnoslo de inmediato.$"
    ],
    "NewBarkTown_Lab_Text_Elm_CallMe": [
        "ELM: ¡Llámame cuando quieras si\\n",
        "necesitas algo!$"
    ]
}

def apply_translations():
    filepath = 'data/maps/NewBarkTown_Lab_hns/scripts.inc'
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()

    count = 0
    for label, lines in translations.items():
        pattern = re.compile(rf'({label}:(?::)?\s*\n)((?:\s*\.string\s*"[^"]*"\s*\n)+)')
        replacement_body = "".join(f'\t.string "{l}"\n' for l in lines)
        def repl(match):
            nonlocal count
            count += 1
            return match.group(1) + replacement_body
        content = pattern.sub(repl, content)

    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"Successfully applied {count} translations in {filepath}")

if __name__ == '__main__':
    apply_translations()
