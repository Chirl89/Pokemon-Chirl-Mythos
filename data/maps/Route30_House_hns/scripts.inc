Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Si sigues ese camino hacia el norte,\n"
	.string "verás la casa del SR. POKéMON.\p"
	.string "Pero antes de irte, ¡déjame contarte\n"
	.string "algo sobre las BAYAS!\p"
	.string "Los POKéMON recuperan salud al comer\n"
	.string "BAYAS.\p"
	.string "Incluso pueden comerse las BAYAS que\n"
	.string "lleven equipadas durante el combate.\p"
	.string "Además, CÉSAR en PUEBLO AZALEA puede\n"
	.string "fabricar BALLS con las BAYAS.\p"
	.string "¡Toma, comparte esta conmigo!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Busca BAYAS en los árboles.\n"
	.string "Vuelven a crecer pasadas unas horas.$"
