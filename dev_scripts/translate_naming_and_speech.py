import re

# 1. src/naming_screen.c
with open("src/naming_screen.c", "r", encoding="utf-8") as f:
    ns = f.read()

ns = ns.replace('COMPOUND_STRING("YOUR NAME?")', 'COMPOUND_STRING("¿CÓMO TE LLAMAS?")')
ns = ns.replace('COMPOUND_STRING("BOX NAME?")', 'COMPOUND_STRING("¿NOMBRE DE CAJA?")')
ns = ns.replace('COMPOUND_STRING("{STR_VAR_1}\'s nickname?")', 'COMPOUND_STRING("¿Mote para {STR_VAR_1}?")')
ns = ns.replace('_("RIVAL\'s NAME?")', '_("¿NOMBRE DEL RIVAL?")')
ns = ns.replace('_("{DPAD_NONE}MOVE  {A_BUTTON}OK  {B_BUTTON}BACK")', '_("{DPAD_NONE}MOVER  {A_BUTTON}OK  {B_BUTTON}ATRÁS")')

with open("src/naming_screen.c", "w", encoding="utf-8") as f:
    f.write(ns)
print("[OK] src/naming_screen.c updated")

# 2. src/oak_speech_hns.c
with open("src/oak_speech_hns.c", "r", encoding="utf-8") as f:
    osh = f.read()

old_disc = 'static const u8 sText_Disclaimer[] = _("What challenge are you\\nexpecting?\\p{COLOR RED}The following settings can be changed\\nfrom the PC once you start the game.\\lHowever, after starting the game, the\\lnuzlocke, randomizer, difficulty and\\lchallenge settings can only be made\\leasier, not harder.");'
new_disc = 'static const u8 sText_Disclaimer[] = _("¿Qué nivel de desafío\\nprefieres?\\p{COLOR RED}Los siguientes ajustes se pueden cambiar\\ndesde el PC al empezar el juego.\\lSin embargo, una vez empezada la partida,\\nlas opciones de Nuzlocke, randomizador\\ny dificultad solo se podrán hacer más\\nfáciles, nunca más difíciles.");'
osh = osh.replace(old_disc, new_disc)

with open("src/oak_speech_hns.c", "w", encoding="utf-8") as f:
    f.write(osh)
print("[OK] src/oak_speech_hns.c updated")

# 3. src/challenge_menu.c
with open("src/challenge_menu.c", "r", encoding="utf-8") as f:
    cm = f.read()

cm = cm.replace('_("{L_BUTTON}PREVIOUS")', '_("{L_BUTTON}ANTERIOR")')
cm = cm.replace('_("{R_BUTTON}NEXT")', '_("{R_BUTTON}SIGUIENTE")')
cm = cm.replace('_("{R_BUTTON}SAVE")', '_("{R_BUTTON}GUARDAR")')
cm = cm.replace('_("{B_BUTTON}CANCEL")', '_("{B_BUTTON}CANCELAR")')

with open("src/challenge_menu.c", "w", encoding="utf-8") as f:
    f.write(cm)
print("[OK] src/challenge_menu.c updated")

# 4. data/text/birch_speech.inc
birch = """gText_Birch_Welcome::
\t.string "¡Hola! ¡Perdona por hacerte esperar!\\p"
\t.string "¡Te doy la bienvenida al mundo de\\n"
\t.string "POKéMON!\\p"
\t.string "Me llamo ABEDUL.\\p"
\t.string "Pero todos me llaman el PROFESOR\\n"
\t.string "POKéMON.\\p"
\t.string "$"

gText_Birch_Pokemon::
\t.string "Esto es lo que llamamos un “POKéMON”.\\p"
\t.string "\\n"
\t.string "$"

gText_Birch_MainSpeech::
\t.string "El mundo está habitado por criaturas\\n"
\t.string "llamadas POKéMON.\\p"
\t.string "Los humanos vivimos junto a los POKéMON,\\n"
\t.string "a veces como amigos y compañeros de juegos,\\l"
\t.string "y a veces cooperando en el trabajo.\\p"
\t.string "Y a veces nos unimos a ellos\\n"
\t.string "para combatir con otros entrenadores.\\p"
\t.string "Pero a pesar de nuestra cercanía,\\n"
\t.string "no lo sabemos todo sobre los POKéMON.\\p"
\t.string "De hecho, aún quedan muchísimos\\n"
\t.string "secretos por resolver.\\p"
\t.string "Para desentrañar los misterios POKéMON,\\n"
\t.string "me dedico a la investigación.\\l"
\t.string "Eso es lo que hago.\\p"
\t.string "$"

gText_Birch_AndYouAre::
\t.string "¿Y tú quién eres?$"

gText_Birch_BoyOrGirl::
\t.string "¿Eres un chico?\\n"
\t.string "¿O eres una chica?$"

gText_Birch_WhatsYourName::
\t.string "Muy bien.\\n"
\t.string "¿Cómo te llamas?$"

gText_Birch_SoItsPlayer::
\t.string "¿Te llamas {PLAYER}{KUN}?$"

gText_Birch_YourePlayer::
\t.string "¡Ah, de acuerdo!\\p"
\t.string "¡Tú eres {PLAYER}{KUN}, que te mudas a mi\\n"
\t.string "pueblo natal, VILLA RAÍZ!\\l"
\t.string "¡Ya lo entiendo todo!\\p"
\t.string "$"

gText_Birch_AreYouReady::
\t.string "Muy bien, ¿estás a punto?\\p"
\t.string "¡Tu propia aventura está a punto\\n"
\t.string "de comenzar!\\p"
\t.string "¡Ármate de valor y adéntrate en el\\n"
\t.string "mundo de los POKéMON, donde te esperan\\l"
\t.string "sueños, aventuras y amistades!\\p"
\t.string "Bueno, te estaré esperando luego.\\n"
\t.string "Pásate por mi LABORATORIO POKéMON.\\p"
\t.string "$"
"""
with open("data/text/birch_speech.inc", "w", encoding="utf-8") as f:
    f.write(birch)
print("[OK] data/text/birch_speech.inc updated")
