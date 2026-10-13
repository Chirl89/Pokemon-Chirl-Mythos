NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "¡Hola, {PLAYER}! Mi marido siempre\n"
	.string "está tan ocupado... Espero que esté bien.\p"
	.string "Cuando se enfrasca en sus investigaciones\n"
	.string "POKéMON, se le olvida hasta comer.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "¡Cuando sea mayor, ayudaré a mi papá!\p"
	.string "¡Voy a ser un profesor POKéMON\n"
	.string "famoso!$"
