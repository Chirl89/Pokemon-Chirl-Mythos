Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "No puedes subir por los desniveles.\p"
	.string "Pero puedes saltar hacia abajo para\n"
	.string "tomar un atajo.$"

Gate_Route29_Route46_Text_Youngster:
	.string "A partir de aquí aparecen distintas\n"
	.string "clases de POKéMON.\p"
	.string "Si quieres atraparlos a todos, tendrás\n"
	.string "que buscar por todas partes.$"
