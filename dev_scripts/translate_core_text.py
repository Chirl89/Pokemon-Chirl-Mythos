import os

def update_file(path, content):
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"[OK] Updated {path}")

# 1. oak_speech_hns.inc
oak_speech = """gText_Oak_Welcome::
\t.string "¡Hola! ¡Perdona por hacerte esperar!\\p"
\t.string "¡Te doy la bienvenida al mundo de\\n"
\t.string "POKéMON!\\p"
\t.string "Me llamo OAK.\\p"
\t.string "Pero la gente me llama el PROFESOR\\n"
\t.string "POKéMON.\\p"
\t.string "$"

gText_Oak_Pokemon::
\t.string "Esto es lo que llamamos un “POKéMON”.\\p"
\t.string "\\n"
\t.string "$"

gText_Oak_MainSpeech::
\t.string "El mundo está habitado por criaturas\\n"
\t.string "llamadas POKéMON.\\p"
\t.string "Para algunos, los POKéMON son\\n"
\t.string "mascotas. Pero otros los usan\\l"
\t.string "para combatir.\\p"
\t.string "En cuanto a mí…\\p"
\t.string "Yo me dedico a investigar a los\\n"
\t.string "POKéMON como profesión.\\p"
\t.string "$"

gText_Oak_AndYouAre::
\t.string "¿Y tú quién eres?$"

gText_Oak_BoyOrGirl::
\t.string "¿Eres un chico?\\n"
\t.string "¿O eres una chica?$"

gText_Oak_WhatChallenge::
\t.string "¿Qué nivel de desafío\\n"
\t.string "prefieres?$"

gText_Oak_ChallengeSelected::
\t.string "¡Me parece el nivel de desafío\\n"
\t.string "adecuado para ti!$" 

gText_Oak_WhatsYourName::
\t.string "¿Y cómo te llamas?$"

gText_Oak_SoItsPlayer::
\t.string "¿Te llamas {PLAYER}{KUN}?$"

gText_Oak_YourePlayer::
\t.string "{PLAYER}{KUN}, ¿estás a punto?\\p"
\t.string "¡Tu propia aventura está a punto\\n"
\t.string "de comenzar!\\p"
\t.string "$"

gText_Oak_AreYouReady::
\t.string "Te esperan momentos de diversión y\\n"
\t.string "grandes desafíos.\\p"
\t.string "¡Un mundo de sueños y aventuras te\\n"
\t.string "espera junto a los POKéMON! ¡Vamos!\\p"
\t.string "¡Nos vemos luego!\\p"
\t.string "$"
"""
update_file("data/text/oak_speech_hns.inc", oak_speech)

# 2. pkmn_center_nurse.inc
nurse = """gText_WouldYouLikeToRestYourPkmn::
\t.string "¡Hola! Te doy la bienvenida al\\n"
\t.string "CENTRO POKéMON.\\p"
\t.string "Nosotros curamos a tus POKéMON y\\n"
\t.string "les devolvemos toda su energía.\\p"
\t.string "¿Quieres que nos ocupemos de ellos?$"

gText_IllTakeYourPkmn::
\t.string "Muy bien. Déjame tus POKéMON\\n"
\t.string "unos instantes.$"

gText_RestoredPkmnToFullHealth::
\t.string "Gracias por esperar.\\p"
\t.string "Tus POKéMON están en forma y\\n"
\t.string "rebosan vitalidad.$"

gText_WeHopeToSeeYouAgain::
\t.string "¡Vuelve cuando quieras!$"

gText_WelcomeCutShort::
\t.string "¡Hola! Te doy la bienvenida al\\n"
\t.string "CENTRO POKéMON.\\p"
\t.string "Nosotros curamos a tus POKéMON y\\n"
\t.string "les devolvemos toda su energía.\\p"
\t.string "¿Quieres que…$"

gText_NoticesGoldCard::
\t.string "E-esa tarjeta…\\n"
\t.string "¿Podría ser… ¡¿la FICHA DE ORO?!\\p"
\t.string "¡Oh, ese brillo dorado es genial!\\n"
\t.string "¡Sus cuatro estrellas relucen!\\p"
\t.string "He visto a varios ENTRENADORES con\\n"
\t.string "la FICHA DE PLATA, ¡pero tú eres\\l"
\t.string "la primera persona que veo con\\l"
\t.string "una FICHA DE ORO, {PLAYER}!\\p"
\t.string "¡Por favor, déjame tener el honor\\n"
\t.string "de cuidar a tus POKéMON!$"

gText_YouWantTheUsual::
\t.string "¡Me alegro de verte, {PLAYER}!\\n"
\t.string "¿Lo de siempre, verdad?$"

gText_IllTakeYourPkmn2::
\t.string "Muy bien. Déjame tus POKéMON\\n"
\t.string "unos instantes.$"

gText_ThankYouForWaiting::
\t.string "Gracias por esperar.$"

gText_WeHopeToSeeYouAgain2::
\t.string "¡Vuelve cuando quieras!$"

gText_PkmnCenterChallenge_NoVisitsLeft:: @ tx_difficulty_challenge
    .string "¡Lo siento, pero estás jugando con\\n"
    .string "el desafío de CENTRO POKéMON!\\p"
    .string "¡Buena suerte!{PAUSE_UNTIL_PRESS}$"
"""
update_file("data/text/pkmn_center_nurse.inc", nurse)

