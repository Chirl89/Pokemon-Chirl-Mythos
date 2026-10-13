CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "¿Quieres poner a prueba tu destreza\n"
	.string "como entrenador POKéMON?\p"
	.string "Lo mejor será que visites los GIMNASIOS\n"
	.string "POKéMON de todo JOHTO y reúnas\l"
	.string "MEDALLAS.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "¡De mayor voy a ser LÍDER DE\n"
	.string "GIMNASIO!\p"
	.string "¡Hago que mis POKéMON luchen contra los\n"
	.string "de mis amigos para volverlos más\l"
	.string "fuertes!$"