# 3. mart_clerk.inc
mart = """gText_HowMayIServeYou::
\t.string "¡Hola!\\p"
\t.string "¿En qué puedo ayudarte?$"

gText_PleaseComeAgain::
\t.string "¡Vuelve cuando quieras!$"

gText_PlayerWhatCanIDoForYou::
\t.string "¡Hola, {PLAYER}{STRING 5}!\\p"
\t.string "¿En qué puedo ayudarte?$"
"""
update_file("data/text/mart_clerk.inc", mart)

# 4. surf.inc
surf = """gText_WantToUseSurf::
\t.string "El agua tiene un color azul intenso…\\n"
\t.string "¿Quieres hacer SURF?$"

gText_PlayerUsedSurf::
\t.string "¡{STR_VAR_1} usó SURF!$"

Text_CurrentTooFast::
\t.string "¡La corriente es muy rápida!\\n"
\t.string "No se puede hacer SURF aquí…$"
"""
update_file("data/text/surf.inc", surf)

# 5. obtain_item.inc
obtain = """gText_ObtainedTheItem::
\t.string "¡Obtuviste {STR_VAR_2}!$"

gText_TheBagIsFull::
\t.string "La MOCHILA está llena…$"

gText_PutItemInPocket::
\t.string "{PLAYER} guardó {STR_VAR_2}\\n"
\t.string "en el bolsillo {STR_VAR_3}.$"

gText_PlayerFoundOneItem::
\t.string "¡{PLAYER} encontró {STR_VAR_2}!$"

gText_TooBadBagIsFull::
\t.string "¡Qué pena!\\n"
\t.string "La MOCHILA está llena…$"

gText_PlayerPutItemInBag::
\t.string "{PLAYER} guardó {STR_VAR_2}\\n"
\t.string "en la MOCHILA.$"

gText_ObtainedTheDecor::
\t.string "¡Obtuviste {STR_VAR_2}!$"

gText_NoRoomLeftForAnother::
\t.string "¡Qué pena! No queda espacio para\\n"
\t.string "otro {STR_VAR_2}…$"

gText_TheDecorWasTransferredToThePC::
\t.string "{STR_VAR_2} se envió\\n"
\t.string "al PC.$"

gText_ObtainedTheItems::
\t.string "¡Obtuviste {STR_VAR_1} {STR_VAR_2}!$"

gText_PlayerFoundItems::
\t.string "¡{PLAYER} encontró {STR_VAR_1} {STR_VAR_2}!$"

gText_PutCoinsAwayInCoinCase::
\t.string "{PLAYER} guardó las FICHAS en\\n"
\t.string "el MONEDERO.$"

gText_FoundXCoins::
\t.string "¡{PLAYER} encontró\\n"
\t.string "{STR_VAR_1} {STR_VAR_2}!$"

gText_FoundXItems::
\t.string "¡{PLAYER} encontró\\n"
\t.string "{STR_VAR_1} {STR_VAR_2}!$"

gText_CoinCaseIsFull::
\t.string "¡Qué pena!\\n"
\t.string "El MONEDERO está lleno…$"

gText_NothingToPutThemIn::
\t.string "¡Qué pena!\\n"
\t.string "No tienes dónde guardarlas…$"
"""
update_file("data/text/obtain_item.inc", obtain)

# 6. save.inc
save_txt = """\t.align 2
gText_ConfirmSave::
\t.string "¿Quieres guardar la partida?$"

gText_AlreadySavedFile::
\t.string "Ya hay una partida guardada.\\n"
\t.string "¿Quieres sobrescribirla?$"

gText_SavingDontTurnOff::
\t.string "GUARDANDO…\\n"
\t.string "NO APAGUES LA CONSOLA.$"

gText_PlayerSavedGame::
\t.string "{PLAYER} guardó la partida.$"

gText_DifferentSaveFile::
\t.string "¡ATENCIÓN!\\p"
\t.string "Ya hay una partida guardada diferente.\\p"
\t.string "Si guardas ahora, los datos de la otra\\n"
\t.string "partida, incluidos objetos y POKéMON,\\l"
\t.string "se perderán para siempre.\\p"
\t.string "¿Seguro que quieres guardar ahora y\\n"
\t.string "sobrescribir los datos guardados?$"

gText_SaveError::
\t.string "Error al guardar.\\p"
\t.string "Por favor, cambia la memoria\\n"
\t.string "de seguridad.$"

gText_SavingDontTurnOffPower::
\t.string "GUARDANDO…\\n"
\t.string "NO APAGUES LA CONSOLA.$"
"""
update_file("data/text/save.inc", save_txt)
